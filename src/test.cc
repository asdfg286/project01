#include"test.h"
#include"Contours.h"
#include"point.h"
#include"pnp.h"



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

// 2D点的坐标（在图像坐标系中）
    std::vector<cv::Point2f> imagePoints;
    for (const auto& point : points[1]) {
        imagePoints.push_back(cv::Point2f(point.x, point.y));
    }
    cv::Mat rvec;
    cv::Mat tvec;
    if(imagePoints.size()==4){
    bool success=pnp(imagePoints,rvec,tvec);
    if(success) {
        std::cout << "PnP solved successfully!" << std::endl;

        // 将旋转向量转换为旋转矩阵
        cv::Mat R;
        cv::Rodrigues(rvec, R);

        // 输出结果
        std::cout << "Rotation vector: " << rvec << std::endl;
        std::cout << "Translation vector: " << tvec << std::endl;
        std::cout << "Rotation matrix: " << R << std::endl;
        
    } else {
        std::cout << "PnP solve failed." << std::endl;
        
    }
    }
}