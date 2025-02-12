#include "mainwindow.h"
#include "ui_mainwindow.h"

const int l = 30;
const int margin = 15;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gamelevel = chooselevel();
    sizeset(gamelevel);
    sceneset();
    map = mapgenerated(gamelevel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::chooselevel()
{
    ChooseLevel* dialog = new ChooseLevel;
    return dialog->exec();
}
void MainWindow::sizeset(int level){
    switch(level)
    {
    case 0:
        maxrow = 10;
        maxcolumn = 16;
        countmine = 8;
        break;
    case 1:
        maxrow = 14;
        maxcolumn = 20;
        countmine = 12;
        break;
    case 2:
        maxrow = 20;
        maxcolumn = 30;
        countmine = 24;
        break;
    case 3:
        maxrow = 30;
        maxcolumn = 40;
        countmine = 30;
        break;
    }
}

void MainWindow::sceneset()
{
    scene = new QGraphicsScene(-1*l*maxcolumn/2,-1*l*maxrow/2,l*maxcolumn,l*maxrow);
    ui->graphicsView->setScene(scene);
    QRect rect(margin,margin,maxcolumn * l + 2*margin,maxrow * l + 2*margin);
    ui->graphicsView->setGeometry(rect);

    qDebug("%d",maxcolumn);
    this->setMinimumHeight(maxrow * l+4*margin);
    this->setMaximumHeight(maxrow * l+4*margin);
    this->setMinimumWidth(maxcolumn * l+4*margin);
    this->setMaximumWidth(maxcolumn * l+4*margin);
}

QList<QList<TBlock*>> MainWindow::mapgenerated(int level)
{
    QList<QList<TBlock*>> map;
    for(int i=0;i<maxrow;i++)
    {
        QList<TBlock*> list;
        for(int j=0;j<maxcolumn;j++)
        {
            TBlock* block = new TBlock();
            block->setPos(-1*l/2*maxcolumn+l*j+l/2,-1*l/2*maxrow+l*i+l/2);
            list.append(block);
            scene->addItem(block);
        }
        map.append(list);
    }
    return map;
}
