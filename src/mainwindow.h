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
    QTimer * _timer;

private slots:

    void updateValues();
};

#endif // MAINWINDOW_H
