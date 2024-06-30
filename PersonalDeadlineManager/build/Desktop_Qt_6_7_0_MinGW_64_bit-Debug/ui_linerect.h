/********************************************************************************
** Form generated from reading UI file 'linerect.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINERECT_H
#define UI_LINERECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineRect
{
public:

    void setupUi(QWidget *LineRect)
    {
        if (LineRect->objectName().isEmpty())
            LineRect->setObjectName("LineRect");
        LineRect->resize(400, 300);

        retranslateUi(LineRect);

        QMetaObject::connectSlotsByName(LineRect);
    } // setupUi

    void retranslateUi(QWidget *LineRect)
    {
        LineRect->setWindowTitle(QCoreApplication::translate("LineRect", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineRect: public Ui_LineRect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINERECT_H
