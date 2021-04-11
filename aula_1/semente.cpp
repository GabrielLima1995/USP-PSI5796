//pintafila1.cpp pos-2016
#include <cekeikon.h>
#include <queue>
Mat_<COR> pintaVermelho
 (Mat_<COR> a, int ls, int cs,int t) {
 Mat_<COR> b=a.clone();
 queue<int> q;
 q.push(ls); q.push(cs); //(1)
 while (!q.empty()) { //(2)
 int l=q.front(); q.pop(); //(3)
 int c=q.front(); q.pop(); //(3)
 if (distancia(b(l,c),COR(20,200,200)) < t ) { //(4)
 b(l,c)=COR(0,0,255); //(5)
 q.push(l-1); q.push(c); //6-acima
 q.push(l+1); q.push(c); //6-abaixo
 q.push(l); q.push(c+1); //6-direita
 q.push(l); q.push(c-1); //6-esq 
 }
 }
 return b; 
}
int main() {
 Mat_<COR> a; le(a,"elefante.jpg");
 Mat_<COR> b=pintaVermelho(a,140,120,70);
 imp(b,"elefante_vermelho_semente.jpg");
}
