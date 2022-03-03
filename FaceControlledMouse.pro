QT += core gui
QT += widgets
QT += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += core testlib



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AspectRatioLabel.cpp \
    Ewma.cpp \
    aboutdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mousewidget.cpp \
    optionsdialog.cpp \
    tracker.cpp

HEADERS += \
    AspectRatioLabel.h \
    Ewma.h \
    aboutdialog.h \
    mainwindow.h \
    mousewidget.h \
    optionsdialog.h \
    tracker.h \
    tracker.h

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \
    mousewidget.ui \
    optionsdialog.ui

TRANSLATIONS = translation_ru.ts translation_ua.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32: {
include("c:/opencv/buildrelease/opencv.pri")
LIBS += -luser32
}
unix: !macx{
CONFIG += link_pkgconfig
PKGCONFIG += opencv
}
unix: macx{
CONFIG+= staticlib
CONFIG += c++11 app_bundle
QT_CONFIG -= no-pkg-config
#CONFIG-=app_bundle
CONFIG  += link_pkgconfig
PKGCONFIG += opencv4
INCLUDEPATH += /usr/local/include/# depends on how you installed
QMAKE_INFO_PLIST += $${TARGET}/data/default.plist
QMAKE_POST_LINK += sed -i -e "s/@VERSION@/$$VERSION/g" "./$${TARGET}.app/Contents/Info.plist";
QMAKE_MACOSX_DEPLOYMENT_TARGET += -mmacosx-version-min=10.10

}

RESOURCES += \
    resources.qrc

