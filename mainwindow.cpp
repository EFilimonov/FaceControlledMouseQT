#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    tracker = new Tracker();

 //   facetracker = new FaceTracker();

 //   facetracker->ptrTracker = tracker;

    od = new OptionsDialog(this);
    ad = new AboutDialog(this);


    hideTimer = new QTimer(this);
    trackerTimer = new QTimer(this);

    process = new QProcess(this);

    ruTranslator = new QTranslator(this);
    ruTranslator->load(":/translations/translation_ru.qm");

    uaTranslator = new QTranslator(this);
    uaTranslator->load(":/translations/translation_ua.qm");

    // connect options dialog

    connect(od->horizontalSpeedSlider, &QSlider::valueChanged, this, [=](int value){tracker->horSensitivity =(float)value/10.0;});
    connect(od->verticalSpeedSlider, &QSlider::valueChanged, this, [=](int value){tracker->verSensitivity =(float)value/10.0;});
    connect(od->accelerationSlider, &QSlider::valueChanged, this, [=](int value){tracker->velocityK =((float)value/10.0)*0.002-0.0014;});
    connect(od->smileAngleSlider, &QSlider::valueChanged, this, [=](int value){tracker->smilingTriggerAngle =value;});
    connect(od->smileAISlider, &QSlider::valueChanged, this, [=](int value){tracker->minNeighborsSmileDetector =value;});
    connect(od->timeToDwellSlider, &QSlider::valueChanged, this, [=](int value){pm->secDwellStartTime =(float)value/10.0;});
    connect(od->dwellDisplacementSlider, &QSlider::valueChanged, this, [=](int value){pm->dwellDisp =(float)value/10.0;});
    connect(od->timeToClickSlider, &QSlider::valueChanged, this, [=](int value){pm->secQuickClick =(float)value/10.0;});
    connect(od->mousePauseSlider, &QSlider::valueChanged, this, [=](int value){pm->pauseTime =(float)value*100.0;});
    // advanced tab
    connect(od->flipCheckBox, &QCheckBox::clicked, this, [=](bool value){tracker->flipCameraFlag = value;});
    connect(od->mouseClickBox, &QCheckBox::clicked, this, [=](bool value){pm->playSoundFlag = value;});
    connect(od->equalizeCheckBox, &QCheckBox::clicked, this, [=](bool value){tracker->needEqualize = value;});
    connect(od->autostartCheckBox, &QCheckBox::clicked, this, [=](bool value){needAutostart = value;});
    connect(od->faceFPSSlider, &QSlider::valueChanged, this, [=](int value){tracker->faceFPS =value;});
    connect(od->trackerFPSSlider, &QSlider::valueChanged, this, [=](int value){tracker->trackerTimeout = value;});
    connect(od->faceThSlider, &QSlider::valueChanged, this, [=](int value){tracker->minFaceNeighbors =value;});
    connect(od->filtrationSlider, &QSlider::valueChanged, this, [=](int value){
        pm->ewmaAlpha =(float)value/100.0;
        pm->facialFilterX.alpha=(float)value/100.0;
        pm->facialFilterY.alpha=(float)value/100.0;
    });
    connect(od->cellsNumSlider, &QSlider::valueChanged, this, [=](int value){tracker->minDistRatio =value;});
    connect(od->minMarksSlider, &QSlider::valueChanged, this, [=](int value){tracker->minCornersCount =value;});

    connect(od->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT (onOdCancel_clicked()));
    connect(od->buttonBox->button(QDialogButtonBox::Apply), SIGNAL(clicked()), this, SLOT (onOdApply_clicked()));

    connect(od->resetButton, SIGNAL(pressed()), this, SLOT (resetDefaults()));

    connect(od->pathButton, SIGNAL(pressed()), this, SLOT (pathDialog()));

    connect(od->aboutButton, SIGNAL(pressed()), this, SLOT (aboutDialog()));

    connect(od->pathLineEdit, SIGNAL(textEdited(QString)), this, SLOT (pathTextChanged(QString)));



    ///////////////////////////////////////////////////
    // initialization
    connect(ui->geoSmileButton, SIGNAL(pressed()), this, SLOT (onGeoSmileButton_pressed()));
    connect(ui->aiSmileButton, SIGNAL(pressed()), this, SLOT (onAISmileButton_pressed()));
    connect(ui->dwellButton, SIGNAL(pressed()), this, SLOT (onDwellButton_pressed()));
    connect(ui->click1Button, SIGNAL(pressed()), this, SLOT (onClick1Button_pressed()));
    connect(ui->stopButton, SIGNAL(pressed()), this, SLOT (onStopButton_pressed()));
    connect(ui->click2Button, SIGNAL(pressed()), this, SLOT (onClick2Button_pressed()));
    connect(ui->clickRButton, SIGNAL(pressed()), this, SLOT (onClickRButton_pressed()));
    connect(ui->clickDButton, SIGNAL(pressed()), this, SLOT (onClickDButton_pressed()));
    connect(ui->optionsButton, SIGNAL(clicked()), this, SLOT (onOptionsButton_clicked()));
    connect(ui->appButton, SIGNAL(pressed()), this, SLOT (onAppButton_pressed()));
    connect(ui->hideButton, SIGNAL(pressed()), this, SLOT (onHideButton_pressed()));
    connect(ui->exitButton, SIGNAL(pressed()), this, SLOT (onExitButton_pressed()));


    connect(tracker, SIGNAL(checkStart()), this, SLOT (underStartButton()));



