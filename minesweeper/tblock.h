#ifndef TBLOCK_H
#define TBLOCK_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QPixmap>
#include <QEvent>
class TBlock : public QGraphicsItem
{
public:
    TBlock(QGraphicsItem* parent = nullptr);
    ~TBlock();
    int mine_count = 0;//nums for mine around
    bool isMine = false;//whether this is a mine.
    int state = 0;//0->invisible; 1-> visible; 2->flaged;3->bomb! ;4->ask;
    int row;
    int column;
    bool isentered = false;
private:

    QPixmap getpic(int s);
public:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget* widget = nullptr) override;
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
signals:

};

#endif // TBLOCK_H
