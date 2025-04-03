#include "connectsettingform.h"
#include "ui_connectsettingform.h"

connectsettingform::connectsettingform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::connectsettingform)
{
    ui->setupUi(this);
}

connectsettingform::~connectsettingform()
{
    delete ui;
}
