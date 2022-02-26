#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    aboutLabel = ui->aboutLabel;
    ui->aboutLabel->setOpenExternalLinks(true);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::retranslateDialogUi()
{
    ui->retranslateUi(this);
}
