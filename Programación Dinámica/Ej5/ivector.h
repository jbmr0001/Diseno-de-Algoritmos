/* 
 * File:   ivector.h
 * Author: Pc
 *
 * Created on 17 de abril de 2022, 18:06
 */

/*************************ivector.h***************************/
/*         MÃ³dulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR

typedef int *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif

