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
#include <cmath>
using namespace cv;

const std::string filePath = "skeleton2.png";

int main(int argc, const char * argv[]) {
    auto img = imread(filePath, IMREAD_GRAYSCALE); // чтени файла.
    imshow("first", img);
    waitKey();
    Mat laplacian;
    Laplacian(img, laplacian, 3); // лапласиан.
    convertScaleAbs(laplacian, laplacian);
    auto laplacianAddIMG = laplacian + img; // наложение лапласиана на изображение.
    imshow("laplacian", laplacianAddIMG);
    waitKey();
    Mat grad;
    Sobel(img, grad, CV_64F, 1, 1);
    imshow("sobl", grad);
    waitKey();
    Mat smooth;
//    medianBlur(grad, smooth, 3);
    blur(grad, smooth, Size(3, 3));
    imshow("smuth", smooth);
    waitKey();
    Mat multiplet;
    convertScaleAbs(smooth, smooth);
    multiply(laplacianAddIMG, smooth, multiplet);
    imshow("multiplet", multiplet);
    waitKey();
    Mat multipleAddIMG = (img/255.0 + multiplet);
    imshow("multiplet + img", multipleAddIMG);
    waitKey();
           for (int i = 0; i < multipleAddIMG.rows; i++) {
               for (int j = 0; j < multipleAddIMG.cols; j++) {
                   multipleAddIMG.at<double>(i, j) = pow(multipleAddIMG.at<double>(i, j), 0.50);
               }
           }
    imshow("result", multipleAddIMG);
    waitKey();
    destroyAllWindows();
    return 0;
}
