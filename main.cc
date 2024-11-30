# include"test.h"
int main(){
cv::Mat img=cv::imread("../img/a/d.jpg");
    if(img.empty()){
        std::cout<<"111";
        return -1;
    }
    cv::imshow("img",img);
    test01(img);
    cv::waitKey(0);

    
    return 0;
}