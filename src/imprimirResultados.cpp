/*
 * imprimirResultados.cpp
 *
 *  Created on: 28 de jun. de 2016
 *      Author: agus
 */

#include <stdio.h>
#include "typedefs.h"

#define POSICION_TOLERANCIA 2

char* parsear (color_t);
estado_t ordenarResist(structColor_t *);


//////////////////////////////////////////

estado_t imprimirResultados (img_t *img){
	if (ordenarResist(img->resist)!=OK)
		return ERROR_ORDENAR;

    printf ( parsear (img->resist[POSICION_TOLERANCIA].color),
    		(short)img->resist[0].color,
			(short)img->resist[1].color,
			(short)img->resist[3].color);


    return OK;
}


/////////////////////////////////////////

char* parsear(color_t color){

    switch (color){
        case COLOR_NEGRO:
			return "La resistencia es %hd%hd Ohms con una tolerancia del %hd%%\n";
        case COLOR_MARRON:
            return "La resistencia es %hd%hd0 Ohms con una tolerancia del %hd%%\n";
        case COLOR_ROJO:
            return "La resistencia es %hdK%hd Ohms con una tolerancia del %hd%%\n";
        case COLOR_NARANJA:
            return "La resistencia es %hd%hdK Ohms con una tolerancia del %hd%%\n";
        case COLOR_AMARILLO:
            return "La resistencia es %hd%hd0K Ohms con una tolerancia del %hd%%\n";
        case COLOR_VERDE:
            return "La resistencia es %hdM%hd Ohms con una tolerancia del %hd%%\n";
        case COLOR_AZUL:
            return "La resistencia es %hd%hdM Ohms con una tolerancia del %hd%%\n";
        case COLOR_VIOLETA:
            return "La resistencia es %hd%hd0M Ohms con una tolerancia del %hd%%\n";
        case COLOR_GRIS:
            return "La resistencia es %hdG%hd Ohms con una tolerancia del %hd%%\n";
        case COLOR_BLANCO:
            return "La resistencia es %hd%hdG Ohms con una tolerancia del %hd%%\n";
        default:
            return "Error de lectura\n";
    }
}

estado_t ordenarResist(structColor_t *v){

	size_t cantidad=sizeof(v)/sizeof(v[1]);//revisar!!!!!

	unsigned short i,j;
	structColor_t aux;

	for(i=0;i<4-1;i++){

		for(j=i+1;j<4;j++){

			if(v[i].coordX > v[j].coordX){
				//copio miembro a miembro
				aux.color=v[i].color;
				aux.coordX=v[i].coordX;

				v[i].color=v[j].color;
				v[i].coordX=v[j].coordX;

				v[j].color=aux.color;
				v[j].coordX=aux.coordX;

			}
		}

	}

	return OK;
}

