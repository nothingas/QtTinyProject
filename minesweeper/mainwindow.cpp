#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QPoint>
#include <QPointF>
#include <QMessageBox>
const int l = 30;
const int margin = 15;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gamelevel = chooselevel();
    sizeset(gamelevel);
    countinvisible = maxrow*maxcolumn;
    qDebug("countinvisible = %d",countinvisible);
    sceneset();
    map = mapgenerated();
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
        maxcolumn = 10;
        countmine = 12;
        break;
    case 1:
        maxrow = 16;
        maxcolumn = 16;
        countmine = 40;
        break;
    case 2:
        maxrow = 16;
        maxcolumn = 30;
        countmine = 99;
        break;
    case 3:
        maxrow = 30;
        maxcolumn = 30;
        countmine = 250;
        break;
    }
}

void MainWindow::sceneset()
{
    scene = new QGraphicsScene(-1*l*maxcolumn/2,-1*l*maxrow/2,l*maxcolumn,l*maxrow);


    //QRect rect(margin,margin,maxcolumn * l + 2*margin,maxrow * l + 2*margin);
    QRect rect(0,0,maxcolumn * l +4*margin ,maxrow * l +4*margin );
    ui->graphicsView->setGeometry(rect);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(2*margin+l*maxcolumn/2,2*margin+l*maxcolumn/2);

    /*
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawRect(margin,margin,maxcolumn * l + 2*margin,maxrow * l + 2*margin);
    painter.drawRect(2*margin,2*margin,l*maxcolumn,l*maxrow);
    */

    //QBrush brush(Qt::red);
    //scene->setForegroundBrush(brush);


    this->setMinimumHeight(maxrow*l+4*margin);
    this->setMaximumHeight(maxrow*l+4*margin);
    this->setMinimumWidth(maxcolumn*l+4*margin);
    this->setMaximumWidth(maxcolumn*l+4*margin);
}

QList<QList<TBlock*>> MainWindow::mapgenerated()
{
    QList<QList<TBlock*>> map;
    for(int i=0;i<maxrow;i++)
    {
        QList<TBlock*> list;
        for(int j=0;j<maxcolumn;j++)
        {
            TBlock* block = new TBlock();
            block->row = i;block->column = j;
            scene->addItem(block);
            block->setPos(-1*l/2*maxcolumn+l*j+l/2,-1*l/2*maxrow+l*i+l/2);
            list.append(block);
        }
        map.append(list);
    }
    int n = countmine;
    while(n--){
        int x,y;
        x = QRandomGenerator::global()->bounded(maxrow);
        y = QRandomGenerator::global()->bounded(maxcolumn);
        TBlock* block = map[x][y];
        if(block->isMine)n++;
        else{
            block->isMine = true;
            bool xcenture = (x!=0 && x!=maxrow-1);
            bool ycenture = (y!=0 && y!=maxcolumn-1);
            if(xcenture && ycenture){
                map[x-1][y-1]->mine_count++;
                map[x-1][y]->mine_count++;
                map[x-1][y+1]->mine_count++;
                map[x][y-1]->mine_count++;
                map[x][y+1]->mine_count++;
                map[x+1][y-1]->mine_count++;
                map[x+1][y]->mine_count++;
                map[x+1][y+1]->mine_count++;
            }
            else if(ycenture){
                if(x==0){
                    map[0][y-1]->mine_count++;
                    map[0][y+1]->mine_count++;
                    map[1][y-1]->mine_count++;
                    map[1][y]->mine_count++;
                    map[1][y+1]->mine_count++;
                }
                else{
                    map[maxrow-2][y-1]->mine_count++;
                    map[maxrow-2][y]->mine_count++;
                    map[maxrow-2][y+1]->mine_count++;
                    map[maxrow-1][y-1]->mine_count++;
                    map[maxrow-1][y+1]->mine_count++;
                }
            }
            else if(xcenture){
                if(y==0){
                    map[x-1][0]->mine_count++;
                    map[x+1][0]->mine_count++;
                    map[x-1][1]->mine_count++;
                    map[x][1]->mine_count++;
                    map[x+1][1]->mine_count++;
                }
                else{
                    map[x-1][maxcolumn-1]->mine_count++;
                    map[x+1][maxcolumn-1]->mine_count++;
                    map[x-1][maxcolumn-2]->mine_count++;
                    map[x][maxcolumn-2]->mine_count++;
                    map[x+1][maxcolumn-2]->mine_count++;
                }
            }
            else{
                if(x==0 && y==0){
                    map[0][1]->mine_count++;
                    map[1][0]->mine_count++;
                    map[1][1]->mine_count++;
                }
                if(x==0 && y==maxcolumn-1){
                    map[0][maxcolumn-2]->mine_count++;
                    map[1][maxcolumn-2]->mine_count++;
                    map[1][maxcolumn-1]->mine_count++;
                }
                if(x==maxrow-1 && y==0){
                    map[maxrow-2][0]->mine_count++;
                    map[maxrow-2][1]->mine_count++;
                    map[maxrow-1][1]->mine_count++;
                }
                if(x==maxrow-1 && y==maxcolumn-1){
                    map[maxrow-2][maxcolumn-2]->mine_count++;
                    map[maxrow-2][maxcolumn-1]->mine_count++;
                    map[maxrow-1][maxcolumn-2]->mine_count++;
                }
            }
        }
    }
    return map;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QPoint p = event->pos();
    int px = p.x() - 2*margin; int py = p.y()-2*margin;
    int x,y;
    if(px>=0 && px<=l*maxcolumn && py>=0 && py<=l*maxrow){
        x = py/l;y=px/l;
    }
    else{return;}
    if(event->button() == Qt::LeftButton){
        leftclicked(x,y);
    }
    else if(event->button() == Qt::RightButton){
        rightclicked(x,y);
    }
}

void MainWindow::leftclicked(int x, int y){
    TBlock* block = map[x][y];
    if(block->isMine){showlose();return;}
    if(block->state != 0)return;
    countinvisible--;
    qDebug("countinvisible = %d",countinvisible);
    if(countinvisible == countmine)showwin();
    block->state = 2;
    block->update();
    if(block->mine_count == 0){
        for(int i=x-1;i<=x+1;i++){
            for(int j = y-1;j<=y+1;j++){
                if(i>=0 && i<= maxrow-1 && j>=0 && j<=maxcolumn-1){
                    leftclicked(i,j);
                }
            }
        }
    }
}

void MainWindow::rightclicked(int x, int y){
    TBlock* block = map[x][y];
    int s = block->state;
    if(s==0)block->state=1;
    if(s==1)block->state=4;
    if(s==4)block->state=0;
    block->update();
}

void MainWindow::showlose(){
    for(int i=0;i<maxrow;i++){
        for(int j=0;j<maxcolumn;j++){
            if(map[i][j]->isMine){map[i][j]->state = 3; map[i][j]->update();}
        }
    }
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,"You Lose!","Want to try again?",QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::Yes){
        map = mapgenerated();
        for(int i=0;i<maxrow;i++){
            for(int j=0;j<maxcolumn;j++){
                map[i][j]->update();
            }
        }
    }
    if(result == QMessageBox::No){
        this->close();
    }
}

void MainWindow::showwin(){
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,"You Win!","Want to try again?",QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::Yes){
        map = mapgenerated();
        for(int i=0;i<maxrow;i++){
            for(int j=0;j<maxcolumn;j++){
                map[i][j]->update();
            }
        }
    }
    if(result == QMessageBox::No){
        this->close();
    }
}
