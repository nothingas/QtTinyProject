#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "tblock.h"
#include <QEvent>
#include <QMouseEvent>
#include "chooselevel.h"
#include <QGraphicsScene>
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
    int maxrow, maxcolumn,countmine;
private:
    Ui::MainWindow *ui;

    QList<QList<TBlock *>> mapgenerated(int level);
    QList<QList<TBlock *>> map;
    int gamelevel;
    QGraphicsScene *scene;

    void sceneset();
    int chooselevel();
    void gameover();
    void checkforwin(TBlock* block);
    void sizeset(int level);
public:
    void mousePressEvent(QEvent* event);
};
#endif // MAINWINDOW_H
