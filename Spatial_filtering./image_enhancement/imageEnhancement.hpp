//
//  imageEnhancement.hpp
//  Spatial_filtering.
//
//  Created by Артём Семёнов on 05.05.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef imageEnhancement_hpp
#define imageEnhancement_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class imageEnhancement {
public:
    cv::Mat& laplasianing(cv::Mat& matrix);
    cv::Mat& gradienting(cv::Mat& matrix);
    cv::Mat& smoothing(cv::Mat& matrix);
    cv::Mat& extractVorkMatrix();
private:
    cv::Mat vorkMatrix;
};

#endif /* imageEnhancement_hpp */
