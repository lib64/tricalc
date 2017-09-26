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

qreal distance(const Corner& cornerA, const Corner& cornerB);

QPointF midpoint(const Corner& cornerA, const Corner& cornerB);

qreal angleA(qreal sideA, qreal sideB, qreal sideC);
qreal angleB(qreal sideA, qreal sideB, qreal sideC);
qreal angleC(qreal sideA, qreal sideB, qreal sideC);

#endif // CORNER_H
