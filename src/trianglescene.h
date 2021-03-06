/* 
 * Copyright (c) 2018-2019, Michael Harper
 * 
 * See LICENSE for licensing information */

#ifndef TRIANGLESCENE_H
#define TRIANGLESCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "corner.h"

class TriangleScene : public QGraphicsScene
{
    Corner *_A,*_B,*_C;
    QGraphicsLineItem *_a, *_b, *_c;
    QGraphicsTextItem *_labelA, *_labelB, *_labelC;
    QGraphicsTextItem *_labela, *_labelb, *_labelc;
    QGraphicsPolygonItem *_triangle;
    QVector<QGraphicsLineItem *> _linesX, _linesY;
public:
    TriangleScene(Corner *A, Corner *B, Corner *C);
public slots:
    void draw();

};

#endif // TRIANGLESCENE_H
