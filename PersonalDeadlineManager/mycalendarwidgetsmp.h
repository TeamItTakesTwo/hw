#ifndef MYCALENDARWIDGETSMP_H
#define MYCALENDARWIDGETSMP_H


#include <QCalendarWidget>
class MyCalendarWidgetSmp:public QCalendarWidget
{
    Q_OBJECT

public:
    MyCalendarWidgetSmp(QWidget *parent=nullptr);
    QRect getDateCellInfo(int row,int col);
    ~MyCalendarWidgetSmp();
signals:
    void signalCalendarPaint();
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYCALENDARWIDGETSMP_H
