#include "mousewidget.h"
#include "ui_mousewidget.h"


#ifdef Q_OS_WIN32
#include "windows.h"
#endif

#include <iostream>
#ifdef Q_OS_MAC
#include <ApplicationServices/ApplicationServices.h>
#endif


#include <QFile>
#include <QBuffer>

MouseWidget::MouseWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::MouseWidget)
{
    ui->setupUi(this);
    mouseTimer = new QElapsedTimer();
    stopActionsTimer = new QElapsedTimer();
    oldCursorPos = QCursor::pos();

    facialFilterX.alpha = ewmaAlpha;
    facialFilterY.alpha = ewmaAlpha;

    dSmallSide = (width() - width()*sideRatio) /2;

    changeSize(1.0);
    setStyleSheet(idleStyle);

    clickSoundEffect = new QSoundEffect;
    clickSoundEffect->setSource(QUrl::fromLocalFile(":/sounds/res/click.wav"));
    //clickSoundEffect->setLoopCount(QSoundEffect::Infinite);
    clickSoundEffect->setVolume(0.5f);


#ifdef Q_OS_MAC

    CFStringRef keys[] = { kAXTrustedCheckOptionPrompt };
    CFTypeRef values[] = { kCFBooleanTrue };
    CFDictionaryRef options = CFDictionaryCreate(NULL,
                                                 (const void **)&keys,
                                                 (const void **)&values,
                                                 sizeof(keys) / sizeof(keys[0]),
            &kCFTypeDictionaryKeyCallBacks,
            &kCFTypeDictionaryValueCallBacks);
    if(AXIsProcessTrustedWithOptions(options)) {
        std::cout << "trusted accessibility client" << std::endl;

    } else {
        std::cout << "not a trusted trusted accessibility client, so give the user a hint or do whatever is appropriate" << std::endl;
    }
    CFRelease(options);

#endif
}

MouseWidget::~MouseWidget()
{
    delete ui;
    mouseTimer->~QElapsedTimer();

    stopActionsTimer->~QElapsedTimer();

}


// Windows only function
void MouseWidget::MouseInput()
{

#ifdef Q_OS_WIN32
    const double XSCALEFACTOR = 65535 / (horLimit - 1);
    const double YSCALEFACTOR = 65535 / (vertLimit - 1);

    double cx = QCursor::pos().x() * XSCALEFACTOR;
    double cy = QCursor::pos().y() * YSCALEFACTOR;



    switch (mouseClick)
    {
    case ONE_CL:
        mouse_event(MOUSEEVENTF_LEFTDOWN, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, cx, cy, 0, 0);
        break;
    case DOUBLE_CL:
        mouse_event(MOUSEEVENTF_LEFTDOWN, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTDOWN, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, cx, cy, 0, 0);
        break;
    case RIGHT_CL:
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN, cx, cy, 0, 0);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP, cx, cy, 0, 0);
        // return control to the left click
        returnTo1Click();
        break;
    case DRAG:
        if (notDragFlag)
        {
            notDragFlag = false;

            mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, cx, cy, 0, 0);
            mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, cx, cy, 0, 0);

        }
        else
        {
            notDragFlag = true;

            mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, cx, cy, 0, 0);
            mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, cx, cy, 0, 0);

            // return control to the left click
            returnTo1Click();

        }
        break;


    }
#endif

#ifdef Q_OS_MAC

    //qDebug() << "mouseClick" << mouseClick;
    CGPoint pt;
    pt.x = QCursor::pos().x();
    pt.y = QCursor::pos().y();

    CGEventRef mouseEv;


    //   this->setEnabled(false);
    switch (mouseClick)
    {
    case ONE_CL:
        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseDown, pt, kCGMouseButtonLeft);
        //CGEventSetType(mouseEv, kCGEventLeftMouseDown);
        CGEventPost (kCGHIDEventTap, mouseEv);

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseUp, pt, kCGMouseButtonLeft);
        //CGEventSetType(mouseEv, kCGEventLeftMouseUp);
        CGEventPost (kCGHIDEventTap, mouseEv );

        break;
    case DOUBLE_CL:

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseDown, pt, kCGMouseButtonLeft);
        CGEventPost (kCGHIDEventTap, mouseEv);

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseUp, pt, kCGMouseButtonLeft);
        CGEventPost (kCGHIDEventTap, mouseEv );

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseDown, pt, kCGMouseButtonLeft);
        CGEventPost (kCGHIDEventTap, mouseEv);

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseUp, pt, kCGMouseButtonLeft);
        CGEventPost (kCGHIDEventTap, mouseEv );

        break;
    case RIGHT_CL:

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventRightMouseDown, pt, kCGMouseButtonRight);
        CGEventPost (kCGHIDEventTap, mouseEv);

        mouseEv = CGEventCreateMouseEvent (NULL, kCGEventRightMouseUp, pt, kCGMouseButtonRight);
        CGEventPost (kCGHIDEventTap, mouseEv );
        // return control to the left click
        returnTo1Click();
        break;
    case DRAG:
        if (notDragFlag)
        {
            notDragFlag = false;
            mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseDown, pt, kCGMouseButtonLeft);
            CGEventPost (kCGHIDEventTap, mouseEv);
        }
        else
        {
            notDragFlag = true;
            mouseEv = CGEventCreateMouseEvent (NULL, kCGEventLeftMouseUp, pt, kCGMouseButtonLeft);
            CGEventPost (kCGHIDEventTap, mouseEv);
            // return control to the left click
            returnTo1Click();
        }
        break;
    }
    CFRelease(mouseEv);

    //    this->setEnabled(true);
