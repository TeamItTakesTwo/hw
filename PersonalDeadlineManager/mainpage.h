#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "mycalendarwidgetsmp.h"
#include "mycase.h"
#include "datewidget.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QTextCharFormat>
#include <QMessageBox>
#include <QVector>
#include <QTimer>
#include <QPixmap>
#include "linerect.h"
#include "mytimer.h"
namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui;
    MyCalendarWidgetSmp *calendar;
    QVector<LineRect *> linerect;
    QVector <MyCase*> cases;
    dateWidget* dateWidget_ptr;
    MyTimer *mytimer;
    QPixmap background;
    //void initCases();
private slots:
    void onDateClicked(const QDate& date);
    void updateCases(QVector<MyCase*> newCases);
    void onDateWidgetClosed();
    void drawCases();
    void onTimeOut(int idx,bool begorend);


protected:
    void closeEvent(QCloseEvent *event)override;
    void paintEvent(QPaintEvent *event)override;
    //void mousePressEvent(QMouseEvent *event)override;
};


#endif // MAINPAGE_H
