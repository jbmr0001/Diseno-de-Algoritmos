/*************************imat2d.c****************************/
/*              Módulo en C para uso de objetos              */
/*                    Matriz 2D DE ENTEROS                   */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

imatriz2d icreamatriz2d(int nf, int nc) {
	imatriz2d m;
	unsigned datasize = nc * nf * sizeof (int);
	unsigned indexsize = nf * sizeof (void *);
	int i;

	if ((m=(imatriz2d)malloc(indexsize)) == NULL){
		fprintf(stderr, "icreamatriz: No hay memoria.\n");
		exit(1);
	}
	if ((m[0]=(int *)malloc(datasize))== NULL){
		fprintf(stderr, "icreamatriz: No hay memoria.\n");
		exit(1);
	}
	for(i=1;i<nf;i++) (m)[i]= (m)[i-1] + nc;
	return(m);
}

/*************************************************************/

void ifreematriz2d (imatriz2d *matriz2d) {

	if (*matriz2d){
		if ((*matriz2d)[0]) free ((*matriz2d)[0]);
		free (*matriz2d);
		*matriz2d=NULL;
	}
}
