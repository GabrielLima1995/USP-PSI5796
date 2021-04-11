//mediamov.cpp - pos2018
#include <cekeikon.h>
Mat_<GRY> mediamov(Mat_<GRY> a) {
 Mat_<GRY> b(a.rows,a.cols);
 for (int l=0; l<b.rows; l++)
 for (int c=0; c<b.cols; c++) {
 int soma=0;
 int conta=0;
 for (int l2=-1; l2<=1; l2++)
 for (int c2=-1; c2<=1; c2++)
 if (0<=l+l2 && l+l2<a.rows && 0<=c+c2 && c+c2<a.cols) {
 soma = soma+a(l+l2,c+c2);
 conta++;
 }
 b(l,c) = round(double(soma)/double(conta));
 }
 return b;
}
int main() {
 Mat_<GRY> a;
 le(a,"lennag.jpg");
 Mat_<GRY> b=mediamov(a);
 imp(b,"lennag-med.png");
}