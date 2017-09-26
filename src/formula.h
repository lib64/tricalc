#ifndef FORMULA_H
#define FORMULA_H

#include "corner.h"

qreal distance(const Corner& cornerA, const Corner& cornerB);
QPointF midpoint(const Corner& cornerA, const Corner& cornerB);

qreal angleA(qreal sideA, qreal sideB, qreal sideC);
qreal angleB(qreal sideA, qreal sideB, qreal sideC);
qreal angleC(qreal sideA, qreal sideB, qreal sideC);


#endif // FORMULA_H
