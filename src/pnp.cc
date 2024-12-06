#include"pnp.h"
bool pnp(std::vector<cv::Point2f> &imagePoints,cv::Mat &rvec,cv::Mat &tvec){
    // 3D������꣨����������ϵ�У�
    std::vector<cv::Point3f> objectPoints;
    objectPoints.push_back(cv::Point3f(275.0f, 0.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(275.0f, 275.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(0.0f, 275.0f, 0.0f));
    objectPoints.push_back(cv::Point3f(0.0f, 0.0f, 1.0f));

    

    // ����ڲξ���
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 
        1.521928836685752e+03, 0, 9.504930579948792e+02,
        0, 1.521695508574793e+03, 6.220985582938733e+02,
        0, 0, 1);

    // ����ϵ��
    cv::Mat distCoeffs = (cv::Mat_<double>(5,1) << -0.157095872989630,0.166823029778507,1.356728774532785e-04,2.266474993725451e-04,-0.070807947517560);


    

  
    

    // ʹ��solvePnP����������λ��
    bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

    // if(success) {
    //     std::cout << "PnP solved successfully!" << std::endl;

    //     // ����ת����ת��Ϊ��ת����
    //     cv::Mat R;
    //     cv::Rodrigues(rvec, R);

    //     // ������
    //     std::cout << "Rotation vector: " << rvec << std::endl;
    //     std::cout << "Translation vector: " << tvec << std::endl;
    //     std::cout << "Rotation matrix: " << R << std::endl;
        
    // } else {
    //     std::cout << "PnP solve failed." << std::endl;
        
    // }
return 0;
}