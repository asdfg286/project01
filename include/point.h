#include<opencv2/opencv.hpp>
std::vector<cv::Point> findcontour(cv::Point point,std::vector<std::vector<cv::Point>> contours);
std::vector<std::vector<cv::Point>> getPoint(cv::Mat& img,std::vector<std::vector<cv::Point>> contours,cv::Mat& img0);
float angleBetweenPoints(cv::Point p1, cv::Point p2, cv::Point firstPoint);
bool isRedPixel(cv::Point point, cv::Mat image);
std::vector<std::vector<cv::Point>> distinguish(std::vector<std::vector<cv::Point>> contours,cv::Mat& img0);
std::vector<cv::Point> vertex(std::vector<cv::Point> contour,cv::Mat& img0);
double euclideanDistance(cv::Point p1, cv::Point p2);
std::vector<cv::Point> processNearPoints(const std::vector<cv::Point>& points, double threshold,std::vector<std::vector<cv::Point>> contours);
std::vector<cv::Point> sortPointsClockwise(std::vector<cv::Point>& points);