#include "trianglescene.h"

TriangleScene::TriangleScene(Corner *A, Corner *B, Corner *C)
{
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



}


void TriangleScene::draw()
{
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
