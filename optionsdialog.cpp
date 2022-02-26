#include "optionsdialog.h"
#include "ui_optionsdialog.h"


OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);


    ///////////////////////////
    // Main tab
    tabMain = ui->tabMain;
    // speed UI
    speedGroupBox = ui->speedGroupBox;
    horizontalSpeedSlider = ui->horizontalSpeedSlider;
    horizontalSpeedLabel = ui->horizontalSpeedLabel;
    verticalSpeedSlider = ui->verticalSpeedSlider;
    verticalSpeedLabel = ui->verticalSpeedLabel;
    accelerationSlider = ui->accelerationSlider;
    accelerationLabel = ui->accelerationLabel;
    // smile UI
    smileGroupBox  = ui->smileGroupBox;
    smileAngleSlider  = ui->smileAngleSlider;
    smileAngleLabel  = ui->smileAngleLabel;
    smileAISlider  = ui->smileAISlider;
    smileAILabel  = ui->smileAILabel;
    // dwell UI
    dwellGroupBox  = ui->dwellGroupBox;
    timeToDwellSlider  = ui->timeToDwellSlider;
    timeToDwellLabel  = ui->timeToDwellLabel;
    dwellDisplacementSlider  = ui->dwellDisplacementSlider;
    dwellDisplacementLabel  = ui->dwellDisplacementLabel;
    //  etc
    timeToClickSlider  = ui->timeToClickSlider;
    timeToClickLabel  = ui->timeToClickLabel;
    mousePauseSlider  = ui->mousePauseSlider;
    mousePauseLabel  = ui->mousePauseLabel;
    ///////////////////////////
    // Adavanced tab
    tabAdvanced  = ui->tabAdvanced;
    flipCheckBox  = ui->flipCheckBox;
    mouseClickBox  = ui->mouseClickBox;
    equalizeCheckBox  = ui->equalizeCheckBox;
    autostartCheckBox  = ui->autostartCheckBox;
    languageComboBox  = ui->languageComboBox;
    webcamComboBox  = ui->webcamComboBox;
    webcamLabel = ui->webcamLabel;
    pathLineEdit  = ui->pathLineEdit;
    pathLabel  = ui->pathLabel;
    pathButton = ui->pathButton;
    // Sliders
    faceFPSSlider  = ui->faceFPSSlider;
    faceFPSlabel  = ui->faceFPSlabel;
    trackerFPSSlider  = ui->trackerFPSSlider;
    trackerFPSlabel  = ui->trackerFPSlabel;
    faceThSlider  = ui->faceThSlider;
    faceThLabel  = ui->faceThLabel;
    filtrationSlider  = ui->filtrationSlider;
    filtrationLabel  = ui->filtrationLabel;
    cellsNumSlider  = ui->cellsNumSlider;
    cellsNumLabel  = ui->cellsNumLabel;
    minMarksSlider  = ui->minMarksSlider;
    minMarksLabel  = ui->minMarksLabel;
    aboutButton  = ui->aboutButton;
    resetButton  = ui->resetButton;
    buttonBox = ui->buttonBox;


    ui->verticalSpeedSlider->setRange(3, 100);
    ui->horizontalSpeedSlider->setRange(3, 130);
    ui->accelerationSlider->setRange(10, 60);
    ui->smileAngleSlider->setRange(60, 170);
    ui->smileAISlider->setRange(2, 250);
    ui->timeToDwellSlider->setRange(2, 50);
    ui->dwellDisplacementSlider->setRange(1, 60);
    ui->timeToClickSlider->setRange(2, 40);
    ui->mousePauseSlider->setRange(2, 100);
    ui->faceFPSSlider->setRange(1, 30);
    ui->trackerFPSSlider->setRange(0, 100);
    ui->faceThSlider->setRange(2, 100);
    ui->filtrationSlider->setRange(1, 100);
    ui->cellsNumSlider->setRange(1, 10);
    ui->minMarksSlider->setRange(3, 15);

#ifdef Q_OS_MAC
    autostartCheckBox->hide();
#endif

}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}


void OptionsDialog::on_horizontalSpeedSlider_valueChanged(int value)
{
    horizontalSpeedLabel->setText(horizontalSpeedLabelS + QString::number((float) value/10));

}


void OptionsDialog::on_verticalSpeedSlider_valueChanged(int value)
{
    verticalSpeedLabel->setText(verticalSpeedLabelS + QString::number((float) value/10));
}


void OptionsDialog::on_accelerationSlider_valueChanged(int value)
{
    accelerationLabel->setText(accelerationLabelS + QString::number((float) value/10));
}

void OptionsDialog::on_smileAngleSlider_valueChanged(int value)
{
    smileAngleLabel->setText(smileAngleLabelS + QString::number(value));
}


void OptionsDialog::on_smileAISlider_valueChanged(int value)
{
    smileAILabel->setText(smileAILabelS + QString::number(value));
}


