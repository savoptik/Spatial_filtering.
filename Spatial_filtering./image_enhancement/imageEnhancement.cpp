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

cv::Mat& imageEnhancement::laplasianing() {
    Laplacian(importMatrix, vorkMatrix, 0);
    nameWindow = "Laplacian";
    return vorkMatrix;
}

cv::Mat& imageEnhancement::gradienting() {
    Sobel(importMatrix, vorkMatrix, 0, 1, 0);
    nameWindow = "Gradient";
    return vorkMatrix;
}

cv::Mat& imageEnhancement::smoothing() {
    medianBlur(importMatrix, vorkMatrix, 7);
    nameWindow = "Smooth";
    return vorkMatrix;
}

cv::Mat &imageEnhancement::extractVorkMatrix() { 
    return vorkMatrix;
}

void imageEnhancement::showCurrentState() { 
    namedWindow(nameWindow);
    imshow(nameWindow, vorkMatrix);
    waitKey();
    destroyWindow(nameWindow);
}

imageEnhancement::imageEnhancement(cv::Mat matrix) { 
    matrix.copyTo(importMatrix);
}

