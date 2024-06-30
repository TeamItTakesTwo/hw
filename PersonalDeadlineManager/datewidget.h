#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include "mycase.h"


namespace Ui {
class dateWidget;
}

class CaseWidgetItem;
class dateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit dateWidget(QWidget *parent = nullptr, const QDate _date = QDate(), const QVector<MyCase*>& cases = QVector<MyCase*>());
    ~dateWidget();

private:
    Ui::dateWidget *ui;
    const QDate current_date;
    QListWidget *listWidget;
    QVBoxLayout *layout;
    QVector<MyCase*> allCases;
    QPushButton *addButton;
    QPushButton *closeButton;

    void populateCases();

private slots:
    void onAddButtonClicked();
    void onCloseButtonClicked();
    void addNewCase(const QDateTime& start_date, const QDateTime& end_date, const QString& description);
    void onDeleteButtonClicked(CaseWidgetItem *item); // Slot for delete button

signals:
    void casesUpdated(const QVector<MyCase*> newCases);
    void aboutToClose(const QVector<MyCase>& updatedCases);
    void closed();
};

class CaseWidgetItem : public QWidget
{
    Q_OBJECT

public:
    CaseWidgetItem(MyCase* myCase, QWidget *parent = nullptr);
    QString getDescription() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

signals:
    void deleteRequested(CaseWidgetItem* item);
    void clicked();
    void caseUpdated(QVector<MyCase*> cases);

private slots:
    void onDeleteButtonClicked();
    void onWidgetClicked();
    void onCaseUpdated(QVector<MyCase*> cases);

private:
    QLabel *descriptionLabel;
    QPushButton *deleteButton;
    MyCase* myCase;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // DATEWIDGET_H
