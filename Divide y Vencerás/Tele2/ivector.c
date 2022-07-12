/*************************ivector.c***************************/
/*             Módulo en C para uso de objetos               */
/*                      VECTOR DE ENTEROS                    */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

ivector icreavector(int tam) {
	ivector v;

	if ( (v=(ivector)malloc(tam*sizeof(int))) == NULL){
		fprintf(stderr, "icreavector: No hay memoria.\n");
		exit(1);
	}
	return(v);
}

/*************************************************************/

void ifreevector (ivector *v) {

	if (*v){
		free (*v);
		*v=NULL;
	}
}
