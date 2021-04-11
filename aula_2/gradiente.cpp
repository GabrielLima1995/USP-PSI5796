//gradiente.cpp - pos2014
#include <cekeikon.h>
void grad(Mat_<FLT> ent, Mat_<FLT>& saix, Mat_<FLT>& saiy)
{ Mat_<FLT> mx=(Mat_<FLT>(3,3)<<-3.0, 0.0, +3.0,
 -10.0, 0.0, +10.0,
 -3.0, 0.0, +3.0);
 mx=mx/16.0;
 Mat_<FLT> my=(Mat_<FLT>(3,3)<<-3.0, -10.0, -3.0,
 0.0, 0.0, 0.0,
 +3.0, +10.0, +3.0);
 my=my/16.0;
 saix=filtro2d(ent,mx);
 saiy=filtro2d(ent,my);
}
int main() {
 Mat_<FLT> ent; le(ent,"fantom.pgm");
 Mat_<FLT> saix;
 Mat_<FLT> saiy;
 grad(ent,saix,saiy);
 Mat_<FLT> t;
 t=0.5+saix; imp(t,"gradx.png");
 t=0.5+saiy; imp(t,"grady.png");
 Mat_<FLT> modgrad=raiz(elev2(saix)+elev2(saiy));
 imp(modgrad,"modgrad.png");
}