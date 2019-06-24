/* 
 * Copyright (c) 2018-2019, Michael Harper
 * 
 * See LICENSE for licensing information */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>

#include "corner.h"
#include "trianglescene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TriangleScene *_scene;
    Corner *_A;
    Corner *_B;
    Corner *_C;
    QPointF _lastA, _lastB, _lastC;
    bool changed;
    QTimer * _timer;

private slots:

    void updateValues();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_lineEdit_41_returnPressed();
    void on_lineEdit_44_returnPressed();
    void on_lineEdit_39_returnPressed();
    void on_lineEdit_42_returnPressed();
    void on_lineEdit_40_returnPressed();
    void on_lineEdit_43_returnPressed();
};

#endif // MAINWINDOW_H
