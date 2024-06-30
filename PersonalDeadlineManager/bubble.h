#ifndef BUBBLE_H
#define BUBBLE_H

#include"mainpage.h"
#include <QWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Bubble; }
QT_END_NAMESPACE

class Bubble : public QWidget
{
    Q_OBJECT

public:
    Bubble(QWidget *parent = nullptr);
    ~Bubble();

signals:
    void mouserightclicked();
    void mouseleftclicked();
    void mouseleftdraged();

public slots:
    void showMainPage();

private:
    Ui::Bubble *ui;
    QPoint DragPoint;
    MainPage *mainpage;

protected:
    void paintEvent(QPaintEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    bool leftPress=false,leftMove=false,rightPress=false,rightMove=false;
};
#endif // BUBBLE_H
