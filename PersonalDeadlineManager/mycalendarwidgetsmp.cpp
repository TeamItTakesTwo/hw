#include "mycalendarwidgetsmp.h"
#include <QTableView>
#include <QHeaderView>
#include <QPaintEvent>
#include <QDebug>
MyCalendarWidgetSmp::MyCalendarWidgetSmp(QWidget *parent)
    :QCalendarWidget(parent)
{
    this->setMinimumSize(800,600);
    emit signalCalendarPaint();
    if (parent) {
        setGeometry(
            (parent->width() - width()) / 2,
            (parent->height() - height()) / 2,
            width(),
            height()
            );
    }
}

MyCalendarWidgetSmp::~MyCalendarWidgetSmp()
{

}
void MyCalendarWidgetSmp::paintEvent(QPaintEvent *event)
{
    qDebug()<<"paint";
}

QRect MyCalendarWidgetSmp::getDateCellInfo(int row,int col)
{
    QWidget *navBar = this->findChild<QWidget*>("qt_calendar_navigationbar");
    int navBarHeight = navBar ? navBar->height() : 0;

    // Get the height of the weekday headers (typically the days of the week)
    QTableView *tableView = this->findChild<QTableView*>("qt_calendar_calendarview");
    int dayHeaderHeight = tableView ? tableView->horizontalHeader()->height() : 0;

    int headerHeight = navBarHeight + dayHeaderHeight;

    QSize calendarSize = this->size();

    int cellWidth = calendarSize.width() / 8;
    int cellHeight = (calendarSize.height() - headerHeight) / 7;

    return QRect((col+1) * cellWidth, headerHeight + row * cellHeight, cellWidth, cellHeight);
}
