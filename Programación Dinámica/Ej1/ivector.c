/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ivector2d.c
 * Author: Pc
 *
 * Created on 17 de abril de 2022, 18:05
 */

/*************************ivector.c***************************/
/*             MÃ³dulo en C para uso de objetos               */
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

