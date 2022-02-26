#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "tracker.h"
#include "mousewidget.h"
#include "optionsdialog.h"
#include "aboutdialog.h"
#include <QDebug>
#include <QMouseEvent>
#include <QProcess>
#include <QFileDialog>
#include <QCamera>

#include <QMediaDevices>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readSerialized(QString fString);
    void serializeData();
    void initiateDialogs();
    void initiateOptionsDialog();
    void backUp();
    void saveForCancel();
private:




public slots:

    void onGeoSmileButton_pressed();

    void onAISmileButton_pressed();

    void onDwellButton_pressed();

    void onClick1Button_pressed();

    void onStopButton_pressed();

    void onClick2Button_pressed();

    void onClickRButton_pressed();

    void onClickDButton_pressed();

 //   void onOptionsButton_pressed();

    void onAppButton_pressed();

    void onHideButton_pressed();

    void onExitButton_pressed();

    void hideWithDelay();

    void underStartButton();

    void setVideoPixmap(QPixmap qp);

    void onOptionsButton_clicked();

    void FsmileAngleSlider(int val);

    void pathDialog();

    void changeLanguage(int index);

    void changeCamera(int index);

    void onOdCancel_clicked();

    void onOdApply_clicked();

    void resetDefaults();

    void aboutDialog();

    void pathTextChanged(QString newpath);

private:
    Ui::MainWindow *ui;
    QTimer *hideTimer;
    QProcess *process;
    bool processFlag = false;
    QString pathToApp = "C:/TC/TOTALCMD64.EXE";
    int savedHeight = 200;
    QTranslator *ruTranslator;
    QTranslator *uaTranslator;

    // backup
    QString _pathToApp;
    float _horSensitivity;
    float _verSensitivity;
    float _velocityK;
    int _smilingTriggerAngle;
    int _minNeighborsSmileDetector;
    float _secDwellStartTime;
    float _dwellDisp;
    float _secQuickClick;
    float _pauseTime;
    bool _flipCameraFlag;
    bool _needEqualize;
    bool _playSoundFlag;
    int _faceFPS;
    int _trackerFPS;
    double _ewmaAlpha;
    int _minFaceNeighbors;
    double _minDistRatio;
    int _minCornersCount;


public:
    Tracker *tracker;
    //FaceTracker *facetracker;
    bool needTrackerInitiate = true;
    bool  skipClick = true;
    MouseWidget *pm;
    OptionsDialog *od;
    AboutDialog *ad;

    bool needResetMouseCondition = false;
    QPushButton * exitButton;
//    int trackerFPS = 20;
    int language = 0;
    bool needAutostart = false;
    QTimer* faceTrackerTimer;
    QTimer* trackerTimer;



//    int cameraIndex = 0;


};
#endif // MAINWINDOW_H
