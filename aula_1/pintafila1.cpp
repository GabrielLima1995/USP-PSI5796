//pintafila1.cpp pos-2016
#include <cekeikon.h>
#include <opencv2/opencv.hpp>
#include <queue>
Mat_<COR> pintaAzul
 (Mat_<COR> a, int ls, int cs) {
 Mat_<COR> b=a.clone();
 queue<int> q;
 q.push(ls); q.push(cs); //(1)
 while (!q.empty()) { //(2)
 int l=q.front(); q.pop(); //(3)
 int c=q.front(); q.pop(); //(3)
 if (b(l,c)==COR(255,255,255)) { //(4)
 b(l,c)=COR(255,0,0); //(5)
 q.push(l-1); q.push(c); //6-acima
 q.push(l+1); q.push(c); //6-abaixo
 q.push(l); q.push(c+1); //6-direita
 q.push(l); q.push(c-1); //6-esq 
 imshow("janela",b);
 waitKey(5);
 }
 }
 return b;
}
int main() {
 Mat_<COR> a; le(a,"mickey_reduz.bmp");
 Mat_<COR> b=pintaAzul(a,159,165);
 imp(b,"fila.png");
}
