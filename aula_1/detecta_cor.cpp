//elefante_am.cpp grad-2018
#include <cekeikon.h>
int main() {
 Mat_<COR> a;
 le(a,"elefante.jpg");
 Mat_<COR> b;
 COR amarelo(20,200,200);
 //b=a; // Esta errado. b e a sao dois nomes para mesma imagem.
 b=a.clone(); // OU a.copyTo(b); Aqui temos duas imagens diferentes.
 for (int l=0; l<a.rows; l++)
 for (int c=0; c<a.cols; c++)
 if (distancia(amarelo,a(l,c))<70)
 b(l,c)=COR(255,255,255);
 imp(b,"elefante_am.png");
}