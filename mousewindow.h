#ifndef MOUSEWINDOW_H
#define MOUSEWINDOW_H

#include <QWidget>

class MouseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MouseWindow(QWidget *parent = nullptr);

signals:

};

#endif // MOUSEWINDOW_H


/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "tracker.h"
#include "facetracker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRead();

private:
    Ui::MainWindow *ui;
    Tracker *tracker;
    FaceTracker *facetracker;
    bool needTrackerInitiate = true;
};
#endif // MAINWINDOW_H

 *
*/
