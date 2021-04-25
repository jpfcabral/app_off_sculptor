#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel : public FiguraGeometrica{
    protected:
        int x, y, z;
        float r, g, b, a;
    public:
        CutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
        ~CutVoxel();
        void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
