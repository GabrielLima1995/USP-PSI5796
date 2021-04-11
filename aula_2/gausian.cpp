//gaussian.cpp pos2021
#include <cekeikon.h>
int main() {
 Mat_<FLT> a; le(a,"lennag.jpg");
 Mat_<FLT> b;
 GaussianBlur(a,b,Size(3,3),5);
 mostra(b);
}