#endif
    if(playSoundFlag)clickSoundEffect->play();;
    oldCursorPos = QCursor::pos();
}



void MouseWidget::updatePosition(QPoint pt)
{

    if(actionLocked)
    {
        // timer off
        if (stopActionsTimer->elapsed() > pauseTime)
        {
            //qDebug() << "enableAction";

            facialFilterX.reset();
            facialFilterY.reset();

            actionLocked = false;

            move(QCursor::pos().x() - width()/2, QCursor::pos().y() - height()/2);

            show();
        }
        // timer still on
        else
        {
            // restart if physical mouse still move
            if(oldCursorPos !=QCursor::pos())
            {
                //qDebug() << "physical mouse move";
                stopActionsTimer->restart();
                actionLocked = true;
            }
        }

        oldCursorPos = QCursor::pos();
        return;
    }


    // if mouse position changed
    if(oldCursorPos !=QCursor::pos())
    {
        if ( // check if borders
             (QCursor::pos().x() + 1 == horLimit && QCursor::pos().y() == oldCursorPos.y())
             ||
             (QCursor::pos().y() + 1 == vertLimit && QCursor::pos().x() == oldCursorPos.x())
             )
        {

        }
        else // physical mouse moved
        {

            hide();
            actionLocked = true;
            stopActionsTimer->restart();
            resetPointer();
        }
    }
    else
    {
        //qDebug() << "dwell ox=" << oldCursorPos.x() << " nx=" << QCursor::pos().x();
    }


    //
    if(!actionLocked && !clickMoveLocked)
    {

        newDx = facialFilterX.filter(pt.x());
        newDy = facialFilterY.filter(pt.y());

        mouseX = QCursor::pos().x() + newDx;
        mouseY = QCursor::pos().y() + newDy;


        //mouseX = QCursor::pos().x() + pt.x();
        //mouseY = QCursor::pos().y() + pt.y();

        //mouseX = facialFilterX.filter(mouseX);
        //mouseY = facialFilterY.filter(mouseY);

        if (mouseX > horLimit) mouseX = horLimit;
        if (mouseY > vertLimit) mouseY = vertLimit;
        if (mouseX < 1) mouseX = 0;
        if (mouseY < 1) mouseY = 0;

        QCursor::setPos(QPoint(mouseX, mouseY));
        move(mouseX - width()/2, mouseY - height()/2);
        oldCursorPos = QPoint(mouseX, mouseY);

    }

}

void MouseWidget::changeSize(float ratio)
{

    newL = (width() - width() * ratio) / 2;
    newT = (height() - height() * ratio) / 2;
    newW = width() * ratio;
    newH = height() * ratio;


    c1 = QRegion (QRect(newL,
                        newT,
                        newW,
                        newH), QRegion::Ellipse);

    c2 = QRegion (QRect((newL + dSmallSide),
                        (newT + dSmallSide),
                        newW - dSmallSide*2,
                        newH - dSmallSide*2), QRegion::Ellipse);
    c3 = c1.xored(c2);

    this->setMask(c3);
}


void MouseWidget::dwellDetecting(float dist)
{

    if(actionLocked) return;

    if (dist < dwellDisp) // stopped or small moving now
    {
        if (mouseCodition == IDLEMOUSE)
        {
            mouseCodition = STARTTIMER;
            this->setStyleSheet(startTimerStyle);
            changeSize(1.0);
            mouseTimer->start();
        }

        elapsedSeconds = mouseTimer->elapsed()/1000.0;

        if (elapsedSeconds > secDwellStartTime)
        {
            // countdown
            if (elapsedSeconds < secDwellStartTime + secQuickClick)
            {
                if(mouseCodition != CLICKTIMER) this->setStyleSheet(clickTimerStyle);
                float _ratio = (secDwellStartTime + secQuickClick - elapsedSeconds) / secQuickClick;
                changeSize(_ratio);
                mouseCodition = CLICKTIMER;
            }
            else
            {
                resetPointer();
                MouseInput();
            }
        }

    }
    else // big moving now
    {
        mouseCodition = IDLEMOUSE;
        resetPointer();
    }

}



void MouseWidget::quickSmileDetecting(bool detect)
{
    if(actionLocked) return;

    if (detect) // smiling now
    {
        if (mouseCodition == IDLEMOUSE)
        {
            mouseCodition = STARTTIMER;
            this->setStyleSheet(startTimerStyle);
            changeSize(1.0);
            mouseTimer->start();
        }

        elapsedSeconds = mouseTimer->elapsed()/1000.0;

        if (elapsedSeconds < secQuickClick)
        {
            // countdown
            if(mouseCodition != CLICKTIMER) this->setStyleSheet(clickTimerStyle);
            float _ratio = 1;
            if(elapsedSeconds) _ratio = 1 - elapsedSeconds / secQuickClick;

            //qDebug() << "secQuickClick=" << secQuickClick << " elapsedSeconds=" << elapsedSeconds << " ratio=" << _ratio;
            changeSize(_ratio);
            mouseCodition = CLICKTIMER;
        }
        else
        {
            resetPointer();
            MouseInput();
        }

    }
    else // not smiling now
    {

        resetPointer();
    }


}

void MouseWidget::resetPointer()
{
    mouseTimer->restart();
    if(mouseCodition != IDLEMOUSE)
    {
        mouseCodition = IDLEMOUSE;
        changeSize(1.0);
        setStyleSheet(idleStyle);
    }
}
