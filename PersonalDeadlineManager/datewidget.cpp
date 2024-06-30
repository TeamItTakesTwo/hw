#include "datewidget.h"
#include "ui_datewidget.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>

CaseWidgetItem::CaseWidgetItem( MyCase* myCase, QWidget *parent)
    : QWidget(parent), myCase(myCase)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    descriptionLabel = new QLabel(QString("描述: %1\n开始时间: %2\n结束时间: %3")
                                      .arg(myCase->getDescription())
                                      .arg(myCase->getStartDateTime().toString(Qt::ISODate))
                                      .arg(myCase->getEndDateTime().toString(Qt::ISODate)), this);
    deleteButton = new QPushButton("删除", this);

    layout->addWidget(descriptionLabel);
    layout->addWidget(deleteButton);

    connect(deleteButton, &QPushButton::clicked, this, &CaseWidgetItem::onDeleteButtonClicked);
    connect(this, &CaseWidgetItem::clicked, this, &CaseWidgetItem::onWidgetClicked);
}

QString CaseWidgetItem::getDescription() const
{
    return myCase->getDescription();
}

QDate CaseWidgetItem::getStartDate() const
{
    return myCase->getStartDate();
}

QDate CaseWidgetItem::getEndDate() const
{
    return myCase->getEndDate();
}

void CaseWidgetItem::onDeleteButtonClicked()
{
    emit deleteRequested(this);
}

void CaseWidgetItem::onCaseUpdated(QVector<MyCase*> cases) {
    emit caseUpdated(cases);
}

void CaseWidgetItem::onWidgetClicked() {
    // 打开文件以获取所有的案例
    QVector<MyCase*> allCases = MyCase::readCasesFromFile("cases.txt");

    // 找到当前 CaseWidgetItem 对应的 MyCase 对象在 allCases 中的索引
    int index = -1;
    for (int i = 0; i < allCases.size(); ++i) {
        MyCase *case_ptr = allCases[i];
        if (case_ptr->getStartDate() == myCase->getStartDate() &&
            case_ptr->getEndDate() == myCase->getEndDate() &&
            case_ptr->getDescription() == myCase->getDescription()) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        qDebug() << "Error: Cannot find matching case in allCases.";
        return;
    }

    // 创建编辑对话框
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Case");

    QVBoxLayout layout(&dialog);

    QLabel *startLabel = new QLabel("Start Time:", &dialog);
    QDateTimeEdit *startDateTimeEdit = new QDateTimeEdit(&dialog);
    startDateTimeEdit->setCalendarPopup(true);
    startDateTimeEdit->setDate(myCase->getStartDate());

    QLabel *endLabel = new QLabel("End Time:", &dialog);
    QDateTimeEdit *endDateTimeEdit = new QDateTimeEdit(&dialog);
    endDateTimeEdit->setCalendarPopup(true);
    endDateTimeEdit->setDate(myCase->getEndDate());

    QLabel *descLabel = new QLabel("Description:", &dialog);
    QLineEdit *descEdit = new QLineEdit(&dialog);
    descEdit->setText(myCase->getDescription());

    layout.addWidget(startLabel);
    layout.addWidget(startDateTimeEdit);
    layout.addWidget(endLabel);
    layout.addWidget(endDateTimeEdit);
    layout.addWidget(descLabel);
    layout.addWidget(descEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout.addWidget(&buttonBox);

    // 连接对话框按钮的信号与槽
    connect(&buttonBox, &QDialogButtonBox::accepted, [&]() {
        // 更新 MyCase 对象的数据
        myCase->setStartDate(startDateTimeEdit->dateTime());
        myCase->setEndDate(endDateTimeEdit->dateTime());
        myCase->setDescription(descEdit->text());

        allCases[index] = myCase;
        // 更新文件中的案例数据
        QFile file("cases.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (const MyCase *case_ptr : allCases) {
                out << case_ptr->getStartDate().toString(Qt::ISODate) << ","
                    << case_ptr->getEndDate().toString(Qt::ISODate) << ","
                    << case_ptr->getDescription() << "\n";
            }
            file.close();
        } else {
            qDebug() << "Failed to open cases.txt for writing.";
        }

        onCaseUpdated(allCases);
        // 关闭对话框
        dialog.accept();
    });

    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // 显示对话框
    dialog.exec();
}

void CaseWidgetItem::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
    QWidget::mousePressEvent(event);
}

