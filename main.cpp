#include <stdlib.h>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
/*
// #define NEGRO_BAJO [0,0,55]
// #define NEGRO_ALTO [255,255,44]
*/
typedef enum{
    ERROR_IMG,
    ERROR_IMG_CSV
}error_t;

using namespace cv;

int main (int argc, char *argv[]) {
    Mat Img, ImgHSV;
    Mat msk;
    Moments mom;
    double area;
    //unsigned char color_bajo[] = {0,0,55};
    //unsigned char color_alto[] = {255,255,44};

//cargo en bgr y convierto imagen a csv
    Img = imread(argv[1],CV_LOAD_IMAGE_COLOR);
    if (!Img.data){
        puts("error");
        return ERROR_IMG;
    }


    //printf("%i\n",Img.channels());

    cvtColor(Img,ImgHSV,COLOR_BGR2HSV);
    if (!ImgHSV.data)
            return ERROR_IMG_CSV;
    puts("cargo");


    inRange (Img, Scalar (0,0,250), Scalar (0,0,255) , msk);


    mom=moments(msk,true);

    //valor del area
    printf("%s %lf\n","area",mom.m00);
    //
    area = mom.m00;


    //Pantallas de testeo
    namedWindow( "mask", WINDOW_AUTOSIZE );
    imshow("mask", msk);

    //namedWindow( "ImgHSV", WINDOW_AUTOSIZE );
    //imshow("ImgHSV", ImgHSV);

    namedWindow( "Img", WINDOW_AUTOSIZE );
    imshow("Img", Img);

   //

    if(area>100)
        printf("negro\n");
    else
        printf("no negro\n");
    waitKey(0);
    destroyAllWindows();
    return 0;

}
