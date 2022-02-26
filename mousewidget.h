#ifndef MOUSEWIDGET_H
#define MOUSEWIDGET_H

#include <QDockWidget>
#include <QCursor>
#include <QElapsedTimer>
#include <QTimer>
#include <QMouseEvent>


#include <QSoundEffect>




#include "Ewma.h"

#include <QDebug>

namespace Ui {
class MouseWidget;
}

class MouseWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit MouseWidget(QWidget *parent = nullptr);
    ~MouseWidget();

public slots:
    void updatePosition(QPoint pt);
//    void timerMouseDlg(bool detect);
    void quickSmileDetecting(bool detect);
    void dwellDetecting(float dist);

signals:
   void returnTo1Click();

private:
    Ui::MouseWidget *ui;


  QSoundEffect *clickSoundEffect;


public:
    float pauseTime = 1000;
    int horLimit = 0;
    int vertLimit = 0;
    double ewmaAlpha = 0.6;
    Ewma facialFilterX;
    Ewma facialFilterY;

    int newDx;
    int newDy;

    int mouseX;
    int mouseY;

    float sideRatio = 0.7;
    float newL, newT, newW, newH;
    float dSmallSide;
    QElapsedTimer *mouseTimer;
//    QElapsedTimer *smileTimer;
    QElapsedTimer *stopActionsTimer;


    enum MouseConditions
    {
        IDLEMOUSE,//GREY
        STARTTIMER,//GREEN
        CLICKTIMER,//ORANGE
        SCLICKTIMER//RED
    };

    MouseConditions mouseCodition = IDLEMOUSE;

    QString idleStyle = "background-color: rgb(78, 78, 78);";
    QString startTimerStyle = "background-color: rgb(0, 200, 0);";
    QString clickTimerStyle = "background-color: rgb(255, 145, 0);";
    QString sclickTimerStyle = "background-color: rgb(255, 0, 0);";

    QRegion c1;
    QRegion c2;
    QRegion c3;

    QPoint oldCursorPos;

    bool actionLocked = false;
    bool clickMoveLocked = false;

public:
    void changeSize(float ratio);
//    void disableAction();



///////////////////////////////////

public:

    bool notDragFlag = true;
    bool notDropFlag = true;
    bool needSound = true;


    enum ClicksFaces
    {
        LOSTFACE,//GRAY
        NEUTRAL,//WHITE
        SMILING,//GREEN
        DWELL,//GREEN
        ONE_CLICK,//ORANGE
        DOUBLE,//DEEP ORANGE
        CANCEL,//RED
        PAUSE
    };

    ClicksFaces click = NEUTRAL;

    enum Clicks
    {
        ONE_CL,//ORANGE
        DOUBLE_CL,//DEEP ORANGE
        RIGHT_CL,//RED
        DRAG//,
        //DO_NOTHING
    };

    bool doNothing = true;
    Clicks mouseClick = ONE_CL;
    Clicks prevRightClick = ONE_CL;

    bool playSoundFlag = true;

    //Timer mouseTimer;
    //Timer dwellTimer;

    double elapsedSeconds;

    bool smileMouseLocked = true;
    bool dwellMouseLocked = true;

    float dwellDisp = 0.6;

    float secDwellStartTime = 2.0;
//    float dwellDuration = 0.8;

    float secQuickClick = 0.6;

    float secSmile = 0.6;
    float secOneClick = 0.9;
    float secDoubleClick = 0.9;
    float secCancel = 0.3;

    float secToOneClickDuration;
    float secToDoubleClickDuration;

    float secToOneClickCancelDuration;
    float secToDoubleClickCancelDuration;
    float secDuration = 0;

    bool isQuickClick = false;
    bool quickSmileUnlocked = true;

    void initiateStart();
    void stopTimers();
    void MouseInput();
    void resetPointer();

};

#endif // MOUSEWIDGET_H
