#ifndef _TYPEDEFS__H
    #define _TYPEDEFS__H

#include <opencv2/core/core.hpp>

#define POSICION_NOMBRE_IMAGEN 1
#define POSICION_CANTIDAD_BANDAS 2


using namespace cv;

//typedef char* string;

typedef enum{
    OK,
    ERROR_INVOCACION,
    ERROR_CARGA_IMG,
    ERROR_PROC_IMG,
    ERROR_IMPRESION_IMG,
    ERROR_IMG,
    ERROR_COLOR,
    ERROR_CONVER,
	ERROR_ORDENAR
}estado_t;

typedef enum{
    COLOR_DESCONOCIDO=-1,
    COLOR_NEGRO=0,
    COLOR_MARRON=1,
    COLOR_ROJO=2,
	COLOR_NARANJA=3,
    COLOR_AMARILLO=4,
    COLOR_VERDE=5,
    COLOR_AZUL=6,
    COLOR_VIOLETA=7,
    COLOR_GRIS=8,
    COLOR_BLANCO=9,
    //COLOR_DORADO=10,
    //COLOR_PLATEADO=11,
    COLOR_MAX
}color_t;

typedef struct{
	color_t color;
    int coordX;
}structColor_t;

typedef struct{
    Mat matImg;
    structColor_t resist[4];//para poder ordenarlos, cada color con su coord
}img_t;

#endif
