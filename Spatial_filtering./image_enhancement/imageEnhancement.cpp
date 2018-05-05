//
//  imageEnhancement.cpp
//  Spatial_filtering.
//
//  Created by Артём Семёнов on 05.05.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "imageEnhancement.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

cv::Mat& imageEnhancement::laplasianing(cv::Mat &matrix) { 
    cvLaplace(matrix, vorkMatrix);
    return vorkMatrix;
}

cv::Mat& imageEnhancement::gradienting(cv::Mat &matrix) {
    cvSobel(matrix, vorkMatrix, 1, 0);
    return vorkMatrix;
}

cv::Mat& imageEnhancement::smoothing(cv::Mat &matrix) {
    ы
    cvSmooth(matrix, vorkMatrix);
    return vorkMatrix
}

cv::Mat &imageEnhancement::extractVorkMatrix() { 
    return vorkMatrix;
}
