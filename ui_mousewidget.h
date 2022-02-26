/********************************************************************************
** Form generated from reading UI file 'mousewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEWIDGET_H
#define UI_MOUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseWidget
{
public:
    QWidget *dockWidgetContents;

    void setupUi(QDockWidget *MouseWidget)
    {
        if (MouseWidget->objectName().isEmpty())
            MouseWidget->setObjectName(QString::fromUtf8("MouseWidget"));
        MouseWidget->resize(100, 100);
        MouseWidget->setWindowOpacity(0.500000000000000);
        MouseWidget->setStyleSheet(QString::fromUtf8(""));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        MouseWidget->setWidget(dockWidgetContents);

        retranslateUi(MouseWidget);

        QMetaObject::connectSlotsByName(MouseWidget);
    } // setupUi

    void retranslateUi(QDockWidget *MouseWidget)
    {
        MouseWidget->setWindowTitle(QApplication::translate("MouseWidget", "DockWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MouseWidget: public Ui_MouseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEWIDGET_H
