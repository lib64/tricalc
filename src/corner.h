/* 
 * Copyright (c) 2018-2019, Michael Harper
 * 
 * See LICENSE for licensing information */

#ifndef CORNER_H
#define CORNER_H

#include <QGraphicsObject>

class Corner : public QGraphicsItem
{
    qreal _radius;
public:
    Corner(qreal radius);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal radius() const;
};


#endif // CORNER_H
