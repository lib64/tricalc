/* 
 * Copyright (c) 2018-2019, Michael Harper
 * 
 * See LICENSE for licensing information */

#include "corner.h"
#include "math.h"
#include <QPainter>

qreal Corner::radius() const
{
    return _radius;
}

Corner::Corner(qreal radius)
{
    _radius = radius;
    setFlags(QGraphicsItem::ItemIsMovable);
}

QRectF Corner::boundingRect() const
{
    return QRectF(0,0,_radius*2, _radius*2);
}

void Corner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush(Qt::black);
    painter->setBrush(brush);
    painter->drawEllipse(0, 0, static_cast<int>(_radius), static_cast<int>(_radius));

}
