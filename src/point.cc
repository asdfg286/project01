#include"point.h"



// 计算点相对于第一个点的角度
float angleBetweenPoints(cv::Point p1, cv::Point p2, cv::Point firstPoint) {
    float dx1 = p1.x - firstPoint.x;
    float dy1 = p1.y - firstPoint.y;
    float dx2 = p2.x - firstPoint.x;
    float dy2 = p2.y - firstPoint.y;
    float angle1 = atan2(dy1, dx1);
    float angle2 = atan2(dy2, dx2);
    return angle2 - angle1;
}



// 按顺时针方向排列点

std::vector<cv::Point> sortPointsClockwise(std::vector<cv::Point>& points) {
    cv::Point special=points[3];
    
    //中心
    cv::Point center(0,0);
    for(int i=0;i<4;i++){
        center.x+=points[i].x/4;
        center.y+=points[i].y/4;
    }

    cv::Point firstPoint = center;
    std::vector<cv::Point> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [firstPoint](const cv::Point& p1, const cv::Point& p2) {
        return angleBetweenPoints(p1, firstPoint, firstPoint) < angleBetweenPoints(p2, firstPoint, firstPoint);
    });
    
    for(int i=0;i<sortedPoints.size();i++){
        if(sortedPoints[i]==special&&i!=points.size()-1){
            //在i后拆分
            std::vector<cv::Point> temp;
            for(int j=i+1;j<sortedPoints.size();j++){
                temp.push_back(sortedPoints[j]);
            }
            for(int j=0;j<i+1;j++){
                temp.push_back(sortedPoints[j]);
            }
            sortedPoints=temp;

        }
    }
    
    if(sortedPoints[3].x>center.x&&sortedPoints[3].y>center.y&&sortedPoints[2].y<center.y&&sortedPoints[2].x>center.x){std::cout<<"1";cv::Point temp0=sortedPoints[2];sortedPoints[2]=sortedPoints[0];sortedPoints[0]=temp0;}
    else if(sortedPoints[3].x>center.x&&sortedPoints[3].y<center.y&&sortedPoints[2].y<center.y&&sortedPoints[2].x<center.x){std::cout<<"2";cv::Point temp0=sortedPoints[2];sortedPoints[2]=sortedPoints[0];sortedPoints[0]=temp0;}
    else if(sortedPoints[3].x<center.x&&sortedPoints[3].y>center.y&&sortedPoints[2].y>center.y&&sortedPoints[2].x>center.x){std::cout<<"3";cv::Point temp0=sortedPoints[2];sortedPoints[2]=sortedPoints[0];sortedPoints[0]=temp0;}
    else if(sortedPoints[3].x<center.x&&sortedPoints[3].y<center.y&&sortedPoints[2].y>center.y&&sortedPoints[2].x<center.x){std::cout<<"4";cv::Point temp0=sortedPoints[2];sortedPoints[2]=sortedPoints[0];sortedPoints[0]=temp0;}
    
    
    return sortedPoints;
    
}



// 计算两个点之间的欧几里得距离
double euclideanDistance(cv::Point p1, cv::Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}



// 处理距离较近的点
std::vector<cv::Point> processNearPoints(const std::vector<cv::Point>& points, double threshold,std::vector<std::vector<cv::Point>> contours) {
    std::vector<cv::Point> result;
    std::vector<cv::Point> result0;
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            // std::cout<<euclideanDistance(points[i],points[j])<<std::endl;
            if(euclideanDistance(points[i],points[j])<threshold){
                result0.push_back(points[i]);
                result0.push_back(points[j]); 
            }
        } 
    }


    //result0没有的点放在result
    for(int i=0;i<points.size();i++){
        bool flag=false;
        for(int j=0;j<result0.size();j++){
            if(points[i]==result0[j]){
                flag=true;
                break;
            }
        }
        if(!flag){
            result.push_back(points[i]);
        }
    }
    
    if(result.size()==4){return result;}
    
    cv::Point temp(0,10000);
    std::vector<std::vector<cv::Point>> contourss;
    //提取result0所在轮廓
    for(int i=0;i<contours.size();i++){
        for(int j=0;j<contours[i].size();j++){
            for(int k=0;k<result0.size();k++){
            if(contours[i][j]==result0[k]){
               contourss.push_back(contours[i]); 
            }
        }
    }
    }
    std::vector<double> area;
    //提取面积最大得轮廓
    for(int i=0;i<contourss.size();i++){
       area.push_back(cv::contourArea(contourss[i])); 
    }
    sort(area.begin(),area.end(),[](double a, double b){return a>b;});
    std::vector<double> dist;
    for(int i=0;i<contourss.size();i++){
        
       if(cv::contourArea(contourss[i])==area[0]){
           for(int j=0;j<3;j++){
            for(int k=j+1;k<3;k++){
            
                dist.push_back(euclideanDistance(contourss[i][j],contourss[i][k]));

            }
        }
           sort(dist.begin(),dist.end(),[](double a, double b){return a>b;});
           for(int j=0;j<3;j++){
            for(int k=j+1;k<3;k++){
            if(euclideanDistance(contourss[i][j],contourss[i][k])==dist[0]){
                temp=contourss[i][3-j-k];
                }
            }
        }
    }
}
    result.push_back(temp);
    return result;
}

