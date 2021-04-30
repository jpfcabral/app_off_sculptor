#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
//    cout << "construtor" << endl;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel **[nx];

    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}

Sculptor::~Sculptor(){
//    cout << "destrutor" << endl;
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j];
        }
    }
    for(int i=0; i<nx; i++){
        delete[] v[i];
    }

    delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _alpha){
    r = _r;
    g = _g;
    b = _b;
    a = _alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x=x0; x<=x1; x++){
        for(int y=y0; y<=y1; y++){
            for(int z=z0; z<=z1; z++){
                putVoxel(x,y,z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x=x0; x<=x1; x++){
        for(int y=y0; y<=y1; y++){
            for(int z=z0; z<=z1; z++){
                cutVoxel(x,y,z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                float x2 = (float)(x-xcenter)*(float)(x-xcenter);
                float y2 = (float)(y-ycenter)*(float)(y-ycenter);
                float z2 = (float)(z-zcenter)*(float)(z-zcenter);
                float r2 = (float)radius*(float)radius;

                if(x2+y2+z2<r2){
                    putVoxel(x,y,z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                float x2 = (float)(x-xcenter)*(float)(x-xcenter);
                float y2 = (float)(y-ycenter)*(float)(y-ycenter);
                float z2 = (float)(z-zcenter)*(float)(z-zcenter);
                float r2 = (float)radius*(float)radius;

                if(x2+y2+z2<=r2){
                    cutVoxel(x,y,z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                float t1 = ((float)(x-xcenter)/(float)rx)*((float)(x-xcenter)/(float)rx);
                float t2 = ((float)(y-ycenter)/(float)ry)*((float)(y-ycenter)/(float)ry);
                float t3 = ((float)(z-zcenter)/(float)rz)*((float)(z-zcenter)/(float)rz);
//                cout << t1 << " = " << x << " - "  << xcenter << " / " << rx <<  endl;

                if(t1+t2+t3<=1.0){
                    putVoxel(x,y,z);
//                    cout << t1 << " " << t2 << " "  << t3 << endl;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                float t1 = ((float)(x-xcenter)/(float)rx)*((float)(x-xcenter)/(float)rx);
                float t2 = ((float)(y-ycenter)/(float)ry)*((float)(y-ycenter)/(float)ry);
                float t3 = ((float)(z-zcenter)/(float)rz)*((float)(z-zcenter)/(float)rz);
    //                cout << t1 << " = " << x << " - "  << xcenter << " / " << rx <<  endl;

                if(t1+t2+t3<=1.0){
                    cutVoxel(x,y,z);
    //                    cout << t1 << " " << t2 << " "  << t3 << endl;
                }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    int total;

    std::ofstream f;
    total = 0;

//    for(int i=1; i<nx-1; i++){
//        for(int j=1; j<ny-1; j++){
//            for(int k=1; k<nz-1; k++){
//                if(v[i+1][j][k].isOn==true && v[i-1][j][k].isOn==true)
//                    v[i][j][k].isOn=false;
//                if(v[i][j+1][k].isOn==true && v[i][j-1][k].isOn==true)
//                    v[i][j][k].isOn=false;
//                if(v[i][j][k+1].isOn==true && v[i][j][k-1].isOn==true)
//                    v[i][j][k].isOn=false;
//            }
//        }
//    }

    f.open(filename);
    if(!f.is_open()){
        std::cout << "deu errado\n";
        exit(0);
    }

    f << "OFF\n";

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){
                    total ++;
                }
            }
        }
    }

    cout << total << endl;

    f << total*8 << " " << total*6 << " 0\n";

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                if(v[x][y][z].isOn==true){
                    f << -0.5 + x << " " <<  0.5 + y << " " << -0.5 + z << "\n";
                    f << -0.5 + x << " " << -0.5 + y << " " << -0.5 + z << "\n";
                    f <<  0.5 + x << " " << -0.5 + y << " " << -0.5 + z << "\n";
                    f <<  0.5 + x << " " <<  0.5 + y << " " << -0.5 + z << "\n";
                    f << -0.5 + x << " " <<  0.5 + y << " " <<  0.5 + z << "\n";
                    f << -0.5 + x << " " << -0.5 + y << " " <<  0.5 + z << "\n";
                    f <<  0.5 + x << " " << -0.5 + y << " " <<  0.5 + z << "\n";
                    f <<  0.5 + x << " " <<  0.5 + y << " " <<  0.5 + z << "\n";
                }
            }
        }
    }

    int counter = 0;

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                if(v[x][y][z].isOn==true){
                    f << 4 << " " << 0+(counter*8) << " " << 3+(counter*8) << " " << 2+(counter*8) << " " << 1+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 4+(counter*8) << " " << 5+(counter*8) << " " << 6+(counter*8) << " " << 7+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 0+(counter*8) << " " << 1+(counter*8) << " " << 5+(counter*8) << " " << 4+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 0+(counter*8) << " " << 4+(counter*8) << " " << 7+(counter*8) << " " << 3+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 3+(counter*8) << " " << 7+(counter*8) << " " << 6+(counter*8) << " " << 2+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 1+(counter*8) << " " << 2+(counter*8) << " " << 6+(counter*8) << " " << 5+(counter*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    counter++;
                }
            }
        }
    }

    f.close();

}

Voxel Sculptor::getVoxelState(int x, int y, int z){
    return v[x][y][z];
}
