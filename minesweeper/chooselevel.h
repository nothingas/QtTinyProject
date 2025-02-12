#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QDialog>

namespace Ui {
class ChooseLevel;
}

class ChooseLevel : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseLevel(QWidget *parent = nullptr);
    ~ChooseLevel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ChooseLevel *ui;
};

#endif // CHOOSELEVEL_H
