#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv; 

int main()
{ 
  Mat_<unsigned char> a;
  a = imread("lennag.jpg",0);
  Mat_<unsigned char> b; 
  blur(a,b,Size(3,3));
  imwrite("lennag_mediamov_func_cv2.jpg",b);
}