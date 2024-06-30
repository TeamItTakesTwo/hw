#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include "mycase.h"
#include <QVector>
#include <QDebug>
class onceTimer;
class MyTimer: public QObject
{
    Q_OBJECT
public:
    MyTimer(QVector <MyCase*>*,QObject *parent = nullptr);
public:
    QVector<onceTimer*> timerPtr;
    QVector <MyCase*>* casesPtr;
signals:
    void casedone(int caseidx,bool begorend);
public slots:
    void resetTimer();

};
class onceTimer:public QTimer{
    Q_OBJECT
public:
    onceTimer();
public slots:
    void ontimeout();
};

#endif // MYTIMER_H