#ifdef Q_OS_WIN32
QString pf =  qApp->applicationDirPath() + "/";
std::string sPathToFolder = pf.toLocal8Bit().constData();
#endif

#ifdef Q_OS_MAC
QString pf =  qApp->applicationFilePath();
QString toReplace = "MacOS/" + QFileInfo(QCoreApplication::applicationFilePath()).fileName();
pf.replace(toReplace, "MacOS/");
std::string sPathToFolder = pf.toStdString();
#endif

std::string cascadeName = sPathToFolder +"haarcascade_frontalface_alt2.xml";
tracker->loadedFrontalfaceModelFlag =  tracker->frontalFaceDetector.load(cascadeName);

    if (! tracker->loadedFrontalfaceModelFlag)
    {
        QMessageBox::critical(this,
                              tr("Model loading error"),
                              tr("Please, add haarcascade_frontalface_alt2.xml file to the program folder"));
        return;
    }


    cascadeName = sPathToFolder + "haarcascade_smile.xml";
tracker->loadedSmileModelFlag = tracker->smileDetector.load(cascadeName);
    //    tracker->loadedSmileModelFlag = tracker->smileDetector.load("/Users/admin/projects/build-FaceControlledMouse-Qt_6_2_3_for_macOS-Release/haarcascade_smile.xml");
    if (! tracker->loadedSmileModelFlag)
    {
        QMessageBox::critical(this,
                              tr("Model loading error"),
                              tr("Please, add haarcascade_smile.xml file to the program folder"));
        return;
    }

    // Create an instance of Facemark
    tracker->facemark = cv::face::FacemarkLBF::create();

    // Load landmark detector
tracker->facemark->loadModel(sPathToFolder + "lbfmodel.yaml");
    //    tracker->facemark->loadModel("/Users/admin/projects/build-FaceControlledMouse-Qt_6_2_3_for_macOS-Release/lbfmodel.yaml");
    tracker->loadedFacemarkModelFlag = ! tracker->facemark->empty();
    if (! tracker->loadedFacemarkModelFlag)
    {

        //bool openFlag = false;
        QMessageBox::critical(this,
                              tr("Model loading error"),
                              tr("Please, add lbfmodel.yaml file to the program folder"));
        return;
    }


    if (needTrackerInitiate) tracker->initiateTracker();

    needTrackerInitiate = false;



    hideTimer->setInterval(500);
    hideTimer->connect(hideTimer, SIGNAL(timeout()), this, SLOT(hideWithDelay()));

    cv::setNumThreads(1);

    ///////////////////////////////////////
    /// start thread
    connect(tracker,
            SIGNAL(inDisplay(QPixmap)),
            this,
            SLOT(setVideoPixmap(QPixmap)));

    tracker->start();


    ui->inVideo->setScaledContents( true );
    ui->inVideo->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored);

}



