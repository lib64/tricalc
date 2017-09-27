#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formula.h"

#include <QDebug>
#include <QTimer>
#include <math.h>

const qreal UNDEFINED = 6.12323e-17;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _A = new Corner(30);
    _B = new Corner(30);
    _C = new Corner(30);

    _scene = new TriangleScene(_A,_B,_C);
    ui->graphicsView->setScene(_scene);

    _scene->addItem(_A);
    _scene->addItem(_B);
    _scene->addItem(_C);

    _B->setPos(0,0);
    _C->setPos(0,100);
    _A->setPos(100,100);

    _scene->update();
    _scene->draw();

    _timer = new QTimer(this);
    _timer->start(10);

    connect(_timer, &QTimer::timeout, this, &MainWindow::updateValues);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValues()
{
    if(_lastA == _A->pos() && _lastB == _B->pos() && _lastC == _C->pos())
    {
        return;
    }

    _lastA = _A->pos();
    _lastB = _B->pos();
    _lastC = _C->pos();

    _scene->draw();

    qreal a = distance(*_B, *_C);
    qreal b = distance(*_A, *_C);
    qreal c = distance(*_A, *_B);

    qreal A = angleA(a,b,c);
    qreal B = angleB(a,b,c);
    qreal C = angleC(a,b,c);

    ui->lineEdit_47->setText(QString::number(a)); // a
    ui->lineEdit_45->setText(QString::number(b)); // b
    ui->lineEdit_46->setText(QString::number(c)); // c

    ui->lineEdit_50->setText(QString::number( A * (180/M_PI)  ) + "°"); // A
    ui->lineEdit_48->setText(QString::number( B * (180/M_PI)  ) + "°"); // B
    ui->lineEdit_49->setText(QString::number( C * (180/M_PI)  ) + "°"); // C

    ui->lineEdit_41->setText(QString::number( _A->x() ));
    ui->lineEdit_44->setText(QString::number( _A->y() ));

    ui->lineEdit_39->setText(QString::number( _B->x() ));
    ui->lineEdit_42->setText(QString::number( _B->y() ));

    ui->lineEdit_40->setText(QString::number( _C->x() ));
    ui->lineEdit_43->setText(QString::number( _C->y() ));

    ui->lineEdit->setText(QString::number(sin(A)));
    ui->lineEdit_4->setText(QString::number((A*(180/M_PI) == 90) ? 0 : cos(A)));
    ui->lineEdit_5->setText((A*(180/M_PI) == 90) ? "Undfined" : QString::number(tan(A)));
    ui->lineEdit_8->setText(QString::number(1/sin(A)));
    ui->lineEdit_6->setText((A*(180/M_PI) == 90) ? "Undfined" : QString::number(1/cos(A)));
    ui->lineEdit_7->setText(QString::number((A*(180/M_PI) == 90) ? 0 : 1/tan(A)));

    ui->lineEdit_29->setText(QString::number(sin(B)));
    ui->lineEdit_27->setText(QString::number((B*(180/M_PI) == 90) ? 0 : cos(B)));
    ui->lineEdit_28->setText((B*(180/M_PI) == 90) ? "Undfined" : QString::number(tan(B)));
    ui->lineEdit_32->setText(QString::number(1/sin(B)));
    ui->lineEdit_30->setText((B*(180/M_PI) == 90) ? "Undfined" : QString::number(1/cos(B)));
    ui->lineEdit_31->setText(QString::number((B*(180/M_PI) == 90) ? 0 : 1/tan(B)));

    ui->lineEdit_35->setText(QString::number(sin(C)));
    ui->lineEdit_33->setText(QString::number( (C*(180/M_PI) == 90) ? 0 : cos(C) ));
    ui->lineEdit_34->setText((C*(180/M_PI) == 90) ? "Undfined" : QString::number(tan(C)));
    ui->lineEdit_38->setText(QString::number(1/sin(C)));
    ui->lineEdit_36->setText((C*(180/M_PI) == 90) ? "Undfined" : QString::number(1/cos(C)));
    ui->lineEdit_37->setText(QString::number((C*(180/M_PI) == 90) ? 0 : 1/tan(C)));
}
