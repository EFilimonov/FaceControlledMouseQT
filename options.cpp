#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}