MainWindow::~MainWindow()
{
    serializeData();
    tracker->requestInterruption();
    tracker->wait();

    if(process->isOpen())
        process->close();
    delete ui;
}



void MainWindow::onGeoSmileButton_pressed()
{

    if(!pm->actionLocked && pm->mouseClick == pm->DOUBLE_CL && skipClick)
    {
        skipClick = false;
        return;
    }
    else skipClick = true;

    if (tracker->detectSmileGeoFlag == true && tracker->detectSmileAIFlag == true)
    {
        tracker->detectSmileGeoFlag = false;
        ui->geoSmileButton->setIcon(QIcon(":/images/res/GEO.png"));

        tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));
    }
    else if (tracker->detectSmileGeoFlag == false && tracker->detectSmileAIFlag == true)
    {
        tracker->detectSmileGeoFlag = true;
        ui->geoSmileButton->setIcon(QIcon(":/images/res/GEOp.png"));
        if (tracker->detectDwellFlag)tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));
    }
    else if (tracker->detectSmileGeoFlag == true && tracker->detectSmileAIFlag == false)
    {
        // do nothing
    }
    else if (tracker->detectSmileGeoFlag == false && tracker->detectSmileAIFlag == false)
    {
        tracker->detectSmileGeoFlag = true;
        ui->geoSmileButton->setIcon(QIcon(":/images/res/GEOp.png"));
        if (tracker->detectDwellFlag)tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));
    }
}


void MainWindow::onAISmileButton_pressed()
{
    if(!pm->actionLocked && pm->mouseClick == pm->DOUBLE_CL && skipClick)
    {
        skipClick = false;
        return;
    }
    else skipClick = true;

    if (tracker->detectSmileAIFlag == true && tracker->detectSmileGeoFlag == true)
    {
        tracker->detectSmileAIFlag = false;
        ui->aiSmileButton->setIcon(QIcon(":/images/res/AI.png"));

        tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));

    }
    else if (tracker->detectSmileAIFlag == false && tracker->detectSmileGeoFlag == true)
    {
        tracker->detectSmileAIFlag = true;
        ui->aiSmileButton->setIcon(QIcon(":/images/res/AIp.png"));

        tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));
    }
    else if (tracker->detectSmileAIFlag == true && tracker->detectSmileGeoFlag == false)
    {
        // do nothing
    }
    else if (tracker->detectSmileAIFlag == false && tracker->detectSmileGeoFlag == false)
    {
        tracker->detectSmileAIFlag = true;
        ui->aiSmileButton->setIcon(QIcon(":/images/res/AIp.png"));

        tracker->detectDwellFlag = false;
        ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));
    }

}



void MainWindow::onDwellButton_pressed()
{

    if (!tracker->detectDwellFlag)
    {
        tracker->detectDwellFlag = true;
        tracker->detectSmileAIFlag = false;
        tracker->detectSmileGeoFlag = false;

        ui->dwellButton->setIcon(QIcon(":/images/res/dwellp.png"));
        ui->aiSmileButton->setIcon(QIcon(":/images/res/AI.png"));
        ui->geoSmileButton->setIcon(QIcon(":/images/res/GEO.png"));

    }
}



void MainWindow::onStopButton_pressed()
{
    if(!pm->actionLocked && pm->mouseClick == pm->DOUBLE_CL && skipClick)
    {
        skipClick = false;
        return;
    }
    else skipClick = true;



    if(tracker->buttonStop)
    {
        ui->stopButton->setIcon(QIcon(":/images/res/pause.png"));
        //        ui->stopButton->setGraphicsEffect(effect);
        ui->stopButton->setStyleSheet("");

    }
    else
    {
        ui->stopButton->setIcon(QIcon(":/images/res/play.png"));
        ui->stopButton->setStyleSheet(
                    "QPushButton {background-color: rgb(255,102,0); }"
                    "QPushButton:hover {background-color: green; }");
    }

    tracker->buttonStop = !tracker->buttonStop;
}



