#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

cv::Mat img;
cv::Mat imgOrg;
cv::Mat Mask;
int main(int argc, char** argv){
    string strPath = "now.jpg";
    imgOrg = cv::imread(strPath.c_str(), 1);
    Mask=cv::imread("pre/out.jpg");
    img = imgOrg.clone();
    img = Scalar::all(0);
    imgOrg.copyTo(img, Mask);
    imwrite("now.jpg",img);
    return 0;
}
