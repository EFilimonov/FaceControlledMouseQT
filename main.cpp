#include "mainwindow.h"
#include "mousewidget.h"
#include "optionsdialog.h"

#include <QApplication>

// disable consol output
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main(int argc, char *argv[])
{

#ifdef Q_OS_WIN32

    QApplication* temp = new QApplication(argc, argv);
    QScreen* _screen = QApplication::screens().at(0);
    QSize _MyRect = _screen->size();
    double width = _MyRect.width();
    // assumes that the default desktop resolution is 720p (scale of 1)
    int minWidth = 1920;
    delete temp;
    double scale = width / minWidth;
    std::string scaleAsString = std::to_string(scale);
    QByteArray scaleAsQByteArray(scaleAsString.c_str(), scaleAsString.length());
    qputenv("QT_SCALE_FACTOR", scaleAsQByteArray);

#endif



    QApplication a(argc, argv);




    MainWindow w;
    MouseWidget m;


#ifdef Q_OS_WIN32
        w.setWindowFlags(Qt::WindowCloseButtonHint);
#endif
    w.show();

    w.pm = &m;

    w.readSerialized("parameters.bin");

   // qDebug() << "1 init" << w.language;
    w.initiateDialogs();

   if(w.language)w.changeLanguage(w.language);
   //w.changeCamera(w.cameraIndex);



#ifdef Q_OS_WIN32
    m.setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
#endif

#ifdef Q_OS_MAC
    m.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput);
    m.setAttribute(Qt::WA_TranslucentBackground);
#endif


    m.setAttribute( Qt::WA_TransparentForMouseEvents );
    m.resetPointer();

    QScreen* screen = QApplication::screens().at(0);
    QSize MyRect = screen->size();
    w.tracker->horLimit = (int)MyRect.width();
    w.tracker->vertLimit = (int)MyRect.height();
    m.horLimit = (int)MyRect.width();
    m.vertLimit = (int)MyRect.height();


    m.show();

    m.setAttribute( Qt::WA_QuitOnClose, false );


    // connect tracker and cursor
    MainWindow::connect(w.tracker, SIGNAL(cursorPosition(QPoint)),
                     &m, SLOT(updatePosition(QPoint)));

    // connect dwell and click
    MainWindow::connect(w.tracker, SIGNAL(cursorDisplacement(float)),
                     &m, SLOT(dwellDetecting(float)));

    // connect smile and click
    MainWindow::connect(w.tracker, SIGNAL(quickClickSignal(bool)),
                     &m, SLOT(quickSmileDetecting(bool)));

    // return control to left click after drag&drop or right click
    MainWindow::connect(&m, SIGNAL(returnTo1Click()),
                     &w, SLOT (onClick1Button_pressed()));





    return a.exec();
}
