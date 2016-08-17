#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "iostream"
#include "typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>


#include <diccionarioColor.h>

#define AREA 1000000


Scalar myFuncionMax(color_t);
Scalar myFuncionMin(color_t);

using namespace std;

estado_t procesarImg(img_t * img, const char * a){
    Mat ImgHSV;
    Mat imgMascara;
    uchar max= (uchar) atoi(a);

    cvtColor(img->matImg, ImgHSV, CV_BGR2HSV, 0);
    if (!ImgHSV.data){
        return ERROR_CONVER;
    }

    Moments momento;

    int busqueda = 0;
    int j;
    color_t color;


    while (busqueda <= max){

    	img->resist[busqueda].coordX=0;

    	for (j=0; j <= COLOR_MAX; j++) {
    		color =(color_t)j;

    		inRange (ImgHSV, myFuncionMin(color) , myFuncionMax(color) , imgMascara);
    		momento=moments(imgMascara, false);

            if(momento.m00>AREA){

            	Canny(imgMascara,imgMascara,100, 200, 3); //Filtro de Canny para mejorar la deteccion de bordes
                vector<vector<Point> > contours;          //Vector donde se alojan los bordes de las barras de colores
                vector<Vec4i> hierarchy;                  //Vector de jerarquias de bordes
                RNG rng(12345);

                findContours( imgMascara, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
                Mat drawing = Mat::zeros( imgMascara.size(), CV_8UC3 );
                vector<Moments> mu(contours.size() );

                for( int i = 0; i < contours.size(); i++ ) {
                	mu[i] = moments( contours[i], false );
                }


                vector<Point> centroDeMasa( contours.size() );


                for( int i = 0; i< contours.size(); i++ )      //Bucle que recorre todos los contornos
                     {
                	   centroDeMasa[i] = Point( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );

               /*  //Funcion de visualizacion
                       Scalar color_scalar = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
                       drawContours( drawing, contours, i, color_scalar, 2, 8, hierarchy, 0, Point() );
                       circle( drawing, centroDeMasa[i], 4, color_scalar, -1, 8, 0 );
                       ostringstream etiqueta;
                       estiqueta << j;
                       string label = etiqueta.str();
                       putText(drawing, label, Point(centroDeMasa[i]), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
              */
                       static int contador = 0;
                       static int posicion = 0;
                       static int lugar=0;

                       if (lugar != centroDeMasa[i].x ){
                       img->resist[posicion].color=color;
                       img->resist[posicion].coordX=centroDeMasa[i].x;
                       lugar = centroDeMasa[i].x;
                       posicion++;
                       }

                   /*
                    //Funciones de debbug
                    std::cout << "coordenada " << centroDeMasa[i] << "de " << i ;
                    std::cout << "color =" << j << "   ..contador =" << contador << "\n";
                    */
                       contador++;
                     }
                busqueda++;
                }
               }
    		  }

    return OK;
}



Scalar myFuncionMax(color_t j){
	Scalar s;
	switch (j) {
        case COLOR_NEGRO   :
        	s=Scalar NEGRO_MAX   ;
        	return s  ;
        case COLOR_MARRON  :
        	s=Scalar MARRON_MAX  ;
        	return s  ;
        case COLOR_ROJO    :
        	s=Scalar ROJO_ALTO_MAX    ;
        	return s  ;
        case COLOR_NARANJA :
        	s=Scalar NARANJA_MAX ;
        	return s  ;
        case COLOR_AMARILLO:
        	s=Scalar AMARILLO_MAX;
        	return s  ;
        case COLOR_VERDE   :
        	s=Scalar VERDE_MAX   ;
        	return s  ;
        case COLOR_AZUL    :
        	s=Scalar AZUL_MAX    ;
        	return s  ;
        case COLOR_VIOLETA :
        	s=Scalar VIOLETA_MAX ;
        	return s  ;
        case COLOR_GRIS    :
        	s=Scalar GRIS_MAX    ;
        	return s  ;
        case COLOR_BLANCO  :
        	s=Scalar BLANCO_MAX  ;
        	return s  ;
    }
	return s;
}

Scalar myFuncionMin(color_t j){
	Scalar s;
	switch (j) {
    	case COLOR_NEGRO   :
    		s=Scalar NEGRO_MIN;
    		return s  ;
        case COLOR_MARRON  :
        	s=Scalar MARRON_MIN  ;
        	return s  ;
        case COLOR_ROJO    :
        	s=Scalar ROJO_ALTO_MIN    ;
        	return s  ;
        case COLOR_NARANJA :
        	s=Scalar NARANJA_MIN ;
        	return s  ;
        case COLOR_AMARILLO:
        	s=Scalar AMARILLO_MIN;
        	return s  ;
        case COLOR_VERDE   :
        	s=Scalar VERDE_MIN   ;
        	return s  ;
        case COLOR_AZUL    :
        	s=Scalar AZUL_MIN    ;
        	return s  ;
        case COLOR_VIOLETA :
        	s=Scalar VIOLETA_MIN ;
        	return s  ;
        case COLOR_GRIS    :
        	s=Scalar GRIS_MIN    ;
        	return s  ;
        case COLOR_BLANCO  :
        	s=Scalar BLANCO_MIN  ;
        	return s  ;
	}
	return s;
}

