#include "cutbox.h"

CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a){
    x0 = _x0;
    x1 = _x1;
    y0 = _y0;
    y1 = _y1;
    z0 = _z0;
    z1 = _z1;
    r  = _r;
    g  = _g;
    b  = _b;
    a  = _a;
}

CutBox::~CutBox(){

}

void CutBox::draw(Sculptor &t){
    t.setColor(r, g, b, a);
    for(int x=x0; x<=x1; x++){
        for(int y=y0; y<=y1; y++){
            for(int z=z0; z<=z1; z++){
                t.cutVoxel(x,y,z);
            }
        }
    }
}
