#include <cekeikon.h>
int main()
{ Mat_<GRY> a;
 le(a,"mickey.bmp");
 for (unsigned i=0; i<a.total(); i++)
    if (a(i)==255 && a(i) != a(i-1) && a(i) != a(i+1)) a(i)=0;
 imp(a,"mickey_processado.bmp");
}
