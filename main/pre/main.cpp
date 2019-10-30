#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

cv::Mat img;
cv::Mat img0;
cv::Mat imgMask;
cv::Mat imgOrg;
cv::Mat imgout;
Point lastPt;
Point firstPt;

void on_mouse_callback(int event, int x, int y, int flags, void* yybird){
    if (!img.data){
	printf("image is empty!\n");
	return;
    }
    Point pt = Point(x, y);
    if (event == cv::EVENT_LBUTTONUP ) {
	line(img, pt, firstPt, Scalar(0, 0, 255), 1, 8, 0);
	line(imgMask, pt, firstPt, Scalar(255, 255, 255), 1, 8, 0);
	imshow("image", img);		
    }
    else if (event == cv::EVENT_LBUTTONDOWN) {
	firstPt = lastPt = Point(x, y);
    }
    else if( (event == cv::EVENT_MOUSEMOVE) && (flags & cv::EVENT_FLAG_LBUTTON) ){
	if (lastPt.x < 0) { lastPt = pt; }
	line(img, lastPt, pt, Scalar(0, 0, 255), 1, 8, 0);
	line(imgMask, lastPt, pt, Scalar(255, 255, 255), 1, 8, 0);
	imshow("image", img);
	lastPt = pt;
    }
    if (event == cv::EVENT_RBUTTONUP){
	floodFill(imgMask, Point(x, y), Scalar(255, 255, 255));
	Mat grayMask = imgMask.clone();
	cvtColor(imgMask, grayMask, COLOR_BGR2GRAY);  
	cv::threshold(grayMask, grayMask, 254, 255, THRESH_BINARY);  
	img0.copyTo(imgout, grayMask);
	imshow("Image out", imgout);
	imwrite("out.jpg",imgout);
	imgOrg.copyTo(imgMask, grayMask);
	imshow("Image in Mask", imgMask);

    }
}

int main(int argc, char** argv){
    string strPath = "now.jpg";
    imgOrg = cv::imread(strPath.c_str(), 1);
    img = imgOrg.clone();
    imgMask = imgOrg.clone();
    imgMask = Scalar::all(0);
    img0 = imgOrg.clone();
    img0 = Scalar::all(255);
    imgout = imgOrg.clone();
    imgout = Scalar::all(0);
    namedWindow("image", 1);
    imshow("image", img);
    cv::setMouseCallback("image", on_mouse_callback, 0);
    waitKey(0);
    return 0;
}
