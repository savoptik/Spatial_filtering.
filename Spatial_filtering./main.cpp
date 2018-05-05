//
//  main.cpp
//  Spatial_filtering.
//
//  Created by Артём Семёнов on 04.05.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

const std::string filePath = "skeleton2.png";

int main(int argc, const char * argv[]) {
    auto img = imread(filePath); // чтени файла.
    imshow("first", img);
    waitKey();
    Mat laplacian;
    Laplacian(img, laplacian, 3); // лапласиан.
    convertScaleAbs(laplacian, laplacian);
    auto laplacianAddIMG = laplacian + img; // наложение лапласиана на изображение.
    namedWindow("laplacian", CV_WINDOW_AUTOSIZE);
    Mat grad;
    Sobel(img, grad, 3, 1, 1);
    Mat smooth;
    medianBlur(grad, smooth, 3);
    Mat multiplet = (laplacianAddIMG/255.0) * (smooth/255.0);
    Mat multipleAddIMG = img/255 + multiplet;
    Mat result = multipleAddIMG;
    imshow("result", result);
    waitKey();
    destroyAllWindows();
    return 0;
}
