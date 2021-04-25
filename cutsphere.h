#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica
{
protected:
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    ~CutSphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
