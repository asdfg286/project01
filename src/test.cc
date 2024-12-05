#include"test.h"
#include"Contours.h"
#include"point.h"



void test01(cv::Mat &img){
std::vector<std::vector<cv::Point>> contours=getContours(img);
cv::Mat mask=cv::Mat::zeros(img.size(), CV_8UC1);
cv::drawContours(mask,contours,-1,cv::Scalar(255,255,255),2);


std::vector<std::vector<cv::Point>> points=getPoint(mask,contours,img);
cv::Mat point = img.clone();
for(int i=0;i<points[0].size();i++){
cv::drawMarker(point ,points[0][i], cv::Scalar(255, 255, 0), cv::MARKER_CROSS, 5, 2);
}
for(int i=0;i<points[1].size()-1;i++){
cv::drawMarker(point ,points[1][i], cv::Scalar(0, 255, 255), cv::MARKER_CROSS, 5, 2);
}
cv::drawMarker(point ,points[1][points[1].size()-1], cv::Scalar(255, 255, 255), cv::MARKER_CROSS, 5, 2);



for(int i=0;i<points[0].size();i++){
cv::putText(point, std::to_string(i+1), points[0][i], cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
}
for(int i=0;i<points[1].size();i++){
cv::putText(point, std::to_string(4-i), points[1][i], cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 255), 2);
}



cv::imshow("poin    t",point);
}