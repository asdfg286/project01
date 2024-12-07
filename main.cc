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


#include <iostream>          // 包含标准输入输出流库，用于打印信息
#include <filesystem>        // 包含文件系统库，用于遍历文件夹和文件操作

namespace fs = std::filesystem; // 使用std::filesystem命名空间的别名，简化代码

int main() {
    std::string path = "../img/station"; // 指定要遍历的文件夹路径
    std::string outputPath = "../img/output";    
    fs::path dir(path);                      // 将字符串路径转换为fs::path对象
    fs::path outputDir(outputPath);


    // 创建输出文件夹（如果不存在）
    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    int count = 0; // 用于计数处理的图片数量

    // 遍历指定文件夹中的所有文件和目录
    for (auto&& entry : fs::directory_iterator(dir)) {
        // 检查文件扩展名是否为图片格式
        if (entry.path().extension() == ".png" || 
            entry.path().extension() == ".jpg" || 
            entry.path().extension() == ".jpeg") {
            
            // 使用OpenCV的imread函数读取图片
            cv::Mat image = cv::imread(entry.path().string());
            
            // 检查图片是否成功加载（非空）
            if (!image.empty()) {
                // 显示图片，窗口名称为"Image"
                cv::Mat result=test01(image);

                std::string outputFileName = entry.path().filename().string();
                fs::path outputPath = outputDir / outputFileName;
                cv::imwrite(outputPath.string(), result);
                // 等待按键，参数0表示无限等待直到按键
                int num=cv::waitKey(0);
                //esct 退出

                if(num==27)return 0;
                count++; // 增加计数器
            }
            // 如果已经处理了2000张图片，则退出循环
            if (count >= 2000) break;
        }
    }
    return 0; // 程序结束
}
