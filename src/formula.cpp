#include "formula.h"
#include <math.h>

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