void MainWindow::onClick1Button_pressed()
{
   // qDebug() << "click1";
    pm->mouseClick = pm->ONE_CL;
    ui->click1Button->setIcon(QIcon(":/images/res/click1p.png"));
    ui->click2Button->setIcon(QIcon(":/images/res/click2.png"));
    ui->clickRButton->setIcon(QIcon(":/images/res/clickR.png"));
    ui->clickDButton->setIcon(QIcon(":/images/res/drag.png"));
}


void MainWindow::onClick2Button_pressed()
{
    //    qDebug() << "click2";
    pm->mouseClick = pm->DOUBLE_CL;
    ui->click1Button->setIcon(QIcon(":/images/res/click1.png"));
    ui->click2Button->setIcon(QIcon(":/images/res/click2p.png"));
    ui->clickRButton->setIcon(QIcon(":/images/res/clickR.png"));
    ui->clickDButton->setIcon(QIcon(":/images/res/drag.png"));
}


void MainWindow::onClickRButton_pressed()
{
    pm->mouseClick = pm->RIGHT_CL;
    ui->click1Button->setIcon(QIcon(":/images/res/click1.png"));
    ui->click2Button->setIcon(QIcon(":/images/res/click2.png"));
    ui->clickRButton->setIcon(QIcon(":/images/res/clickRp.png"));
    ui->clickDButton->setIcon(QIcon(":/images/res/drag.png"));

}


void MainWindow::onClickDButton_pressed()
{
    pm->mouseClick = pm->DRAG;
    ui->click1Button->setIcon(QIcon(":/images/res/click1.png"));
    ui->click2Button->setIcon(QIcon(":/images/res/click2.png"));
    ui->clickRButton->setIcon(QIcon(":/images/res/clickR.png"));
    ui->clickDButton->setIcon(QIcon(":/images/res/dragp.png"));
}


void MainWindow::onOptionsButton_clicked()
{
    if(od->isHidden())
    {
        initiateOptionsDialog();
        od->show();
        saveForCancel();
    }
    else od->hide();
    //   tracker->smilingTriggerAngle = 110.0;
}



void MainWindow::onHideButton_pressed()
{

    if(!pm->actionLocked && pm->mouseClick == pm->DOUBLE_CL && skipClick)
    {
        skipClick = false;
        return;
    }
    else skipClick = true;


    if (tracker->showVideoFlag)
    {
        ui->inVideo->hide();
        ui->hideButton->setIcon(QIcon(":/images/res/show.png"));
        hideTimer->start();
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        show();
    }
    else
    {
        ui->inVideo->show();
        ui->hideButton->setIcon(QIcon(":/images/res/hide.png"));
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        resize(width(), savedHeight);
        show();
    }
    tracker->showVideoFlag = !tracker->showVideoFlag;

}


void MainWindow::onExitButton_pressed()
{
    //    serializeData();
    close();
}


void MainWindow::hideWithDelay()
{
    savedHeight = height();
    resize(width(), 98);
    hideTimer->stop();
}




void MainWindow::underStartButton()
{
    //qDebug() <<pm->mouseTimer->elapsed();

    if (ui->stopButton->rect().contains(ui->stopButton->mapFromGlobal(QCursor::pos())))
    {
        emit tracker->cursorDisplacement(0);
        needResetMouseCondition = true;
    }
    else
    {
        if(needResetMouseCondition)
        {
            pm->resetPointer();
            needResetMouseCondition = false;
        }
    }
}


void MainWindow::setVideoPixmap(QPixmap qp)
{
    ui->inVideo->setPixmap(qp);
}

void MainWindow::FsmileAngleSlider(int val)
{
    tracker->smilingTriggerAngle = val;
}



