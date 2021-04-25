#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    dim_x = dim_y = dim_z = INITIAL_DIMENSIONS;
    plano = INITIAL_LAYER;
    r = g = b = INITITAL_COLOR;
    a = INITIAL_ALPHA;
    escultura = new Sculptor(dim_x, dim_y, dim_z);

}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());

    int voxel_x = width()/dim_x;
    int voxel_y = height()/dim_y;

    for(int i=0; i < dim_x; i++){
        painter.drawLine(i*voxel_x, 0, i*voxel_x, height());
    }
    for(int i=0; i < dim_y; i++){
        painter.drawLine(0, i*voxel_y, width(), i*voxel_y);
    }

    for(int i=0; i < dim_x; i++){
        for(int j=0; j < dim_y; j++){

            Voxel atual = escultura->getVoxelState(i,j,plano);

            if(atual.isOn==true){
                brush.setColor(QColor(int (atual.r*255), (atual.g*255), (atual.b*255), (atual.a*255)));
                painter.setBrush(brush);
                painter.drawRect(i*voxel_x,j*voxel_y,voxel_x,voxel_y);
            }
        }
    }
}

void Plotter::mousePressEvent(QMouseEvent *event){
    int voxel_x = event->x()/(width()/dim_x);
    int voxel_y = event->y()/(height()/dim_y);
    escultura->setColor((float)r/100,(float)g/100,(float)b/100, (float)a/100);
    escultura->putVoxel(voxel_x,voxel_y,plano);
    repaint();
}

void Plotter::setRColor(int _r){
    r = _r;
}

void Plotter::setGColor(int _g){
    g = _g;
}

void Plotter::setBColor(int _b){
    b = _b;
}

void Plotter::setAlpha(int _a){
    a = _a;
}

void Plotter::setPlano(int _plano){
    plano = _plano;
    repaint();
}

void Plotter::runWriteOFF(){
    escultura->writeOFF((char*)"/home/jpfcabral/UFRN/escultura.off");
}
