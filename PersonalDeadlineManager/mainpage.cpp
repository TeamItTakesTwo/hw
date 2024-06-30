#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
    , dateWidget_ptr(nullptr)
    , background(":/calendar_background.jpg")
{
    ui->setupUi(this);
    setFixedSize(1000, 800);
    cases = MyCase::readCasesFromFile("cases.txt");
    calendar = new MyCalendarWidgetSmp(this);
    mytimer=new MyTimer(&cases,this);
    connect(calendar, &MyCalendarWidgetSmp::clicked, this, &MainPage::onDateClicked);
    connect(calendar,&MyCalendarWidgetSmp::currentPageChanged,this,&MainPage::drawCases);
    connect(mytimer,&MyTimer::casedone,this,&MainPage::onTimeOut);
    drawCases();
}

MainPage::~MainPage()
{
    delete ui;    delete calendar;
    if (dateWidget_ptr) {
        delete dateWidget_ptr;
    }
}

void MainPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // 绘制背景图片
    if (!background.isNull()) {
        painter.drawPixmap(this->rect(), background);
    }
    else
        qDebug() << "pix not found";

    // 调用基类的 paintEvent 以确保日历组件的正常绘制
    QWidget::paintEvent(event);

    qDebug() << "paint";
}

void MainPage::onDateClicked(const QDate& date)
{

    if (dateWidget_ptr == nullptr) {
        dateWidget_ptr = new dateWidget(nullptr, date, cases);  // Pass the cases to dateWidget

        // Connect the casesUpdated signal from dateWidget to MainPage's updateCases slot
        connect(dateWidget_ptr, &dateWidget::casesUpdated, this, &MainPage::updateCases);

        // Connect the close signal from dateWidget to MainPage's slot
        connect(dateWidget_ptr, &dateWidget::closed, this, &MainPage::onDateWidgetClosed);
    } else {
        dateWidget_ptr = nullptr;
        dateWidget_ptr = new dateWidget(nullptr, date, cases);  // Pass the cases to dateWidget

        // Connect the casesUpdated signal from dateWidget to MainPage's updateCases slot
        connect(dateWidget_ptr, &dateWidget::casesUpdated, this, &MainPage::updateCases);

        // Connect the close signal from dateWidget to MainPage's slot
        connect(dateWidget_ptr, &dateWidget::closed, this, &MainPage::onDateWidgetClosed);
    }
    connect(dateWidget_ptr,&dateWidget::casesUpdated,this,&MainPage::drawCases);
    connect(dateWidget_ptr,&dateWidget::casesUpdated,this->mytimer,&MyTimer::resetTimer);
    dateWidget_ptr->show();
}

void MainPage::drawCases()
{
    for (auto i :linerect){
        delete i;
    }
    linerect.clear();
    static bool updating = false;
    if (updating) return;
    updating = true;

    //qDebug()<<tr("drawcases");
    int year = calendar->yearShown();
    int month = calendar->monthShown();

    QDate firstDate(year, month, 1);
    int dayOfWeek = firstDate.dayOfWeek();
    //qDebug()<<"dayofweek"<<dayOfWeek;
    firstDate = firstDate.addDays(-(dayOfWeek-1 ? dayOfWeek-1:7)); // Move to the start of the week

    //qDebug()<<"firstdate:"<<firstDate;
    QDate lastDate = firstDate.addDays(6 * 7 - 1);
    for (auto i:cases)
    {

        for(QDate tmp=i->getStartDate();tmp!=i->getEndDate().addDays(1);tmp=tmp.addDays(1))
        {

            if(tmp>lastDate) break;
            if(tmp<firstDate) continue;
            //qDebug()<<i->getDescription()<<":"<<tmp;
            int row=firstDate.daysTo(tmp)/7;
            int column=firstDate.daysTo(tmp)%7;
            //qDebug()<<row<<column;
            QRect rect=calendar->getDateCellInfo(row,column);
            //qDebug()<<rect;
            QTimer::singleShot(0, [=]() {
                linerect.push_back(new LineRect(90, 10, rect.bottomLeft().x(), rect.bottomLeft().y(), calendar));
                linerect.back()->show();
            });
        }
    }
    updating = false;
    //calendar->setUpdatesEnabled(false);
}



void MainPage::updateCases(QVector<MyCase*> newCases) {
    cases = newCases;
}

void MainPage::onDateWidgetClosed()
{
    if (dateWidget_ptr) {
        // Disconnect the signals to prevent further interactions
        disconnect(dateWidget_ptr, &dateWidget::casesUpdated, this, &MainPage::updateCases);
        disconnect(dateWidget_ptr, &dateWidget::closed, this, &MainPage::onDateWidgetClosed);
        disconnect(dateWidget_ptr,&dateWidget::casesUpdated,this,&MainPage::drawCases);
        // Delete the dateWidget_ptr object
        dateWidget_ptr->deleteLater();
        dateWidget_ptr = nullptr;
    }
}

void MainPage::onTimeOut(int idx,bool begorend)
{
    QMessageBox msgBox;
    if(!begorend){
        msgBox.setText("A deadline just start! \nfrom:"+cases[idx]->getStartDateTime().toString()+"\nto"
                       +cases[idx]->getEndDateTime().toString()+"\n"+cases[idx]->getDescription());
    }else{
        msgBox.setText("A deadline just end! \nfrom:"+cases[idx]->getStartDateTime().toString()+"\nto"
                       +cases[idx]->getEndDateTime().toString()+"\n"+cases[idx]->getDescription());
    }
    msgBox.exec();
}

void MainPage::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}
