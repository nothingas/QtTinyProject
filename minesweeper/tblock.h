#ifndef TBLOCK_H
#define TBLOCK_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class TBlock : public QGraphicsItem
{
public:
    TBlock(QGraphicsItem* parent = nullptr);
    ~TBlock();
private:
    int state = 0;//3kinds, invisible; flaged; visible, denoted as 0,1,2;
    int mine_count = 0;//nums for mine around
    int row;
    int column;
    bool isMine = false;//whether this is a mine.
public:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget* widget = nullptr) override;
};

#endif // TBLOCK_H
