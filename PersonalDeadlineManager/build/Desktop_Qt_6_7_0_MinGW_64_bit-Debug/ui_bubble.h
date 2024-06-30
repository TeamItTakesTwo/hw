/********************************************************************************
** Form generated from reading UI file 'bubble.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUBBLE_H
#define UI_BUBBLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bubble
{
public:

    void setupUi(QWidget *Bubble)
    {
        if (Bubble->objectName().isEmpty())
            Bubble->setObjectName("Bubble");
        Bubble->resize(800, 600);

        retranslateUi(Bubble);

        QMetaObject::connectSlotsByName(Bubble);
    } // setupUi

    void retranslateUi(QWidget *Bubble)
    {
        Bubble->setWindowTitle(QCoreApplication::translate("Bubble", "Bubble", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bubble: public Ui_Bubble {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUBBLE_H
