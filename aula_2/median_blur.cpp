#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv; 

int main()
{ 
  Mat_<unsigned char> a;
  a = imread("fever-2.pgm",0);
  Mat_<unsigned char> b; 
  medianBlur(a,b,11);
  imwrite("fever-2-medianBlur.jpg",b);
}