dateWidget::dateWidget(QWidget *parent, const QDate _date, const QVector<MyCase*>& cases)
    : QWidget(parent)
    , ui(new Ui::dateWidget)
    , current_date(_date)
    , listWidget(nullptr)
    , layout(nullptr)
    , allCases(cases)
    , addButton(nullptr)
    , closeButton(nullptr)
{
    ui->setupUi(this);

    // 设置布局
    layout = new QVBoxLayout(this);
    listWidget = new QListWidget(this);
    layout->addWidget(listWidget);

    addButton = new QPushButton("Add Case", this);
    layout->addWidget(addButton, 0, Qt::AlignRight | Qt::AlignBottom);

    closeButton = new QPushButton("Close", this);
    layout->addWidget(closeButton, 0, Qt::AlignRight | Qt::AlignBottom);

    // 设置窗口标题
    setWindowTitle(QString("Date: %1").arg(current_date.toString(Qt::ISODate)));

    connect(addButton, &QPushButton::clicked, this, &dateWidget::onAddButtonClicked);
    connect(closeButton, &QPushButton::clicked, this, &dateWidget::onCloseButtonClicked);

    // 填充列表
    populateCases();

    if (parent) {
        setGeometry(
            (parent->width() - width()) / 2,
            (parent->height() - height()) / 2,
            width(),
            height()
            );
    }
}

dateWidget::~dateWidget()
{
    delete ui;
}

void dateWidget::populateCases() {
    listWidget->clear();
    for (MyCase* myCase : allCases) {
        if (myCase->getStartDate() <= current_date && myCase->getEndDate() >= current_date) {
            QListWidgetItem *item = new QListWidgetItem(listWidget);
            CaseWidgetItem *caseWidget = new CaseWidgetItem(myCase, listWidget);
            connect(caseWidget, &CaseWidgetItem::deleteRequested, this, &dateWidget::onDeleteButtonClicked);
            connect(caseWidget, &CaseWidgetItem::caseUpdated, [&](QVector<MyCase*> cases){
                emit casesUpdated(cases);
            });
            item->setSizeHint(caseWidget->sizeHint());
            listWidget->setItemWidget(item, caseWidget);
        }
    }
}


void dateWidget::onAddButtonClicked() {
    QDialog dialog(this);
    dialog.setWindowTitle("Add New Case");

    QVBoxLayout layout(&dialog);

    QLabel *startLabel = new QLabel("Start Date:", &dialog);
    QDateTimeEdit *startDateTimeEdit = new QDateTimeEdit(&dialog);
    startDateTimeEdit->setCalendarPopup(true);
    startDateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QLabel *endLabel = new QLabel("End Date:", &dialog);
    QDateTimeEdit *endDateTimeEdit = new QDateTimeEdit(&dialog);
    endDateTimeEdit->setCalendarPopup(true);
    endDateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QLabel *descLabel = new QLabel("Description:", &dialog);
    QLineEdit *descEdit = new QLineEdit(&dialog);

    layout.addWidget(startLabel);
    layout.addWidget(startDateTimeEdit);
    layout.addWidget(endLabel);
    layout.addWidget(endDateTimeEdit);
    layout.addWidget(descLabel);
    layout.addWidget(descEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout.addWidget(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted, [&]() {
        addNewCase(startDateTimeEdit->dateTime(), endDateTimeEdit->dateTime(), descEdit->text());
        dialog.accept();
    });
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    dialog.exec();
}

void dateWidget::addNewCase(const QDateTime& start_date, const QDateTime& end_date, const QString& description) {
    //MyCase newCase(start_date, end_date, description);
    //allCases.append(newCase);
    allCases.append(new MyCase(start_date, end_date, description));
    // Save to cases.txt
    QFile file("cases.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (auto myCase : allCases) {
            out << myCase->getStartDate().toString(Qt::ISODate) << ","
                << myCase->getEndDate().toString(Qt::ISODate) << ","
                << myCase->getDescription() << "\n";
        }
        file.close();
    }

    // Update the list
    populateCases();

    // Emit signal to notify MainPage to reload cases
    emit casesUpdated(allCases);
}

void dateWidget::onDeleteButtonClicked(CaseWidgetItem *item) {
    for (int i = 0; i < allCases.size(); ++i) {
        MyCase *myCase = allCases[i];
        if (myCase->getDescription() == item->getDescription() &&
            myCase->getStartDate() == item->getStartDate() &&
            myCase->getEndDate() == item->getEndDate()) {
            allCases.remove(i);
            break;
        }
    }

    // 保存到cases.txt
    QFile file("cases.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (MyCase *myCase : allCases) {
            out << myCase->getStartDate().toString(Qt::ISODate) << ","
                << myCase->getEndDate().toString(Qt::ISODate) << ","
                << myCase->getDescription() << "\n";
        }
        file.close();
    }

    // 更新列表
    populateCases();

    // 发射信号通知MainPage重新加载cases
    emit casesUpdated(allCases);
}

void dateWidget::onCloseButtonClicked()
{
    emit closed();
    deleteLater();
}
