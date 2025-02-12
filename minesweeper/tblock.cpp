#include "tblock.h"
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QDebug>
TBlock::TBlock(QGraphicsItem* parent):QGraphicsItem(parent) {

}

TBlock::~TBlock(){}

const int l = 30;
QRectF TBlock::boundingRect() const
{
    QRectF rect(-1*l/2,-1*l/2,l,l);
    qDebug("%s","in boundingrect");
    return rect;
}

void TBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    QBrush brush;
    brush.setColor(Qt::blue);
    painter->setPen(pen);
    painter->setBrush(brush);
    qDebug("%s","in painter1");
    switch(this->state)
    {
    case 0:
        painter->drawRect(-1*l/2,-1*l/2,l,l);
        //case 0,invisible

        break;
    case 1:
        //case 1,flaged
        break;
    case 2:
        //case 2,visible
        break;
    };
    qDebug("%s","in painter2");
}
