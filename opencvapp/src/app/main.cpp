#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    printf("Hello\n");

    //cv::Mat image = cv::imread(RESOURCE_DIR "lena.jpg");
    cv::Mat mat = (cv::Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    std::cout << mat << std::endl;
    //    cv::imshow("Display", image);
    std::cout << cv::getBuildInformation() << std::endl;
    //    cv::waitKey(0);
    return 0;
}
