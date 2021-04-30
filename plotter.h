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
    int box_dim_x, box_dim_y, box_dim_z;
    int rx, ry, rz, raio;
    Sculptor *escultura;
    int plano;
    int acao = 0;

public slots:
    void AtualizaDim();
    void setDimX(int _dimx);
    void setDimY(int _dimy);
    void setDimZ(int _dimz);

    void setRColor(int _r);
    void setGColor(int _g);
    void setBColor(int _b);
    void setAlpha(int _a);
    void setPlano(int _plano);

    void setPutVoxel();
    void setCutVoxel();

    void setPutBox();
    void setCutBox();
    void setBoxDimX(int _x);
    void setBoxDimY(int _y);
    void setBoxDimZ(int _z);

    void setPutEllipse();
    void setCutEllipse();
    void setEllipseRX(int _rx);
    void setEllipseRY(int _ry);
    void setEllipseRZ(int _rz);

    void setPutSphere();
    void setCutSphere();
    void setRaio(int _r);

    void runWriteOFF();
signals:

};

#endif // PLOTTER_H
