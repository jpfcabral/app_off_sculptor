#include "putellipsoid.h"


PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx      = _rx;
    ry      = _ry;
    rz      = _rz;
    r       = _r;
    g       = _g;
    b       = _b;
    a       = _a;
    }

PutEllipsoid::~PutEllipsoid(){

}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);

    for(int x=(xcenter-rx); x<(xcenter+rx); x++){
        for(int y=(ycenter-ry); y<(ycenter+ry); y++){
            for(int z=(zcenter-rz); z<(zcenter+rz); z++){
                float t1 = ((float)(x-xcenter)/(float)rx)*((float)(x-xcenter)/(float)rx);
                float t2 = ((float)(y-ycenter)/(float)ry)*((float)(y-ycenter)/(float)ry);
                float t3 = ((float)(z-zcenter)/(float)rz)*((float)(z-zcenter)/(float)rz);
//                cout << t1 << " = " << x << " - "  << xcenter << " / " << rx <<  endl;

                if(t1+t2+t3<=1.0){
                    t.putVoxel(x,y,z);
//                    cout << t1 << " " << t2 << " "  << t3 << endl;
                }
            }
        }
    }
}
