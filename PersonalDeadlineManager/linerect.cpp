#include "linerect.h"
#include "ui_linerect.h"

LineRect::LineRect(int width,int height,int x,int y,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LineRect),m_width(width),m_height(height),m_x(x),m_y(y)
{
    ui->setupUi(this);
    setGeometry(x,y,width,height);
}

LineRect::~LineRect()
{
    delete ui;
}

void LineRect::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //QRect clipRect(0, 0, 800, 600);
    //painter.setClipRect(clipRect);

    painter.setBrush(Qt::blue);
    painter.drawRect(0, 0, m_width, m_height);
    //qDebug()<<"drawline";
}

void LineRect::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QMessageBox::information(this, "Mouse Clicked", "Mouse clicked on rectangle");
    }
}