void MainWindow::serializeData()
{ 
    QFile file("parameters.bin");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream saveStream(&file);

        saveStream << (QString) pathToApp;
        saveStream << tracker->horSensitivity;
        saveStream << tracker->verSensitivity;
        saveStream << tracker->velocityK;
        saveStream << (qint32)tracker->smilingTriggerAngle;
        saveStream << (qint32)tracker->minNeighborsSmileDetector;
        saveStream << pm->secDwellStartTime;
        saveStream << pm->dwellDisp;
        saveStream << pm->secQuickClick;
        saveStream << pm->pauseTime;
        saveStream << tracker->flipCameraFlag;
        saveStream << tracker->needEqualize;
        saveStream << pm->playSoundFlag;
        saveStream << tracker->showVideoFlag;
        saveStream << tracker->detectSmileGeoFlag;
        saveStream << tracker->detectSmileAIFlag;
        saveStream << tracker->detectDwellFlag;
        saveStream << (qint32) tracker->faceFPS;
        saveStream << (qint32) tracker->trackerTimeout;
        saveStream << pm->ewmaAlpha;
        saveStream << (qint32)tracker->minFaceNeighbors;
        saveStream << tracker->minDistRatio;
        saveStream << tracker->minCornersCount;
        saveStream << (qint32)language;
        saveStream << needAutostart;
        saveStream << tracker->cameraIndex;

        if(saveStream.status() != QDataStream::Ok)
        {
            QMessageBox::critical(this,
                                  tr("Write error"),
                                  tr("Can't save data"));
        }
    }
    file.close();
}

void MainWindow::readSerialized(QString fString)
{
    QFile file(fString);
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream readf(&file);
        readf >> pathToApp;//  t;//
        readf >> tracker->horSensitivity;
        readf >> tracker->verSensitivity;
        readf >> tracker->velocityK;
        readf >> tracker->smilingTriggerAngle;
        readf >> tracker->minNeighborsSmileDetector;
        readf >> pm->secDwellStartTime;
        readf >> pm->dwellDisp;
        readf >> pm->secQuickClick;
        readf >> pm->pauseTime;
        readf >> tracker->flipCameraFlag;
        readf >> tracker->needEqualize;
        readf >> pm->playSoundFlag;
        readf >> tracker->showVideoFlag;
        readf >> tracker->detectSmileGeoFlag;
        readf >> tracker->detectSmileAIFlag;
        readf >> tracker->detectDwellFlag;
        readf >> tracker->faceFPS;
        readf >> tracker->trackerTimeout;
        readf >> pm->ewmaAlpha;
        readf >> tracker->minFaceNeighbors;
        readf >> tracker->minDistRatio;
        readf >> tracker->minCornersCount;
        readf >> language;
        readf >> needAutostart;
        readf >> tracker->cameraIndex;
        if(readf.status() != QDataStream::Ok)
        {
            QMessageBox::critical(this,
                                  tr("Read error"),
                                  tr("Can't read data"));
        }

    }
    file.close();

            //tracker->trackerTimeout = (int) 1000/(float)trackerFPS;
            //tracker->facetrackerTimeout = (int) 1000/(float)faceFPS;

    //qDebug() << "cameraIndex " << cameraIndex;/**/
}

