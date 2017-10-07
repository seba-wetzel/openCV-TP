#define _GLIBCXX_USE_CXX11_ABI 1
#include <stdio.h>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>

#include "manejoImagen.h"
#include "typedefs.h"

estado_t cargarImg(const char * nombre, img_t *img){

    img->matImg = imread(nombre,CV_LOAD_IMAGE_COLOR);
    if (!img->matImg.data)
        return ERROR_IMG;
    return OK;

}

