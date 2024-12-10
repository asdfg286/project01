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
//drawMarker(img,points[1][points[1].size()-1],cv::Scalar(255,255,0),2);
cv::Mat point = img.clone();




cv::imshow("poin    t",point);


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
    
    // for(int i=0;i<area.size();i++){
    //      if(area[i]<30){
    //          is=0;
    //    }
    // }

    double diss=50;
    
    if(imagePoints.size()==4&&euclideanDistance(points[1][0],points[1][1])>diss&&euclideanDistance(points[1][1],points[1][2])>diss&&euclideanDistance(points[1][2],points[1][3])>diss&&euclideanDistance(points[1][3],points[1][0])>diss&&is){
    //std::cout<<" ========"<<imagePoints.size()<<std::endl;
    cv::Mat r=img.clone();
    for(int i=0;i<imagePoints.size();i++){
        cv::circle(r,imagePoints[i],5,cv::Scalar(0,255,255),-1);
        //std::cout<<"////////"<<imagePoints[i]<<std::endl;
    }
    std::cout<<img.rows<<" "<<img.cols<<std::endl;
    cv::imshow("r",r);
    bool success=pnp(imagePoints,rvec,tvec,point,points[1][3]);
    if(success) {

        
        std::cout << "PnP solved successfully!" << std::endl;

        // 将旋转向量转换为旋转矩阵
        cv::Mat R;
        cv::Rodrigues(rvec, R);

        // 输出结果
        // std::cout << "Rotation vector: " << rvec << std::endl;
        // std::cout << "Translation vector: " << tvec << std::endl;
        // std::cout << "Rotation matrix: " << R << std::endl;
        
        
    } else {
        std::cout << "PnP solve failed." << std::endl;
        
    }
    }
    return point;
}