void MainWindow::initiateDialogs()
{
    ///////////////////////////////////////////////////

    tracker->cap.open(tracker->cameraIndex);
    if (!tracker->cap.isOpened()) tracker->cameraIndex = 0;
    tracker->cap.open(tracker->cameraIndex);

    if (!tracker->cap.isOpened())
    {
        tracker->cap.release();
        QMessageBox::critical(this,
                              tr("Camera error"),
                              tr("Please, connect your webcam"));
        exit(0);
    }


    // set icons

    if(tracker->detectSmileGeoFlag) ui->geoSmileButton->setIcon(QIcon(":/images/res/GEOp.png"));
    else ui->geoSmileButton->setIcon(QIcon(":/images/res/GEO.png"));

    if(tracker->detectSmileAIFlag) ui->aiSmileButton->setIcon(QIcon(":/images/res/AIp.png"));
    else ui->aiSmileButton->setIcon(QIcon(":/images/res/AI.png"));

    if(tracker->detectDwellFlag) ui->dwellButton->setIcon(QIcon(":/images/res/dwellp.png"));
    else ui->dwellButton->setIcon(QIcon(":/images/res/dwell.png"));

    if(!tracker->showVideoFlag)
    {
        ui->inVideo->hide();
        ui->hideButton->setIcon(QIcon(":/images/res/show.png"));
        hideTimer->start();
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        show();
    }

    initiateOptionsDialog();


// to add webcam list in future
// od->webcamComboBox->hide();
// od->webcamLabel->hide();

 const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
 for (const QCameraDevice &cameraDevice : cameras)
 {
     od->webcamComboBox->addItem(cameraDevice.description());
 }
 od->webcamComboBox->setCurrentIndex(tracker->cameraIndex);
 connect(od->webcamComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT (changeCamera(int)));


    QStringList languageComboBoxItems = {"English", "Russian", "Ukrainian"};
    od->languageComboBox->insertItems(language, languageComboBoxItems);
    od->languageComboBox->setCurrentIndex(language);
    connect(od->languageComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT (changeLanguage(int)));

}


void MainWindow::pathDialog()
{
    QString fileName =
            QFileDialog::getOpenFileName(
                this,
                tr("Path to application"),
                QDir::currentPath(),
                tr("Any file") + " (*.*)");
    if(QFile::exists(fileName))
    {
        pathToApp=fileName;
        od->pathLineEdit->setText(fileName);

    }
}

void MainWindow::pathTextChanged(QString newpath)
{
    pathToApp = newpath;
}

void MainWindow::onAppButton_pressed()
{

    if(!pm->actionLocked && pm->mouseClick == pm->DOUBLE_CL && skipClick)
    {
        skipClick = false;
        return;
    }
    else skipClick = true;



    if(pathToApp.size() && !process->isOpen())
    {
        process->setProgram(pathToApp);

        //process->start();

        process->startDetached();

    }

}


void MainWindow::changeLanguage(int index)
{
    switch (index)
    {
    case 0: // English
        qApp->removeTranslator(ruTranslator);
        qApp->removeTranslator(uaTranslator);
        break;
    case 1: // Russian
        qApp->removeTranslator(uaTranslator);
        qApp->installTranslator(ruTranslator);

        break;
    case 2: // Ukrainian
        qApp->removeTranslator(ruTranslator);
        qApp->installTranslator(uaTranslator);
        break;
    }
    ui->retranslateUi(this);
    od->retranslateDialogUi();
    ad->retranslateDialogUi();
    language = index;

}

void MainWindow::changeCamera(int index)
{
    if (index == tracker->cameraIndex) return;
    else
    {
       tracker->cameraIndex = index;
       QMessageBox::warning(this,
                             tr("Camera change"),
                             tr("Please restart the program."));
    }

    /*
    tracker->cap.release();
    tracker->cap.open(index);
    if (tracker->cap.isOpened())
    {
        cameraIndex = index;

    }
    else
    {
        tracker->cap.open(cameraIndex);
        QMessageBox::warning(this,
                              tr("Camera error"),
                              tr("Can't change webcam"));
    }
        //tracker->preTrackingActions();
        tracker->initiateTracker();
        tracker->needToTrackerInit = true;


    if (!tracker->cap.isOpened())
    {

        QMessageBox::critical(this,
                              tr("Camera error"),
                              tr("Please, connect your webcam"));
        exit(0);
    }
*/
}



void MainWindow::onOdCancel_clicked()
{
    //qDebug() << "backUp();";
    backUp();
}

void MainWindow::onOdApply_clicked()
{
    //qDebug() << "saveForCancel();";
    saveForCancel();

}

