#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QTranslator>
#include <QDialogButtonBox>


namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = nullptr);
    ~OptionsDialog();   
    void retranslateDialogUi();

private:
//    void changeEvent(QEvent *event);

signals:
    void needAutostart(int val);

public slots:
    void on_smileAngleSlider_valueChanged(int value);

    void on_horizontalSpeedSlider_valueChanged(int value);

    void on_verticalSpeedSlider_valueChanged(int value);

    void on_accelerationSlider_valueChanged(int value);

    void on_smileAISlider_valueChanged(int value);

    void on_timeToDwellSlider_valueChanged(int value);

    void on_dwellDisplacementSlider_valueChanged(int value);

    void on_timeToClickSlider_valueChanged(int value);

    void on_mousePauseSlider_valueChanged(int value);

    void on_faceFPSSlider_valueChanged(int value);

    void on_trackerFPSSlider_valueChanged(int value);

    void on_filtrationSlider_valueChanged(int value);

    void on_faceThSlider_valueChanged(int value);

    void on_cellsNumSlider_valueChanged(int value);

    void on_minMarksSlider_valueChanged(int value);

    void on_autostartCheckBox_stateChanged(int arg1);

    void on_aboutButton_clicked();

private:
    Ui::OptionsDialog *ui;

public:   
    ///////////////////////////
    // Main tab
    QWidget* tabMain;
    QString tabMainS = tr("Main");

    // speed UI
    QGroupBox *speedGroupBox;
    QString speedGroupBoxS = tr("Speed parameters: ");

    QSlider *horizontalSpeedSlider;
    QLabel *horizontalSpeedLabel;
    QString horizontalSpeedLabelS = tr("Horizontal mouse speed (X): ");

    QSlider *verticalSpeedSlider;
    QLabel *verticalSpeedLabel;
    QString verticalSpeedLabelS = tr("Vertical mouse speed (Y): ");

    QSlider *accelerationSlider;
    QLabel *accelerationLabel;
    QString accelerationLabelS = tr("Acceleration: ");

    // smile UI
    QGroupBox *smileGroupBox;
    QString smileGroupBoxS = tr("Smile parameters: ");

    QSlider *smileAngleSlider;
    QLabel *smileAngleLabel;
    QString smileAngleLabelS = tr("Smile angle (geometric): ");

    QSlider *smileAISlider;
    QLabel *smileAILabel;
    QString smileAILabelS = tr("Recognition threshold (AI): ");

    // dwell UI
    QGroupBox *dwellGroupBox;
    QString dwellGroupBoxS = tr("Dwell parameters:");

    QSlider *timeToDwellSlider;
    QLabel *timeToDwellLabel;
    QString timeToDwellLabelS = tr("Dwell time, (sec): ");

    QSlider *dwellDisplacementSlider;
    QLabel *dwellDisplacementLabel;
    QString dwellDisplacementLabelS = tr("Dwell displacement: ");

    //  etc
    QSlider *timeToClickSlider;
    QLabel *timeToClickLabel;
    QString timeToClickLabelS = tr("Time to click, (sec): ");

    QSlider *mousePauseSlider;
    QLabel *mousePauseLabel;
    QString mousePauseLabelS = tr("Pause after touching a physical mouse, (sec):");

    ///////////////////////////
    // Adavanced tab
    QWidget* tabAdvanced;
    QString tabAdvancedS = tr("Advanced");

    // upper block
    QCheckBox *flipCheckBox;
    QString flipCheckBoxS = tr("Flip mouse movement");

    QCheckBox *mouseClickBox;
    QString mouseClickBoxS = tr("Mouse click sound");

    QCheckBox *equalizeCheckBox;
    QString equalizeCheckBoxS = tr("Equalize brightness");

    QCheckBox *autostartCheckBox;
    QString autostartCheckBoxS = tr("Autostart with Windows");

    QComboBox *languageComboBox;
    QString languageLabelS = tr("Languagies:");

    QComboBox *webcamComboBox;
    QLabel *webcamLabel;
    QString webcamLabelS = tr("Webcams:");

    QPushButton *pathButton;
    QLineEdit *pathLineEdit;
    QLabel *pathLabel;
    QString pathLabelS = tr("Path to onscreen application:");

    // Sliders
    QSlider *faceFPSSlider;
    QLabel *faceFPSlabel;
    QString faceFPSlabelS = tr("Face recognition FPS: ");

    QSlider *trackerFPSSlider;
    QLabel *trackerFPSlabel;
    QString trackerFPSlabelS = tr("Face tracker latency: ");

    QSlider *faceThSlider;
    QLabel *faceThLabel;
    QString faceThLabelS = tr("Face recognition threshold (AI): ");

    QSlider *filtrationSlider;
    QLabel *filtrationLabel;
    QString filtrationLabelS = tr("Smoothing threshold: ");

    QSlider *cellsNumSlider;
    QLabel *cellsNumLabel;
    QString cellsNumLabelS = tr("Cells/width: ");

    QSlider *minMarksSlider;
    QLabel *minMarksLabel;
    QString minMarksLabelS = tr("Min marks: ");

    // buttons
    QPushButton *aboutButton;
    QString aboutButtonText = tr("About");

    QPushButton *resetButton;
    QString resetButtonText = tr("Reset to default settings");

    QDialogButtonBox *buttonBox;





};

#endif // OPTIONSDIALOG_H
