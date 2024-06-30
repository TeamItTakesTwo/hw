#ifndef LINERECT_H
#define LINERECT_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

namespace Ui {
class LineRect;
}

class LineRect : public QWidget
{
    Q_OBJECT

public:
    explicit LineRect(int width,int height,int x,int y,QWidget *parent = nullptr);
    ~LineRect();

private:
    Ui::LineRect *ui;
    int m_width;
    int m_height;
    int m_x;
    int m_y;
protected:
    void paintEvent(QPaintEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;

};

#endif // LINERECT_H
