#include"pnp.h"
#include"point.h"
void pnp(std::vector<cv::Point2f> &imagePoints,cv::Mat &rvec,cv::Mat &tvec,cv::Mat &image,cv::Point special){
    // 3D点的坐标（在世界坐标系中）
    std::vector<cv::Point3f> objectPoints;
    objectPoints.push_back(cv::Point3f(275.0f, 0.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(275.0f, 275.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(0.0f, 275.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(0.0f, 0.0f, 0.0f));
 
    // 相机内参矩阵
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 
        1.521928836685752e+03, 0, 9.504930579948792e+02,
        0, 1.521695508574793e+03, 6.220985582938733e+02,
        0, 0, 1);

    // 畸变系数
    cv::Mat distCoeffs = (cv::Mat_<double>(5,1) << -0.157095872989630,0.166823029778507,1.356728774532785e-04,2.266474993725451e-04,-0.070807947517560);

    // 使用solvePnP函数求解相机位姿
    bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);
    if(success){
        std::vector<cv::Point3f> points3D={cv::Point3f(0,0,0)};
        std::vector<cv::Point2f> points2D;
        cv::projectPoints(points3D, rvec, tvec, cameraMatrix, distCoeffs, points2D);
        if(euclideanDistance(points2D[0],special)>30){
            success=0;
            rvec=cv::Mat();
            tvec=cv::Mat();
        }
    }
    if(success)cv::drawFrameAxes(image, cameraMatrix, distCoeffs, rvec, tvec, 100);
    
    

}