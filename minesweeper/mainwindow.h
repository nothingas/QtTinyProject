#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "tblock.h"
#include <QEvent>
#include <QMouseEvent>
#include "chooselevel.h"
#include <QGraphicsScene>
#include <QEvent>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int maxrow, maxcolumn,countmine,countinvisible;
private:
    Ui::MainWindow *ui;

    QList<QList<TBlock *>> mapgenerated();
    QList<QList<TBlock *>> map;
    int gamelevel;
    QGraphicsScene *scene;

    void sceneset();
    int chooselevel();
    void gameover();
    void checkforwin(TBlock* block);
    void sizeset(int level);

    void leftclicked(int x, int y);
    void rightclicked(int x, int y);

    void showlose();
    void showwin();
protected:
    void mousePressEvent(QMouseEvent *event);
public:
private slots:

};
#endif // MAINWINDOW_H