void OptionsDialog::on_timeToDwellSlider_valueChanged(int value)
{
    timeToDwellLabel->setText(timeToDwellLabelS + QString::number((float) value/10));
}


void OptionsDialog::on_dwellDisplacementSlider_valueChanged(int value)
{
    dwellDisplacementLabel->setText(dwellDisplacementLabelS + QString::number((float) value/10));
}


void OptionsDialog::on_timeToClickSlider_valueChanged(int value)
{
    timeToClickLabel->setText(timeToClickLabelS + QString::number((float) value/10));
}


void OptionsDialog::on_mousePauseSlider_valueChanged(int value)
{
    mousePauseLabel->setText(mousePauseLabelS + QString::number((float) value/10));
}


void OptionsDialog::on_faceFPSSlider_valueChanged(int value)
{
    faceFPSlabel->setText(faceFPSlabelS + QString::number(value));
}


void OptionsDialog::on_trackerFPSSlider_valueChanged(int value)
{
    trackerFPSlabel->setText(trackerFPSlabelS + QString::number(value));
}


void OptionsDialog::on_filtrationSlider_valueChanged(int value)
{
    filtrationLabel->setText(filtrationLabelS + QString::number((float) value/100));
}


void OptionsDialog::on_faceThSlider_valueChanged(int value)
{
    faceThLabel->setText(faceThLabelS + QString::number(value));
}


void OptionsDialog::on_cellsNumSlider_valueChanged(int value)
{
    cellsNumLabel->setText(cellsNumLabelS + QString::number(value));
}


void OptionsDialog::on_minMarksSlider_valueChanged(int value)
{
    minMarksLabel->setText(minMarksLabelS + QString::number(value));
}


void OptionsDialog::on_autostartCheckBox_stateChanged(int arg1)
{

    if (arg1)
    {
#ifdef Q_OS_WIN32
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    settings.setValue("FaceControlledMouse", QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
    settings.sync();
  //  settings.
#endif

    }
    else
    {
#ifdef Q_OS_WIN32
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    settings.remove("FaceControlledMouse");
#endif
    }
  // qDebug() << arg1;
}

void OptionsDialog::retranslateDialogUi()
{
    ui->retranslateUi(this);

    horizontalSpeedLabelS = horizontalSpeedLabel->text();
    verticalSpeedLabelS = verticalSpeedLabel->text();
    accelerationLabelS = accelerationLabel->text();
    smileAngleLabelS = smileAngleLabel->text();
    smileAILabelS = smileAILabel->text();
    timeToDwellLabelS = timeToDwellLabel->text();
    dwellDisplacementLabelS = dwellDisplacementLabel->text();
    timeToClickLabelS = timeToClickLabel->text();
    mousePauseLabelS = mousePauseLabel->text();
    faceFPSlabelS = faceFPSlabel->text();
    trackerFPSlabelS = trackerFPSlabel->text();
    filtrationLabelS = filtrationLabel->text();
    faceThLabelS = faceThLabel->text();
    cellsNumLabelS = cellsNumLabel->text();
    minMarksLabelS = minMarksLabel->text();

    horizontalSpeedLabel->setText(horizontalSpeedLabelS + QString::number((float)horizontalSpeedSlider->value()/10));
    verticalSpeedLabel->setText(verticalSpeedLabelS + QString::number((float)verticalSpeedSlider->value()/10));
    accelerationLabel->setText(accelerationLabelS + QString::number((float)accelerationSlider->value()/10));
    smileAngleLabel->setText(smileAngleLabelS + QString::number(smileAngleSlider->value()));
    smileAILabel->setText(smileAILabelS + QString::number(smileAISlider->value()));
    timeToDwellLabel->setText(timeToDwellLabelS + QString::number((float)timeToDwellSlider->value()/10));
    dwellDisplacementLabel->setText(dwellDisplacementLabelS + QString::number((float)dwellDisplacementSlider->value()/10));
    timeToClickLabel->setText(timeToClickLabelS + QString::number((float)timeToClickSlider->value()/10));
    mousePauseLabel->setText(mousePauseLabelS + QString::number((float)mousePauseSlider->value()/10));
    faceFPSlabel->setText(faceFPSlabelS + QString::number(faceFPSSlider->value()));
    trackerFPSlabel->setText(trackerFPSlabelS + QString::number(trackerFPSSlider->value()));
    filtrationLabel->setText(filtrationLabelS + QString::number((float)filtrationSlider->value()/100));
    faceThLabel->setText(faceThLabelS + QString::number(faceThSlider->value()));
    cellsNumLabel->setText(cellsNumLabelS + QString::number(cellsNumSlider->value()));
    minMarksLabel->setText(minMarksLabelS + QString::number(minMarksSlider->value()));



}



void OptionsDialog::on_aboutButton_clicked()
{

}

