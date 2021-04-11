// borda.cpp. grad-2013 
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv; 

int main()
{ Mat_<float> ent= ( Mat_<float>(3,3) << 2,2,2,3,3,3,4,4,4 );
 Mat_<float> ker= ( Mat_<float>(3,3) << 1,1,1,1,1,1,1,1,1 );
 Mat_<float> sai;
 filter2D(ent,sai,-1,ker,Point(-1,-1),0,BORDER_DEFAULT);
 cout << sai << endl;
}