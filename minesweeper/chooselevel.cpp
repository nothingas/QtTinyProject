#include "chooselevel.h"
#include "ui_chooselevel.h"

ChooseLevel::ChooseLevel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseLevel)
{
    ui->setupUi(this);
}

ChooseLevel::~ChooseLevel()
{
    delete ui;
}

void ChooseLevel::on_pushButton_clicked()
{
    this->done(0);
}



void ChooseLevel::on_pushButton_2_clicked()
{
    this->done(1);
}


void ChooseLevel::on_pushButton_3_clicked()
{
    this->done(2);
}


void ChooseLevel::on_pushButton_4_clicked()
{
    this->done(3);
}

