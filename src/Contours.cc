#include"Contours.h"
std::vector<std::vector<cv::Point>> getContours(cv::Mat &img)
{
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);	

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat kerne2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
    morphologyEx(hsv, hsv, cv::MORPH_OPEN, kernel);
    morphologyEx(hsv, hsv, cv::MORPH_CLOSE, kerne2);
    cv::Mat mask;
    cv::Mat mask1;
    cv::Mat mask2;

    cv::inRange(hsv, cv::Scalar(0, 40, 20), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(hsv, cv::Scalar(156, 40, 20), cv::Scalar(180, 255, 255), mask2);

    mask=mask1|mask2;

    // 形态学操作去除噪点
    cv::Mat kerne3 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat kerne4 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    morphologyEx(mask, mask, cv::MORPH_OPEN, kerne3);
    morphologyEx(mask, mask, cv::MORPH_CLOSE, kerne4);
  
    
    cv::Mat point= cv::Mat::zeros(img.size(), CV_8UC3);
    cv::GaussianBlur(mask,mask,cv::Size(3,3),0);
    cv::Canny(mask,point,50,150);


    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(point, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for(int i=0;i<contours.size();i++){
    if(contourArea(contours[i])<40.0){
        contours.erase(contours.begin()+i);
        i--;
    }    
    }
    for(int i=0;i<contours.size();i++){
        float num=0.05;
        int time=0;
        while(1){
        time++;
        if(time>1000){break;}
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
    return contours;
}