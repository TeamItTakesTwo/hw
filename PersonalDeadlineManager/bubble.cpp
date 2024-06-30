#include "bubble.h"
#include "ui_bubble.h"

Bubble::Bubble(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Bubble)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    connect(this,SIGNAL(mouseleftclicked()),this,SLOT(showMainPage()));
    connect(this,&Bubble::mouserightclicked,this,&QApplication::quit);
    mainpage=new MainPage();
}

Bubble::~Bubble()
{
    delete ui;
}

void Bubble::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(20,20,60,60);
}

void Bubble::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        leftPress=true;
        leftMove=false;
        DragPoint = event->pos();
    }
    if(event->button() == Qt::RightButton){
        rightPress=true;
        rightMove=false;
    }
}
void Bubble::mouseMoveEvent(QMouseEvent *event){
    if((leftPress||rightPress)&&(event->pos() - DragPoint).manhattanLength() > QApplication::startDragDistance())
    {
        leftMove=true;
        rightMove=true;
        DragPoint = event->pos();
    }

    move(mapToParent(event->pos() - DragPoint));
}
void Bubble::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(leftMove)
        {
            emit mouseleftdraged();

        }
        else
        {
            emit mouseleftclicked();
        }
    }
    if(event->button() == Qt::RightButton){
        if(rightMove)
        {
        }
        else
        {
            emit mouserightclicked();
        }
    }
}
void Bubble::showMainPage(){
    qDebug()<<tr("openmainpage");
    mainpage->show();
}
