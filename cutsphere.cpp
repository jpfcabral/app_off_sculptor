#include "cutsphere.h"

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius  = _radius;
    r       = _r;
    g       = _g;
    b       = _b;
    a       = _a;
}

CutSphere::~CutSphere(){

}

void CutSphere::draw(Sculptor &t){
    for(int x=(xcenter-radius); x<(xcenter+radius); x++){
        for(int y=(ycenter-radius); y<(ycenter+radius); y++){
            for(int z=(zcenter-radius); z<(zcenter+radius); z++){
                float x2 = (float)(x-xcenter)*(float)(x-xcenter);
                float y2 = (float)(y-ycenter)*(float)(y-ycenter);
                float z2 = (float)(z-zcenter)*(float)(z-zcenter);
                float r2 = (float)radius*(float)radius;

                if(x2+y2+z2<r2){
                    t.cutVoxel(x,y,z);
                }
            }
        }
    }
}
