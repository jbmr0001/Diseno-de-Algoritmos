/*************************imat2d.h****************************/
/*         Módulo de cabeceras para uso de objetos           */
/*              ARRAY DINAMICO  2D DE ENTEROS                */
/*************************************************************/

#ifndef IMATRIZ2D

#define IMATRIZ2D

typedef int **imatriz2d;

imatriz2d icreamatriz2d(int nf, int nc);
void ifreematriz2d (imatriz2d *matriz2d);

#endif
