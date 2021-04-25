#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"

#define INITIAL_DIMENSIONS 10
#define INITIAL_LAYER 0
#define INITITAL_COLOR 50
#define INITIAL_ALPHA 99


class Plotter : public QWidget{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    int r, g, b, a;
    int dim_x, dim_y, dim_z;
    Sculptor *escultura;
    int plano;

public slots:
    void setRColor(int _r);
    void setGColor(int _g);
    void setBColor(int _b);
    void setAlpha(int _a);
    void setPlano(int _plano);
    void runWriteOFF();
signals:

};

#endif // PLOTTER_H
