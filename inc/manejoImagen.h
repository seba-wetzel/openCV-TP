#ifndef _MANEJOIMG__H
    #define _MANEJOIMG__H

#include "typedefs.h"

estado_t cargarImg(const char *,img_t *);

estado_t procesarImg(img_t*,const char *);

estado_t imprimirResultados(img_t*);

#endif

