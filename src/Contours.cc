#include"Contours.h"
std::vector<std::vector<cv::Point>> getContours(cv::Mat &img)
{
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);	
    cv::Mat mask;
    cv::Mat mask1;
    cv::Mat mask2;
    cv::Mat mask3;
    cv::inRange(hsv, cv::Scalar(0, 43, 46), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(hsv, cv::Scalar(156, 43, 46), cv::Scalar(180, 255, 255), mask2);
    cv::inRange(hsv, cv::Scalar(26, 43, 46), cv::Scalar(34, 255, 255), mask3);
    mask=mask1|mask2|mask3;
  
    cv::imshow("mask", mask);

    cv::Mat point= cv::Mat::zeros(img.size(), CV_8UC3);
    cv::GaussianBlur(mask,mask,cv::Size(3,3),0);
    cv::Canny(mask,point,50,150);


    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(point, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        
    for(int i=0;i<contours.size();i++){
        float num=0.05;
        int time=0;
        while(1){
        time++;
        if(time>100){
            std::cout<<"0000000"<<std::endl;
            break;}
        if(num<0){break;}
        if(contours[i].size()==3)break;
        else if(contours[i].size()>3){cv::approxPolyDP(cv::Mat(contours[i]), contours[i], cv::arcLength(cv::Mat(contours[i]), true) * num, true);
        num+=0.01;
        }
        else if(contours[i].size()<3){cv::approxPolyDP(cv::Mat(contours[i]), contours[i], cv::arcLength(cv::Mat(contours[i]), true) * num, true);
        num-=0.01;
        }
    }
    
    }
    
    double minArea = 0.0;

    // 过滤小面积轮廓
    std::vector<std::vector<cv::Point>> filteredContours;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area >= minArea) {
            filteredContours.push_back(contours[i]);
        }
    }
    

   
    return contours;
}