#include "cutvoxel.h"

CutVoxel::CutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a){
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

CutVoxel::~CutVoxel(){

}

void CutVoxel::draw(Sculptor &t){
    t.cutVoxel(x, y, z);
}
