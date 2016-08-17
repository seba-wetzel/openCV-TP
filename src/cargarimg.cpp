#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "typedefs.h"

estado_t cargarImg(const char * nombre, img_t *img){

    img->matImg = imread(nombre,CV_LOAD_IMAGE_COLOR);
    if (!img->matImg.data)
        return ERROR_IMG;
    return OK;

}