//分
std::vector<std::vector<cv::Point>> distinguish(std::vector<std::vector<cv::Point>> contours,cv::Mat& img0)
{
    std::vector<std::vector<cv::Point>> point;
    point.push_back(std::vector<cv::Point>()); // 添加第一个子向量
    point.push_back(std::vector<cv::Point>()); // 添加第二个子向量
    std::vector<double> length;
    for(int i=0;i<contours.size();i++){
        length.push_back(cv::arcLength(cv::Mat(contours[i]), true)); 
    }
    std::sort(length.begin(),length.end(),[](double a, double b){return a>b;});
    if(length[0]>length[1]*1.5){
       for(int i=0;i<contours.size();i++){
        if(cv::arcLength(cv::Mat(contours[i]), true)==length[0]){
            // point.insert(point.end(), contours[i].begin(), contours[i].end());
            for(int j=0;j<contours[i].size();j++){
                point[0].push_back(contours[i][j]);
            
            }
        }
        else{
            // 将 vertex 函数返回的点插入到 point 向量中
            //point.insert(point.end(), vertex(contours[i], img0).begin(), vertex(contours[i], img0).end());
            for(int j=0;j<vertex(contours[i], img0).size();j++){
                point[1].push_back(vertex(contours[i], img0)[j]);
            }
        }
        }
       
    }
    ///=======================
    else{
        for(int i=0;i<contours.size();i++){
            // 将 vertex 函数返回的点插入到 point 向量中
            //point.insert(point.end(), vertex(contours[i], img0).begin(), vertex(contours[i], img0).end());
            for(int j=0;j<vertex(contours[i], img0).size();j++){
                point[1].push_back(vertex(contours[i], img0)[j]);
            }
        }
    }
   
    return point;
}


std::vector<cv::Point> vertex(std::vector<cv::Point> contour,cv::Mat& img0){
    //顶点
    
    std::vector<cv::Point> vertex;
    
    if(contour.size()==3){
        
        
        for(int j=0;j<3;j++){
            cv::Point temp1=(contour[j]+contour[(j+1)%3])/2;
            cv::Point temp2=(contour[j]+contour[(j+2)%3])/2;
            int a=isRedPixel(temp1,img0);
            int b=isRedPixel(temp2,img0);
            //std::cout<<a<<" "<<b<<std::endl;
            if((a+b)==2){
                vertex.push_back(contour[j]);
                
            }
        }
    }
    return vertex;  
}



//red
bool isRedPixel(cv::Point point, cv::Mat image) {
    // 检查点是否在图像范围内
    int x = point.x;
    int y = point.y;
    if (x < 0 || x >= image.cols || y < 0 || y >= image.rows) {
        return false; // 坐标超出图像范围
    }

    // 检查图像是否为空
    if (image.empty()) {
        return false; // 图像为空
    }

    // 定义红色的阈值
    const cv::Scalar redLower(0,0, 10);
    const cv::Scalar redUpper(250,250, 255);

    

    // 获取该点的像素值
    cv::Vec3b color = image.at<cv::Vec3b>(y, x);

    // 判断该点是否为红色
    return (color[0] >= redLower[0] && color[0] <= redUpper[0] &&
            color[1] >= redLower[1] && color[1] <= redUpper[1] &&
            color[2] >= redLower[2] && color[2] <= redUpper[2]);
}





std::vector<std::vector<cv::Point>> getPoint(cv::Mat& img,std::vector<std::vector<cv::Point>> contours,cv::Mat& img0){

    cv::Mat point= cv::Mat::zeros(img.size(), CV_8UC3);
    cv::drawContours(point, contours, -1, cv::Scalar(255, 0, 0), 1);
    cv::imshow("result1", point);

    for(int i=0;i<contours.size();i++){
        for(int j=0;j<contours[i].size();j++){
            
                cv::drawMarker(point,contours[i][j],cv::Scalar(255,0,0),cv::MARKER_CROSS, 5, 2);
            
        }
    }
    imshow("result2", point);
    

    std::vector<std::vector<cv::Point>> pointss;
    std::vector<cv::Point> pointthr;
    std::vector<cv::Point> pointfor;


    pointss=distinguish(contours,img0);
    pointfor=processNearPoints(pointss[1], 30,contours);
    
    pointthr=pointss[0];
    
    
    for(int i=0;i<pointthr.size();i++){
        cv::drawMarker(point,pointthr[i],cv::Scalar(0,0,255),cv::MARKER_CROSS, 5, 2);
    }
    for(int i=0;i<pointfor.size()-1;i++){
        cv::drawMarker(point,pointfor[i],cv::Scalar(0,255,255),cv::MARKER_CROSS, 5, 2);
    }
    cv::drawMarker(point,pointfor[pointfor.size()-1],cv::Scalar(255,255,255),cv::MARKER_CROSS, 5, 2);
    imshow("result4", point);

    std::vector<std::vector<cv::Point>> result=pointss;
    result.push_back(std::vector<cv::Point>()); // 添加第一个子向量
    result.push_back(std::vector<cv::Point>()); // 添加第二个子向量
    result[0]=pointthr;
    result[1]=pointfor;
    for(int i=0;i<result[0].size();i++){
        //按y小到大
        for(int j=i+1;j<result[0].size();j++){
            if(result[0][i].y>result[0][j].y){
                cv::Point temp=result[0][i];
                result[0][i]=result[0][j];
                result[0][j]=temp;
            }
        }
    }

if(result[1].size()==4){
    result[1] = sortPointsClockwise(result[1]);
}

else{std::cout<<"error"<<std::endl;}
    return result;

}





