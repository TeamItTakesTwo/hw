#include "mytimer.h"

MyTimer::MyTimer(QVector <MyCase*>* casesptr,QObject *parent ):QObject(parent),timerPtr(),casesPtr(casesptr)
{
    resetTimer();
}

void MyTimer::resetTimer()
{
    for(auto ptr:timerPtr){
        delete ptr;
    }
    timerPtr.clear();
    //for(auto ptr:casesPtr){
    for(int i=0;i<casesPtr->size();i++){
        onceTimer* qtimer=new onceTimer();
        QDateTime currentdatetime=QDateTime::currentDateTime();
        qint64 sep=(*casesPtr)[i]->getEndDateTime().msecsTo(currentdatetime);
        qtimer->start(sep);
        timerPtr.append(qtimer);
        connect(qtimer, &QTimer::timeout, this, [this,i]() { casedone(i,1); });
        qDebug()<<"timer to "<<(*casesPtr)[i]->getEndDateTime()<<"load";

        onceTimer* qtimer2=new onceTimer();
        qint64 sep2=(*casesPtr)[i]->getStartDateTime().msecsTo(currentdatetime);
        qtimer->start(sep2);
        timerPtr.append(qtimer2);
        connect(qtimer2, &QTimer::timeout, this, [this,i]() { casedone(i,0); });
        qDebug()<<"timer to "<<(*casesPtr)[i]->getEndDateTime()<<"load";
    }
}
onceTimer::onceTimer():QTimer(){
    connect(this,&QTimer::timeout,this,&onceTimer::ontimeout);
}

void onceTimer::ontimeout(){
    this->stop();
}

