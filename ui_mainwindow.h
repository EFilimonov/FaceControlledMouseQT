/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "aspectratiolabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *videoContainerLayout;
    AspectRatioLabel *inVideo;
    QHBoxLayout *horizontalButtonsLayout;
    QPushButton *stopButton;
    QPushButton *geoSmileButton;
    QPushButton *aiSmileButton;
    QPushButton *dwellButton;
    QPushButton *click1Button;
    QPushButton *click2Button;
    QPushButton *clickRButton;
    QPushButton *clickDButton;
    QPushButton *optionsButton;
    QPushButton *appButton;
    QPushButton *hideButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(861, 553);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/res/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        videoContainerLayout = new QVBoxLayout();
        videoContainerLayout->setObjectName(QString::fromUtf8("videoContainerLayout"));
        inVideo = new AspectRatioLabel(centralwidget);
        inVideo->setObjectName(QString::fromUtf8("inVideo"));
        QFont font;
        font.setPointSize(10);
        inVideo->setFont(font);
        inVideo->setStyleSheet(QString::fromUtf8(""));
        inVideo->setAlignment(Qt::AlignCenter);

        videoContainerLayout->addWidget(inVideo);


        verticalLayout_2->addLayout(videoContainerLayout);

        horizontalButtonsLayout = new QHBoxLayout();
        horizontalButtonsLayout->setSpacing(0);
        horizontalButtonsLayout->setObjectName(QString::fromUtf8("horizontalButtonsLayout"));
        horizontalButtonsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(stopButton);

        geoSmileButton = new QPushButton(centralwidget);
        geoSmileButton->setObjectName(QString::fromUtf8("geoSmileButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/res/GEO.png"), QSize(), QIcon::Normal, QIcon::Off);
        geoSmileButton->setIcon(icon2);
        geoSmileButton->setIconSize(QSize(50, 50));
        geoSmileButton->setFlat(false);

        horizontalButtonsLayout->addWidget(geoSmileButton);

        aiSmileButton = new QPushButton(centralwidget);
        aiSmileButton->setObjectName(QString::fromUtf8("aiSmileButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/res/AI.png"), QSize(), QIcon::Normal, QIcon::Off);
        aiSmileButton->setIcon(icon3);
        aiSmileButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(aiSmileButton);

        dwellButton = new QPushButton(centralwidget);
        dwellButton->setObjectName(QString::fromUtf8("dwellButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/res/dwell.png"), QSize(), QIcon::Normal, QIcon::Off);
        dwellButton->setIcon(icon4);
        dwellButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(dwellButton);

        click1Button = new QPushButton(centralwidget);
        click1Button->setObjectName(QString::fromUtf8("click1Button"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/res/click1p.png"), QSize(), QIcon::Normal, QIcon::Off);
        click1Button->setIcon(icon5);
        click1Button->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(click1Button);

        click2Button = new QPushButton(centralwidget);
        click2Button->setObjectName(QString::fromUtf8("click2Button"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/res/click2.png"), QSize(), QIcon::Normal, QIcon::Off);
        click2Button->setIcon(icon6);
        click2Button->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(click2Button);

        clickRButton = new QPushButton(centralwidget);
        clickRButton->setObjectName(QString::fromUtf8("clickRButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/res/clickR.png"), QSize(), QIcon::Normal, QIcon::Off);
        clickRButton->setIcon(icon7);
        clickRButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(clickRButton);

        clickDButton = new QPushButton(centralwidget);
        clickDButton->setObjectName(QString::fromUtf8("clickDButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/res/drag.png"), QSize(), QIcon::Normal, QIcon::Off);
        clickDButton->setIcon(icon8);
        clickDButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(clickDButton);

        optionsButton = new QPushButton(centralwidget);
        optionsButton->setObjectName(QString::fromUtf8("optionsButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/res/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        optionsButton->setIcon(icon9);
        optionsButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(optionsButton);

        appButton = new QPushButton(centralwidget);
        appButton->setObjectName(QString::fromUtf8("appButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/res/app.png"), QSize(), QIcon::Normal, QIcon::Off);
        appButton->setIcon(icon10);
        appButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(appButton);

        hideButton = new QPushButton(centralwidget);
        hideButton->setObjectName(QString::fromUtf8("hideButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/res/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideButton->setIcon(icon11);
        hideButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(hideButton);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/res/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon12);
        exitButton->setIconSize(QSize(50, 50));

        horizontalButtonsLayout->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalButtonsLayout);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        geoSmileButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Face Controlled Mouse", nullptr));
        inVideo->setText(QString());
        stopButton->setText(QString());
        geoSmileButton->setText(QString());
        aiSmileButton->setText(QString());
        dwellButton->setText(QString());
        click1Button->setText(QString());
        clickDButton->setText(QString());
        optionsButton->setText(QString());
        appButton->setText(QString());
        hideButton->setText(QString());
        exitButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
