#include "tblock.h"
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QDebug>
TBlock::TBlock(QGraphicsItem* parent):QGraphicsItem(parent) {
    setAcceptHoverEvents(true);
}

TBlock::~TBlock(){}

const int l = 30;
QRectF TBlock::boundingRect() const
{
    QRectF rect(-1*l/2,-1*l/2,l,l);
    //qDebug("%s","in boundingrect");
    return rect;
}

QPixmap TBlock::getpic(int s){
    if(s == 9)
    {
        if(isentered){
            QPixmap p(":/pic/images/pshow.png");
            if (p.isNull()) {
                qWarning("Failed to load pshow!");
            }
            return p;
        }
        QPixmap p(":/pic/images/pnormal.png");
        if (p.isNull()) {
            qWarning("Failed to load pnormal!");
        }
        return p;
    }
    /*
    if(s == )
    {
        QPixmap p(":/pic/images/.png");
        if (p.isNull()) {
            qWarning("Failed to load !");
        }
        return p;
    }
    */
    if(s == 1)
    {
        QPixmap p(":/pic/images/p1.png");
        if (p.isNull()) {
            qWarning("Failed to load p1!");
        }
        return p;
    }

    if(s == 2)
    {
        QPixmap p(":/pic/images/p2.png");
        if (p.isNull()) {
            qWarning("Failed to load p2!");
        }
        return p;
    }

    if(s == 3)
    {
        QPixmap p(":/pic/images/p3.png");
        if (p.isNull()) {
            qWarning("Failed to load p3!");
        }
        return p;
    }

    if(s == 4)
    {
        QPixmap p(":/pic/images/p4.png");
        if (p.isNull()) {
            qWarning("Failed to load p4!");
        }
        return p;
    }

    if(s == 5)
    {
        QPixmap p(":/pic/images/p5.png");
        if (p.isNull()) {
            qWarning("Failed to load p5!");
        }
        return p;
    }

    if(s == 6)
    {
        QPixmap p(":/pic/images/p6.png");
        if (p.isNull()) {
            qWarning("Failed to load p6!");
        }
        return p;
    }

    if(s == 7)
    {
        QPixmap p(":/pic/images/p7.png");
        if (p.isNull()) {
            qWarning("Failed to load p7!");
        }
        return p;
    }

    if(s == 8)
    {
        QPixmap p(":/pic/images/p8.png");
        if (p.isNull()) {
            qWarning("Failed to load p8!");
        }
        return p;
    }

    if(s == 0)
    {
        QPixmap p(":/pic/images/pback.png");
        if (p.isNull()) {
            qWarning("Failed to load pback!");
        }
        return p;
    }

    if(s == 10)
    {
        QPixmap p(":/pic/images/pmine.png");
        if (p.isNull()) {
            qWarning("Failed to load pmine!");
        }
        return p;
    }

    if(s == 11)
    {
        QPixmap p(":/pic/images/pflag.png");
        if (p.isNull()) {
            qWarning("Failed to load pflag!");
        }
        return p;
    }
    if(s == 12)
    {
        QPixmap p(":/pic/images/pask.png");
        if (p.isNull()) {
            qWarning("Failed to load pask!");
        }
        return p;
    }
    QPixmap p(":/pic/images/pme.png");
    return p;
}

void TBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    //brush.setColor(Qt::blue);
    painter->setPen(pen);
    //qDebug("%s","in painter1");



    // QPixmap pnormal(":/pic/images/pnormal.png");
    // if (pnormal.isNull()) {
    //     qWarning("Failed to load PNG file!");
    // }



    switch(this->state)
    {
        painter->drawRect(-1*l/2,-1*l/2,l,l);
    case 0:
        painter->drawPixmap(QRect(-1*l/2,-1*l/2,l,l),getpic(9));
        //case 0,invisible
        break;
    case 1:
        painter->drawPixmap(QRect(-1*l/2,-1*l/2,l,l),getpic(11));
        //case 1,flaged
        break;
    case 2:
        painter->drawPixmap(QRect(-1*l/2,-1*l/2,l,l),getpic(mine_count));
        //case 2,visible
        break;
    case 3:
        //case3,mine
        painter->drawPixmap(QRect(-1*l/2,-1*l/2,l,l),getpic(10));
        break;
    case 4:
        //case4,ask
        painter->drawPixmap(QRect(-1*l/2,-1*l/2,l,l),getpic(12));
    };

    //qDebug("%s","in painter2");
}


void TBlock::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    isentered = true;
    this->update();
}

void TBlock::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    isentered = false;
    this->update();
}


