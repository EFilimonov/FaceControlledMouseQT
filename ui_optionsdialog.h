/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabOptionsWidget;
    QWidget *tabMain;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *timeToClickLayout;
    QLabel *timeToClickLabel;
    QSlider *timeToClickSlider;
    QGroupBox *dwellGroupBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *dwellVerticalLayout;
    QVBoxLayout *smileAILayout_3;
    QLabel *timeToDwellLabel;
    QSlider *timeToDwellSlider;
    QLabel *dwellDisplacementLabel;
    QSlider *dwellDisplacementSlider;
    QLabel *dwellIcon;
    QGroupBox *smileGroupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *smileAIHorizontalLayout;
    QVBoxLayout *smileAILayout;
    QLabel *smileAILabel;
    QSlider *smileAISlider;
    QLabel *smileAIIcon;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *smileAngleHorizontalLayout;
    QVBoxLayout *smileAngleLayout;
    QLabel *smileAngleLabel;
    QSlider *smileAngleSlider;
    QLabel *smileAngleIcon;
    QGroupBox *speedGroupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *speedLayout;
    QLabel *horizontalSpeedLabel;
    QSlider *horizontalSpeedSlider;
    QLabel *verticalSpeedLabel;
    QSlider *verticalSpeedSlider;
    QLabel *accelerationLabel;
    QSlider *accelerationSlider;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *mousePauseLayout;
    QLabel *mousePauseLabel;
    QSlider *mousePauseSlider;
    QWidget *tabAdvanced;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *equalizeCheckBox;
    QCheckBox *autostartCheckBox;
    QCheckBox *mouseClickBox;
    QCheckBox *flipCheckBox;
    QHBoxLayout *languageLayout;
    QLabel *languageLabel;
    QComboBox *languageComboBox;
    QHBoxLayout *webcamLayout;
    QLabel *webcamLabel;
    QComboBox *webcamComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *pathLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pathButton;
    QLineEdit *pathLineEdit;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *buttonsLayout;
    QPushButton *aboutButton;
    QPushButton *resetButton;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *etcLayout;
    QLabel *faceFPSlabel;
    QSlider *faceFPSSlider;
    QLabel *trackerFPSlabel;
    QSlider *trackerFPSSlider;
    QLabel *filtrationLabel;
    QSlider *filtrationSlider;
    QLabel *faceThLabel;
    QSlider *faceThSlider;
    QLabel *cellsNumLabel;
    QSlider *cellsNumSlider;
    QLabel *minMarksLabel;
    QSlider *minMarksSlider;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(407, 640);
        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 610, 381, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        tabOptionsWidget = new QTabWidget(OptionsDialog);
        tabOptionsWidget->setObjectName(QString::fromUtf8("tabOptionsWidget"));
        tabOptionsWidget->setGeometry(QRect(0, 0, 431, 611));
        QFont font;
        font.setBold(true);
        font.setWeight(QFont::Weight(75));
        tabOptionsWidget->setFont(font);
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        verticalLayoutWidget_4 = new QWidget(tabMain);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 480, 381, 52));
        timeToClickLayout = new QVBoxLayout(verticalLayoutWidget_4);
        timeToClickLayout->setObjectName(QString::fromUtf8("timeToClickLayout"));
        timeToClickLayout->setContentsMargins(0, 0, 0, 0);
        timeToClickLabel = new QLabel(verticalLayoutWidget_4);
        timeToClickLabel->setObjectName(QString::fromUtf8("timeToClickLabel"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(QFont::Weight(50));
        timeToClickLabel->setFont(font1);

        timeToClickLayout->addWidget(timeToClickLabel);

        timeToClickSlider = new QSlider(verticalLayoutWidget_4);
        timeToClickSlider->setObjectName(QString::fromUtf8("timeToClickSlider"));
        timeToClickSlider->setOrientation(Qt::Horizontal);
        timeToClickSlider->setTickPosition(QSlider::TicksBelow);

        timeToClickLayout->addWidget(timeToClickSlider);

        dwellGroupBox = new QGroupBox(tabMain);
        dwellGroupBox->setObjectName(QString::fromUtf8("dwellGroupBox"));
        dwellGroupBox->setGeometry(QRect(10, 340, 381, 131));
        dwellGroupBox->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(dwellGroupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 20, 381, 113));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dwellVerticalLayout = new QVBoxLayout();
        dwellVerticalLayout->setObjectName(QString::fromUtf8("dwellVerticalLayout"));
        smileAILayout_3 = new QVBoxLayout();
        smileAILayout_3->setObjectName(QString::fromUtf8("smileAILayout_3"));
        timeToDwellLabel = new QLabel(horizontalLayoutWidget_3);
        timeToDwellLabel->setObjectName(QString::fromUtf8("timeToDwellLabel"));
        timeToDwellLabel->setFont(font1);

        smileAILayout_3->addWidget(timeToDwellLabel);

        timeToDwellSlider = new QSlider(horizontalLayoutWidget_3);
        timeToDwellSlider->setObjectName(QString::fromUtf8("timeToDwellSlider"));
        timeToDwellSlider->setOrientation(Qt::Horizontal);
        timeToDwellSlider->setTickPosition(QSlider::TicksBelow);

        smileAILayout_3->addWidget(timeToDwellSlider);

        dwellDisplacementLabel = new QLabel(horizontalLayoutWidget_3);
        dwellDisplacementLabel->setObjectName(QString::fromUtf8("dwellDisplacementLabel"));
        dwellDisplacementLabel->setFont(font1);

        smileAILayout_3->addWidget(dwellDisplacementLabel);

        dwellDisplacementSlider = new QSlider(horizontalLayoutWidget_3);
        dwellDisplacementSlider->setObjectName(QString::fromUtf8("dwellDisplacementSlider"));
        dwellDisplacementSlider->setOrientation(Qt::Horizontal);
        dwellDisplacementSlider->setTickPosition(QSlider::TicksBelow);

        smileAILayout_3->addWidget(dwellDisplacementSlider);


        dwellVerticalLayout->addLayout(smileAILayout_3);


        horizontalLayout->addLayout(dwellVerticalLayout);

        dwellIcon = new QLabel(horizontalLayoutWidget_3);
        dwellIcon->setObjectName(QString::fromUtf8("dwellIcon"));
        dwellIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/res/dwell.png")));

        horizontalLayout->addWidget(dwellIcon);

        smileGroupBox = new QGroupBox(tabMain);
        smileGroupBox->setObjectName(QString::fromUtf8("smileGroupBox"));
        smileGroupBox->setGeometry(QRect(10, 190, 385, 150));
        smileGroupBox->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(smileGroupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 80, 381, 61));
        smileAIHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        smileAIHorizontalLayout->setObjectName(QString::fromUtf8("smileAIHorizontalLayout"));
        smileAIHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        smileAILayout = new QVBoxLayout();
        smileAILayout->setObjectName(QString::fromUtf8("smileAILayout"));
        smileAILabel = new QLabel(horizontalLayoutWidget_2);
        smileAILabel->setObjectName(QString::fromUtf8("smileAILabel"));
        smileAILabel->setFont(font1);

        smileAILayout->addWidget(smileAILabel);

        smileAISlider = new QSlider(horizontalLayoutWidget_2);
        smileAISlider->setObjectName(QString::fromUtf8("smileAISlider"));
        smileAISlider->setOrientation(Qt::Horizontal);
        smileAISlider->setTickPosition(QSlider::TicksBelow);

        smileAILayout->addWidget(smileAISlider);


        smileAIHorizontalLayout->addLayout(smileAILayout);

        smileAIIcon = new QLabel(horizontalLayoutWidget_2);
        smileAIIcon->setObjectName(QString::fromUtf8("smileAIIcon"));
        smileAIIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/res/AI.png")));
        smileAIIcon->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        smileAIHorizontalLayout->addWidget(smileAIIcon);

        horizontalLayoutWidget = new QWidget(smileGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 381, 59));
        smileAngleHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        smileAngleHorizontalLayout->setObjectName(QString::fromUtf8("smileAngleHorizontalLayout"));
        smileAngleHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        smileAngleLayout = new QVBoxLayout();
        smileAngleLayout->setObjectName(QString::fromUtf8("smileAngleLayout"));
        smileAngleLabel = new QLabel(horizontalLayoutWidget);
        smileAngleLabel->setObjectName(QString::fromUtf8("smileAngleLabel"));
        smileAngleLabel->setFont(font1);

        smileAngleLayout->addWidget(smileAngleLabel);

        smileAngleSlider = new QSlider(horizontalLayoutWidget);
        smileAngleSlider->setObjectName(QString::fromUtf8("smileAngleSlider"));
        smileAngleSlider->setOrientation(Qt::Horizontal);
        smileAngleSlider->setTickPosition(QSlider::TicksBelow);

        smileAngleLayout->addWidget(smileAngleSlider);


        smileAngleHorizontalLayout->addLayout(smileAngleLayout);

        smileAngleIcon = new QLabel(horizontalLayoutWidget);
        smileAngleIcon->setObjectName(QString::fromUtf8("smileAngleIcon"));
        smileAngleIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/res/GEO.png")));
        smileAngleIcon->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        smileAngleHorizontalLayout->addWidget(smileAngleIcon);

        speedGroupBox = new QGroupBox(tabMain);
        speedGroupBox->setObjectName(QString::fromUtf8("speedGroupBox"));
        speedGroupBox->setGeometry(QRect(10, 10, 421, 181));
        speedGroupBox->setFont(font);
        verticalLayoutWidget = new QWidget(speedGroupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 15, 381, 166));
        speedLayout = new QVBoxLayout(verticalLayoutWidget);
        speedLayout->setObjectName(QString::fromUtf8("speedLayout"));
        speedLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpeedLabel = new QLabel(verticalLayoutWidget);
        horizontalSpeedLabel->setObjectName(QString::fromUtf8("horizontalSpeedLabel"));
        horizontalSpeedLabel->setFont(font1);

        speedLayout->addWidget(horizontalSpeedLabel);

        horizontalSpeedSlider = new QSlider(verticalLayoutWidget);
        horizontalSpeedSlider->setObjectName(QString::fromUtf8("horizontalSpeedSlider"));
        horizontalSpeedSlider->setOrientation(Qt::Horizontal);
        horizontalSpeedSlider->setTickPosition(QSlider::TicksBelow);

        speedLayout->addWidget(horizontalSpeedSlider);

        verticalSpeedLabel = new QLabel(verticalLayoutWidget);
        verticalSpeedLabel->setObjectName(QString::fromUtf8("verticalSpeedLabel"));
        verticalSpeedLabel->setFont(font1);

        speedLayout->addWidget(verticalSpeedLabel);

        verticalSpeedSlider = new QSlider(verticalLayoutWidget);
        verticalSpeedSlider->setObjectName(QString::fromUtf8("verticalSpeedSlider"));
        verticalSpeedSlider->setEnabled(true);
        verticalSpeedSlider->setOrientation(Qt::Horizontal);
        verticalSpeedSlider->setTickPosition(QSlider::TicksBelow);

        speedLayout->addWidget(verticalSpeedSlider);

        accelerationLabel = new QLabel(verticalLayoutWidget);
        accelerationLabel->setObjectName(QString::fromUtf8("accelerationLabel"));
        accelerationLabel->setFont(font1);

        speedLayout->addWidget(accelerationLabel);

        accelerationSlider = new QSlider(verticalLayoutWidget);
        accelerationSlider->setObjectName(QString::fromUtf8("accelerationSlider"));
        accelerationSlider->setOrientation(Qt::Horizontal);
        accelerationSlider->setTickPosition(QSlider::TicksBelow);

        speedLayout->addWidget(accelerationSlider);

        verticalLayoutWidget_5 = new QWidget(tabMain);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 530, 381, 52));
        mousePauseLayout = new QVBoxLayout(verticalLayoutWidget_5);
        mousePauseLayout->setObjectName(QString::fromUtf8("mousePauseLayout"));
        mousePauseLayout->setContentsMargins(0, 0, 0, 0);
        mousePauseLabel = new QLabel(verticalLayoutWidget_5);
        mousePauseLabel->setObjectName(QString::fromUtf8("mousePauseLabel"));
        mousePauseLabel->setFont(font1);

        mousePauseLayout->addWidget(mousePauseLabel);

        mousePauseSlider = new QSlider(verticalLayoutWidget_5);
        mousePauseSlider->setObjectName(QString::fromUtf8("mousePauseSlider"));
        mousePauseSlider->setOrientation(Qt::Horizontal);
        mousePauseSlider->setTickPosition(QSlider::TicksBelow);

        mousePauseLayout->addWidget(mousePauseSlider);

        tabOptionsWidget->addTab(tabMain, QString());
        tabAdvanced = new QWidget();
        tabAdvanced->setObjectName(QString::fromUtf8("tabAdvanced"));
        gridLayoutWidget = new QWidget(tabAdvanced);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 103));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        equalizeCheckBox = new QCheckBox(gridLayoutWidget);
        equalizeCheckBox->setObjectName(QString::fromUtf8("equalizeCheckBox"));
        equalizeCheckBox->setFont(font1);

        gridLayout->addWidget(equalizeCheckBox, 0, 1, 1, 1);

        autostartCheckBox = new QCheckBox(gridLayoutWidget);
        autostartCheckBox->setObjectName(QString::fromUtf8("autostartCheckBox"));
        autostartCheckBox->setFont(font1);

        gridLayout->addWidget(autostartCheckBox, 1, 1, 1, 1);

        mouseClickBox = new QCheckBox(gridLayoutWidget);
        mouseClickBox->setObjectName(QString::fromUtf8("mouseClickBox"));
        mouseClickBox->setFont(font1);

        gridLayout->addWidget(mouseClickBox, 1, 0, 1, 1);

        flipCheckBox = new QCheckBox(gridLayoutWidget);
        flipCheckBox->setObjectName(QString::fromUtf8("flipCheckBox"));
        flipCheckBox->setFont(font1);

        gridLayout->addWidget(flipCheckBox, 0, 0, 1, 1);

        languageLayout = new QHBoxLayout();
        languageLayout->setObjectName(QString::fromUtf8("languageLayout"));
        languageLabel = new QLabel(gridLayoutWidget);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(languageLabel->sizePolicy().hasHeightForWidth());
        languageLabel->setSizePolicy(sizePolicy);
        languageLabel->setFont(font1);
        languageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        languageLayout->addWidget(languageLabel);

        languageComboBox = new QComboBox(gridLayoutWidget);
        languageComboBox->setObjectName(QString::fromUtf8("languageComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(languageComboBox->sizePolicy().hasHeightForWidth());
        languageComboBox->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(QFont::Weight(50));
        languageComboBox->setFont(font2);

        languageLayout->addWidget(languageComboBox);


        gridLayout->addLayout(languageLayout, 4, 0, 1, 1);

        webcamLayout = new QHBoxLayout();
        webcamLayout->setObjectName(QString::fromUtf8("webcamLayout"));
        webcamLabel = new QLabel(gridLayoutWidget);
        webcamLabel->setObjectName(QString::fromUtf8("webcamLabel"));
        webcamLabel->setFont(font1);
        webcamLabel->setLayoutDirection(Qt::LeftToRight);
        webcamLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        webcamLayout->addWidget(webcamLabel);

        webcamComboBox = new QComboBox(gridLayoutWidget);
        webcamComboBox->setObjectName(QString::fromUtf8("webcamComboBox"));
        webcamComboBox->setFont(font2);

        webcamLayout->addWidget(webcamComboBox);


        gridLayout->addLayout(webcamLayout, 4, 1, 1, 1);

        verticalLayoutWidget_2 = new QWidget(tabAdvanced);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 110, 381, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pathLabel = new QLabel(verticalLayoutWidget_2);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));
        pathLabel->setFont(font1);

        verticalLayout->addWidget(pathLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pathButton = new QPushButton(verticalLayoutWidget_2);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/res/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pathButton->setIcon(icon);
        pathButton->setIconSize(QSize(50, 20));

        horizontalLayout_2->addWidget(pathButton);

        pathLineEdit = new QLineEdit(verticalLayoutWidget_2);
        pathLineEdit->setObjectName(QString::fromUtf8("pathLineEdit"));
        pathLineEdit->setFont(font1);

        horizontalLayout_2->addWidget(pathLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget_5 = new QWidget(tabAdvanced);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 540, 371, 30));
        buttonsLayout = new QHBoxLayout(horizontalLayoutWidget_5);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        aboutButton = new QPushButton(horizontalLayoutWidget_5);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setFont(font1);

        buttonsLayout->addWidget(aboutButton);

        resetButton = new QPushButton(horizontalLayoutWidget_5);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setFont(font1);

        buttonsLayout->addWidget(resetButton);

        verticalLayoutWidget_6 = new QWidget(tabAdvanced);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 180, 381, 351));
        etcLayout = new QVBoxLayout(verticalLayoutWidget_6);
        etcLayout->setObjectName(QString::fromUtf8("etcLayout"));
        etcLayout->setContentsMargins(0, 0, 0, 0);
        faceFPSlabel = new QLabel(verticalLayoutWidget_6);
        faceFPSlabel->setObjectName(QString::fromUtf8("faceFPSlabel"));
        faceFPSlabel->setFont(font1);

        etcLayout->addWidget(faceFPSlabel);

        faceFPSSlider = new QSlider(verticalLayoutWidget_6);
        faceFPSSlider->setObjectName(QString::fromUtf8("faceFPSSlider"));
        faceFPSSlider->setOrientation(Qt::Horizontal);
        faceFPSSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(faceFPSSlider);

        trackerFPSlabel = new QLabel(verticalLayoutWidget_6);
        trackerFPSlabel->setObjectName(QString::fromUtf8("trackerFPSlabel"));
        trackerFPSlabel->setFont(font1);

        etcLayout->addWidget(trackerFPSlabel);

        trackerFPSSlider = new QSlider(verticalLayoutWidget_6);
        trackerFPSSlider->setObjectName(QString::fromUtf8("trackerFPSSlider"));
        trackerFPSSlider->setOrientation(Qt::Horizontal);
        trackerFPSSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(trackerFPSSlider);

        filtrationLabel = new QLabel(verticalLayoutWidget_6);
        filtrationLabel->setObjectName(QString::fromUtf8("filtrationLabel"));
        filtrationLabel->setFont(font1);

        etcLayout->addWidget(filtrationLabel);

        filtrationSlider = new QSlider(verticalLayoutWidget_6);
        filtrationSlider->setObjectName(QString::fromUtf8("filtrationSlider"));
        filtrationSlider->setOrientation(Qt::Horizontal);
        filtrationSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(filtrationSlider);

        faceThLabel = new QLabel(verticalLayoutWidget_6);
        faceThLabel->setObjectName(QString::fromUtf8("faceThLabel"));
        faceThLabel->setFont(font1);

        etcLayout->addWidget(faceThLabel);

        faceThSlider = new QSlider(verticalLayoutWidget_6);
        faceThSlider->setObjectName(QString::fromUtf8("faceThSlider"));
        faceThSlider->setOrientation(Qt::Horizontal);
        faceThSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(faceThSlider);

        cellsNumLabel = new QLabel(verticalLayoutWidget_6);
        cellsNumLabel->setObjectName(QString::fromUtf8("cellsNumLabel"));
        cellsNumLabel->setFont(font1);

        etcLayout->addWidget(cellsNumLabel);

        cellsNumSlider = new QSlider(verticalLayoutWidget_6);
        cellsNumSlider->setObjectName(QString::fromUtf8("cellsNumSlider"));
        cellsNumSlider->setOrientation(Qt::Horizontal);
        cellsNumSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(cellsNumSlider);

        minMarksLabel = new QLabel(verticalLayoutWidget_6);
        minMarksLabel->setObjectName(QString::fromUtf8("minMarksLabel"));
        minMarksLabel->setFont(font1);

        etcLayout->addWidget(minMarksLabel);

        minMarksSlider = new QSlider(verticalLayoutWidget_6);
        minMarksSlider->setObjectName(QString::fromUtf8("minMarksSlider"));
        minMarksSlider->setOrientation(Qt::Horizontal);
        minMarksSlider->setTickPosition(QSlider::TicksBelow);

        etcLayout->addWidget(minMarksSlider);

        tabOptionsWidget->addTab(tabAdvanced, QString());

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        tabOptionsWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Dialog", nullptr));
        timeToClickLabel->setText(QApplication::translate("OptionsDialog", "Time to click, (sec): ", nullptr));
        dwellGroupBox->setTitle(QApplication::translate("OptionsDialog", "Dwell parameters:", nullptr));
        timeToDwellLabel->setText(QApplication::translate("OptionsDialog", "Dwell time, (sec): ", nullptr));
        dwellDisplacementLabel->setText(QApplication::translate("OptionsDialog", "Dwell displacement: ", nullptr));
        dwellIcon->setText(QString());
        smileGroupBox->setTitle(QApplication::translate("OptionsDialog", "Smile parameters:", nullptr));
        smileAILabel->setText(QApplication::translate("OptionsDialog", "Recognition threshold (AI): ", nullptr));
        smileAIIcon->setText(QString());
        smileAngleLabel->setText(QApplication::translate("OptionsDialog", "Smile angle (geometric): ", nullptr));
        smileAngleIcon->setText(QString());
        speedGroupBox->setTitle(QApplication::translate("OptionsDialog", "Speed parameters:", nullptr));
        horizontalSpeedLabel->setText(QApplication::translate("OptionsDialog", "Horizontal mouse speed (X): ", nullptr));
        verticalSpeedLabel->setText(QApplication::translate("OptionsDialog", "Vertical mouse speed (Y): ", nullptr));
        accelerationLabel->setText(QApplication::translate("OptionsDialog", "Acceleration: ", nullptr));
        mousePauseLabel->setText(QApplication::translate("OptionsDialog", "Pause after touching a physical mouse, (sec): ", nullptr));
        tabOptionsWidget->setTabText(tabOptionsWidget->indexOf(tabMain), QApplication::translate("OptionsDialog", "Main", nullptr));
        equalizeCheckBox->setText(QApplication::translate("OptionsDialog", "Equalize brightness", nullptr));
        autostartCheckBox->setText(QApplication::translate("OptionsDialog", "Autostart with Windows", nullptr));
        mouseClickBox->setText(QApplication::translate("OptionsDialog", "Mouse click sound", nullptr));
        flipCheckBox->setText(QApplication::translate("OptionsDialog", "Flip mouse movement", nullptr));
        languageLabel->setText(QApplication::translate("OptionsDialog", "Languagies:", nullptr));
        webcamLabel->setText(QApplication::translate("OptionsDialog", "Webcams:", nullptr));
        pathLabel->setText(QApplication::translate("OptionsDialog", "Path to onscreen application:", nullptr));
        pathButton->setText(QString());
        aboutButton->setText(QApplication::translate("OptionsDialog", "About", nullptr));
        resetButton->setText(QApplication::translate("OptionsDialog", "Reset to default settings", nullptr));
        faceFPSlabel->setText(QApplication::translate("OptionsDialog", "Face recognition FPS: ", nullptr));
        trackerFPSlabel->setText(QApplication::translate("OptionsDialog", "Face tracker latency:", nullptr));
        filtrationLabel->setText(QApplication::translate("OptionsDialog", "Smoothing threshold: ", nullptr));
        faceThLabel->setText(QApplication::translate("OptionsDialog", "Face recognition threshold (AI):", nullptr));
        cellsNumLabel->setText(QApplication::translate("OptionsDialog", "Cells/width: ", nullptr));
        minMarksLabel->setText(QApplication::translate("OptionsDialog", "Min marks: ", nullptr));
        tabOptionsWidget->setTabText(tabOptionsWidget->indexOf(tabAdvanced), QApplication::translate("OptionsDialog", "Advanced", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
