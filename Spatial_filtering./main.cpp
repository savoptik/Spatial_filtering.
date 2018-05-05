//
//  main.cpp
//  Spatial_filtering.
//
//  Created by Артём Семёнов on 04.05.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "matrixContainer.hpp"
#include "imageEnhancement.hpp"
using namespace std;

const string filePath = "skeleton2.png";

int main(int argc, const char * argv[]) {
    matrixContainer container(filePath); // создание контейнера.
    container.showImage(); // вывод изображения для контроля.
    imageEnhancement laplacian(container.extractImage());
    laplacian.laplasianing();
    laplacian.showCurrentState();
    return 0;
}
