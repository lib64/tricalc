#include "trianglescene.h"
#include "formula.h"

TriangleScene::TriangleScene(Corner *A, Corner *B, Corner *C)
{
    setSceneRect(-1000,-1000,2000,2000);


    _A = A;
    _B = B;
    _C = C;

    _a = addLine(_A->x(),_A->y(),_B->x(),_B->y());
    _b = addLine(_A->x(),_A->y(),_B->x(),_B->y());
    _c = addLine(_A->x(),_A->y(),_C->x(),_C->y());

    _labelA = addText("A");
    _labelB = addText("B");
    _labelC = addText("C");

    _labela = addText("a");
    _labelb = addText("b");
    _labelc = addText("c");


    QRect rect = sceneRect().toRect();
    QPen pen(Qt::gray);

    for(int i = rect.x(); i < rect.width(); i += 20)
    {
        QGraphicsLineItem *line = addLine(i, rect.y(), i, rect.height());
        line->setPen(pen);
        _linesY.append(line);
    }

    for(int i = rect.y(); i < rect.height(); i += 20)
    {
        QGraphicsLineItem *line = addLine(rect.x(), i, rect.width(), i);
        line->setPen(pen);
        _linesX.append(line);
    }
}


void TriangleScene::draw()
{
    QPen pen(Qt::black);
    pen.setWidth(2);

    _a->setPen(pen);
    _b->setPen(pen);
    _c->setPen(pen);

    _a->setLine(_A->x()+_A->radius()/2,
                _A->y()+_A->radius()/2,
                _B->x()+_B->radius()/2,
                _B->y()+_B->radius()/2);

    _b->setLine(_B->x()+_B->radius()/2,
                _B->y()+_B->radius()/2,
                _C->x()+_C->radius()/2,
                _C->y()+_C->radius()/2);

    _c->setLine(_A->x()+_A->radius()/2,
                _A->y()+_A->radius()/2,
                _C->x()+_C->radius()/2,
                _C->y()+_C->radius()/2);

    _labelA->setPos(_A->pos());
    _labelB->setPos(_B->pos());
    _labelC->setPos(_C->pos());

    _labelc->setPos( midpoint(*_A, *_B) );
    _labela->setPos( midpoint(*_B, *_C) );
    _labelb->setPos( midpoint(*_C, *_A) );

    _a->update();
    _b->update();
    _c->update();

}
