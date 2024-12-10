#include"test.h"
#include"Contours.h"
#include"point.h"
#include"pnp.h"



cv::Mat test01(cv::Mat &img){
std::vector<std::vector<cv::Point>> contours=getContours(img);
cv::Mat mask=cv::Mat::zeros(img.size(), CV_8UC1);
cv::drawContours(mask,contours,-1,cv::Scalar(255,255,255),2);
bool is=1;
if(contours.size()>=10){is=0;}
std::vector<std::vector<cv::Point>> points=getPoint(mask,contours,img);

cv::Mat point = img.clone();


// 2D点的坐标（在图像坐标系中）
    std::vector<cv::Point2f> imagePoints;
    for (const auto& point : points[1]) {
        imagePoints.push_back(cv::Point2f(point.x, point.y));
    }
    cv::Mat rvec;
    cv::Mat tvec; 
    std::vector<double>area;
    for(int i=0;i<imagePoints.size();i++){
        std::vector<cv::Point>contour=findcontour(imagePoints[i],contours);
        if(!contour.empty()){area.push_back(contourArea(contour));}
    }
    
   

    double diss=50;
    
    if(imagePoints.size()==4&&euclideanDistance(points[1][0],points[1][1])>diss&&euclideanDistance(points[1][1],points[1][2])>diss&&euclideanDistance(points[1][2],points[1][3])>diss&&euclideanDistance(points[1][3],points[1][0])>diss&&is){
    
    pnp(imagePoints,rvec,tvec,point,points[1][3]);

    }
    return point;
}