void MainWindow::saveForCancel()
    {
    _pathToApp = pathToApp;
    _horSensitivity = tracker->horSensitivity;;
    _verSensitivity = tracker->verSensitivity;
    _velocityK = tracker->velocityK;
    _smilingTriggerAngle = tracker->smilingTriggerAngle;
    _minNeighborsSmileDetector = tracker->minNeighborsSmileDetector;
    _secDwellStartTime = pm->secDwellStartTime;;
    _dwellDisp = pm->dwellDisp;
    _secQuickClick = pm->secQuickClick;
    _pauseTime = pm->pauseTime;
    _flipCameraFlag = tracker->flipCameraFlag;
    _needEqualize = tracker->needEqualize;
    _playSoundFlag = pm->playSoundFlag;
    _faceFPS = tracker->faceFPS;
    _trackerFPS = tracker->trackerTimeout;
    _ewmaAlpha = pm->ewmaAlpha;
    _minFaceNeighbors = tracker->minFaceNeighbors;
    _minDistRatio = tracker->minDistRatio;
    _minCornersCount = tracker->minCornersCount;
    }

void MainWindow::backUp()
{
     pathToApp = _pathToApp;
     tracker->horSensitivity = _horSensitivity;
     tracker->verSensitivity = _verSensitivity;
     tracker->velocityK = _velocityK;
     tracker->smilingTriggerAngle = _smilingTriggerAngle;
     tracker->minNeighborsSmileDetector = _minNeighborsSmileDetector;
     pm->secDwellStartTime = _secDwellStartTime;
     pm->dwellDisp = _dwellDisp;
     pm->secQuickClick = _secQuickClick;
     pm->pauseTime = _pauseTime;
     tracker->flipCameraFlag = _flipCameraFlag;
     tracker->needEqualize = _needEqualize;
     pm->playSoundFlag = _playSoundFlag;
     tracker->faceFPS = _faceFPS;
     tracker->trackerTimeout = _trackerFPS;
     pm->ewmaAlpha = _ewmaAlpha;
     tracker->minFaceNeighbors = _minFaceNeighbors;
     tracker->minDistRatio = _minDistRatio;
     tracker->minCornersCount = _minCornersCount;
}


void MainWindow::initiateOptionsDialog()
{
    // main tab
    od->horizontalSpeedSlider->setValue(tracker->horSensitivity * 10);
    od->verticalSpeedSlider->setValue(tracker->verSensitivity * 10);
    od->accelerationSlider->setValue(10*((tracker->velocityK +0.0014)/0.002));
    od->smileAngleSlider->setValue(tracker->smilingTriggerAngle);
    od->smileAISlider->setValue(tracker->minNeighborsSmileDetector);
    od->timeToDwellSlider->setValue(pm->secDwellStartTime*10);
    od->dwellDisplacementSlider->setValue(pm->dwellDisp*10);
    od->timeToClickSlider->setValue(pm->secQuickClick*10);
    od->mousePauseSlider->setValue(pm->pauseTime/100);
    // advanced tab
    od->flipCheckBox->setChecked(tracker->flipCameraFlag);
    od->mouseClickBox->setChecked(pm->playSoundFlag);
    od->equalizeCheckBox->setChecked(tracker->needEqualize);
    od->autostartCheckBox->setChecked(needAutostart);
    //od->languageComboBox
    od->pathLineEdit->setText(pathToApp);
    od->faceFPSSlider->setValue(tracker->faceFPS);
    od->trackerFPSSlider->setValue(tracker->trackerTimeout);
    od->faceThSlider->setValue(tracker->minFaceNeighbors);
    od->filtrationSlider->setValue(pm->ewmaAlpha*100);
    od->cellsNumSlider->setValue(tracker->minDistRatio);
    od->minMarksSlider->setValue(tracker->minCornersCount);

}

void MainWindow::resetDefaults()
{
    readSerialized("defaults.bin");
    changeLanguage(0);
    changeCamera(0);
    od->on_autostartCheckBox_stateChanged(0);
    needAutostart = false;

    initiateOptionsDialog();
}

void MainWindow::aboutDialog()
{

//   ad->aboutLabel->selectedText()
    if(ad->isHidden()) ad->show();
    else ad->hide();


}


