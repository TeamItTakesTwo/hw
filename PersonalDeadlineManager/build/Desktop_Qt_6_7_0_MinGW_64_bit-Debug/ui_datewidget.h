/********************************************************************************
** Form generated from reading UI file 'datewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEWIDGET_H
#define UI_DATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dateWidget
{
public:

    void setupUi(QWidget *dateWidget)
    {
        if (dateWidget->objectName().isEmpty())
            dateWidget->setObjectName("dateWidget");
        dateWidget->resize(400, 300);

        retranslateUi(dateWidget);

        QMetaObject::connectSlotsByName(dateWidget);
    } // setupUi

    void retranslateUi(QWidget *dateWidget)
    {
        dateWidget->setWindowTitle(QCoreApplication::translate("dateWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dateWidget: public Ui_dateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEWIDGET_H
