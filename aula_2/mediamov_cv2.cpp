#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv; 

Mat_<unsigned char> mediamov(Mat_<unsigned char> a)
{ 
    Mat_<unsigned char> b(a.rows,a.cols);
    for (int l=0;l<b.rows;l++)
        for (int c=0;c<b.cols;c++)
        {
            int soma  =0;
            int conta =0;
            for (int l2=-1;l2<=1;l2++)
                for(int c2=-1;c2 <=1; c2++)
                    if(0<=l+l2 && l+l2 <= a.rows && 0 <= c+c2 && c+c2 < a.cols)
                    {
                        soma = soma +a(l+l2,c+c2);
                        conta++;
                    }
                    b(l,c)=round(double(soma)/double(conta));
        }
    return b;
}

int main()
{ 
  Mat_<unsigned char> a;
  a = imread("lennag.jpg",0);
  Mat_<unsigned char> b = mediamov(a);
  imwrite("lennag_mediamov_cv2.jpg",b);
}