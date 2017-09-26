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

    painter->drawEllipse(0, 0, _radius, _radius);

}

qreal distance(const Corner &cornerA, const Corner &cornerB)
{
    return sqrt(pow(cornerA.x() - cornerB.x(), 2) +pow(cornerA.y() - cornerB.y(), 2));
}

QPointF midpoint(const Corner &cornerA, const Corner &cornerB)
{
    return QPointF((cornerA.x() + cornerB.x())/2, (cornerA.y() + cornerB.y())/2);
}

qreal angleA(qreal A, qreal B, qreal C)
{
    return acos((pow(B, 2) + pow(C, 2) - pow(A, 2)) / (2 * B * C));
}
qreal angleB(qreal A, qreal B, qreal C)
{
    return acos((pow(C, 2) + pow(A, 2) - pow(B, 2)) / (2 * C * A));
}
qreal angleC(qreal A, qreal B, qreal C)
{
    return acos((pow(A, 2) + pow(B, 2) - pow(C, 2)) / (2 * A * B));
}
