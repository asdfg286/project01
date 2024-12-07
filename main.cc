# include"test.h"
// int main(){
// cv::Mat img=cv::imread("/mnt/c/Users/wangzixiao1/Pictures/Screenshots/a.png");
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

int main() {
    std::string path = "../img/station"; // ָ��Ҫ�������ļ���·��
    std::string outputPath = "../img/output";    
    fs::path dir(path);                      // ���ַ���·��ת��Ϊfs::path����
    fs::path outputDir(outputPath);


    // ��������ļ��У���������ڣ�
    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    int count = 0; // ���ڼ��������ͼƬ����

    // ����ָ���ļ����е������ļ���Ŀ¼
    for (auto&& entry : fs::directory_iterator(dir)) {
        // ����ļ���չ���Ƿ�ΪͼƬ��ʽ
        if (entry.path().extension() == ".png" || 
            entry.path().extension() == ".jpg" || 
            entry.path().extension() == ".jpeg") {
            
            // ʹ��OpenCV��imread������ȡͼƬ
            cv::Mat image = cv::imread(entry.path().string());
            
            // ���ͼƬ�Ƿ�ɹ����أ��ǿգ�
            if (!image.empty()) {
                // ��ʾͼƬ����������Ϊ"Image"
                cv::Mat result=test01(image);

                std::string outputFileName = entry.path().filename().string();
                fs::path outputPath = outputDir / outputFileName;
                cv::imwrite(outputPath.string(), result);
                // �ȴ�����������0��ʾ���޵ȴ�ֱ������
                int num=cv::waitKey(0);
                //esct �˳�

                if(num==27)return 0;
                count++; // ���Ӽ�����
            }
            // ����Ѿ�������2000��ͼƬ�����˳�ѭ��
            if (count >= 2000) break;
        }
    }
    return 0; // �������
}
