#include <stdio.h>

#include "mensajes.h"
#include "typedefs.h"
#include "manejoImagen.h"

#define ARGUMENTOS 3



int main (int argc, char * argv[]){
    img_t Img;

    if(argc!=ARGUMENTOS){
        fprintf(stderr,"%s\n",MSJ_ERROR_INVOCACION);
        return ERROR_INVOCACION;
    }

    if(cargarImg(argv[POSICION_NOMBRE_IMAGEN],&Img)!=OK){
        fprintf(stderr,"%s\n",MSJ_ERROR_CARGA_IMG);
        return ERROR_CARGA_IMG;
    }
////////////////////////////////////////////////////
    if(procesarImg(&Img, argv[POSICION_CANTIDAD_BANDAS])!=OK){
        fprintf(stderr,"%s\n",MSJ_ERROR_PROC_IMG);
        return ERROR_PROC_IMG;
    }
///////////////////////////////////////////////////
    if(imprimirResultados(&Img)!=OK){
        fprintf(stderr,"%s\n",MSJ_ERROR_IMPRESION_IMG);
        return ERROR_IMPRESION_IMG;
    }

    return 0;
}
