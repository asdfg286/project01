# include"test.h"
// int main(){
// cv::Mat img=cv::imread("../img/station/20211816608.jpg");
//     if(img.empty()){
//         std::cout<<"111";
//         return -1;
//     }
//     cv::imshow("img",img);
//     test01(img);
//     cv::waitKey(0);


//     return 0;
// }


#include <iostream>          // ������׼����������⣬���ڴ�ӡ��Ϣ
#include <filesystem>        // �����ļ�ϵͳ�⣬���ڱ����ļ��к��ļ�����

namespace fs = std::filesystem; // ʹ��std::filesystem�����ռ�ı������򻯴���

// int main() {
//     std::string path = "../img/station"; // ָ��Ҫ�������ļ���·��
//     std::string outputPath = "../img/output";
//     fs::path dir(path);                      // ���ַ���·��ת��Ϊfs::path����
//     fs::path outputDir(outputPath);


//     // ��������ļ��У���������ڣ�
//     if (!fs::exists(outputDir)) {
//         fs::create_directory(outputDir);
//     }

//     int count = 0; // ���ڼ��������ͼƬ����

//     // ����ָ���ļ����е������ļ���Ŀ¼
//     for (auto&& entry : fs::directory_iterator(dir)) {
//         // ����ļ���չ���Ƿ�ΪͼƬ��ʽ
//         if (entry.path().extension() == ".png" ||
//             entry.path().extension() == ".jpg" ||
//             entry.path().extension() == ".jpeg") {

//             // ʹ��OpenCV��imread������ȡͼƬ
//             cv::Mat image = cv::imread(entry.path().string());

//             // ���ͼƬ�Ƿ�ɹ����أ��ǿգ�
//             if (!image.empty()) {
//                 // ��ʾͼƬ����������Ϊ"Image"
//                 cv::Mat result=test01(image);
//                 std::cout<<"6666666666666644444444"<<std::endl;
//                 std::string outputFileName = entry.path().filename().string();
//                 fs::path outputPath = outputDir / outputFileName;
//                 //ͼ��д�ı�

//                 //cv::putText(result, entry.path().string(), cv::Point(50,50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 2);

//                 cv::imwrite(outputPath.string(), result);

//                 cv::imshow("Image", result);
//                 // �ȴ�����������0��ʾ���޵ȴ�ֱ������
//                 int num=cv::waitKey(0);
//                 //esct �˳�

//                 if(num==27)return 0;
                

//                 count++; // ���Ӽ�����
//             }
//             // ����Ѿ�������2000��ͼƬ�����˳�ѭ��
//             if (count >= 2122) break;
//         }
//     }
//     return 0; // �������
// }

// #include <iostream>
// #include <vector>
// #include <string>

// int main() {
//     std::string outputPath = "../img/output";
//     fs::path outputDir(outputPath);
//     // ��Ƶ��֡��
//     double fps = 10.0;
//     // ��Ƶ�ķֱ���
//     cv::Size frameSize(1920, 1080);
//     // ��Ƶ�ı����ʽ��ȷ�����ϵͳ֧���������
//     int codec = cv::VideoWriter::fourcc('m', 'p', '4', 'v'); // �Ƽ�ʹ��
//     // �����Ƶ���ļ���
//     std::string outputFile = "output.mp4";

//     // ������Ƶд�����
//     cv::VideoWriter videoWriter(outputFile, codec, fps, frameSize);

//     // ͼƬ�ļ��б�


//     // ȷ����Ƶд����󴴽��ɹ�
//     if (!videoWriter.isOpened()) {
//         std::cerr << "Error: Could not open video writer." << std::endl;
//         return -1;
//     }

//     // ѭ����ȡͼƬ��д����Ƶ
//     for (const auto& imagePath : fs::directory_iterator(outputDir)) {
//         cv::Mat image = cv::imread(imagePath.path().string());
//         if (image.empty()) {
//             std::cerr << "Error: Could not read the image " << imagePath << std::endl;
//             continue;
//         }
//         // ����ͼƬ��С��ƥ����Ƶ�ֱ���
//         cv::resize(image, image, frameSize);
//         // д��֡����Ƶ
//         videoWriter.write(image);
//     }

//     // �ͷ���Ƶд�����
//     videoWriter.release();

//     std::cout << "Video has been created successfully." << std::endl;
//     return 0;
// }