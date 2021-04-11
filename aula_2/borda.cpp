// borda.cpp. grad-2013 
#include <cekeikon.h>
int main()
{ Mat_<FLT> ent= ( Mat_<FLT>(3,3) << 2,2,2,3,3,3,4,4,4 );
 Mat_<FLT> ker= ( Mat_<FLT>(3,3) << 1,1,1,1,1,1,1,1,1 );
 Mat_<FLT> sai;
 filter2D(ent,sai,-1,ker,Point(-1,-1),0,BORDER_DEFAULT);
 cout << sai << endl;
}