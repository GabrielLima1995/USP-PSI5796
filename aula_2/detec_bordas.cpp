#include <opencv2/opencv.hpp>
#include<cekeikon.h>

using namespace std;
using namespace cv; 

int main()
{ 
  // input 
  Mat_<float> a,converted,util;
  Mat_<unsigned char> top,left,right,bottom,top_bottom,left_right;
  a = imread("quadrado.png",0);
  a.convertTo(converted,CV_32FC1,1.0/255.0);
  
  // kernel creation 

  Mat SCHARR_X = (Mat_<float>(3,3) <<
                -3, -10, -3,
                 0,   0,  0,
                +3, +10, +3);
  
  Mat SCHARR_Y = (Mat_<float>(3,3) <<
                -3,   0,  +3,
                -10,  0, +10,
                -3,   0,  +3);

  Mat SCHARR_XX = (Mat_<float>(3,3) <<
                +3, +10, +3,
                 0,   0,  0,
                -3, -10, -3);

  Mat SCHARR_YY = (Mat_<float>(3,3) <<
                +3,   0,  -3,
                +10,  0, -10,
                +3,   0,  -3);

  
  SCHARR_X = (1.0/16.0) * SCHARR_X;
  SCHARR_Y = (1.0/16.0) * SCHARR_Y;
    
  //filtering 
    // top 
 filter2D(converted,util,-1,SCHARR_X,Point(-1,-1),0);
 util.convertTo(top,CV_8UC1,255.0);
 imwrite("quadrado_top.png",top);
   //bottom 
 filter2D(converted,util,-1,SCHARR_XX,Point(-1,-1),0);
 util.convertTo(bottom,CV_8UC1,255.0);
 imwrite("quadrado_bottom.png",bottom);
  // Top + Bottom 
 util=raiz(elev2(top)+elev2(bottom));
 util.convertTo(top_bottom,CV_8UC1,255.0);
 imwrite("quadrado_top__bottom.png",top_bottom);
  // Left 
 filter2D(converted,util,-1,SCHARR_Y,Point(-1,-1),0);
 util.convertTo(left,CV_8UC1,255.0);
 imwrite("quadrado_left.png",left); 
  // Right 
 filter2D(converted,util,-1,SCHARR_YY,Point(-1,-1),0);
 util.convertTo(right,CV_8UC1,255.0);
 imwrite("quadrado_right.png",right); 
  // left + right 
 util=raiz(elev2(left)+elev2(right));
 util.convertTo(left_right,CV_8UC1,255.0);
 imwrite("quadrado_left__right.png",left_right);
 }