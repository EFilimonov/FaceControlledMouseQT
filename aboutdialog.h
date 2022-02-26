#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();
    void retranslateDialogUi();

private:
    Ui::AboutDialog *ui;

public:
    QLabel *aboutLabel;
    QString aboutText = tr("<p align='justify'>"
                       "Version 1.0.2<br>"
                       "Face Controlled Mouse (C) is a free mouse replacement software. "
                       "You will be able to control your computer without using your hands. "
                       "Face Controlled Mouse uses a standard web camera to track your face "
                       "motion and move the mouse pointer accordingly.<br>"
                       "It also provides several methods for clicking (dwell or smile). "
                       "It works on standard PCs equipped with a web camera. "
                       "No additional hardware is required.<br>"
                       "Pointer speed, motion acceleration and smoothness, dwelling time, "
                       "and many other variables can be adjusted to fit the user's needs.<br>"
                       "License: Face Controlled Mouse released under the BY-NC-SA (non-commercial "
                       "Attribution-Share-Alike) license.<br>"
                       "Authors: Eugene Filimonov (development), Julia Reutskaya "
                       "(adaptation for children with special needs).<br>"
                       "Face Controlled Mouse (C) 2022, <br>"
                       "<a href='https://www.facebook.com/filimonov.evg'>Eugene Filimonov,</a><br>"
                       "<a href='https://preability.com/face-controlled-mouse/'>preAbility.com,</a><br>"
                       "<a href='https://github.com/EFilimonov/FaceControlledMouse'>github</a></p>"
                       );
};

#endif // ABOUTDIALOG_H
