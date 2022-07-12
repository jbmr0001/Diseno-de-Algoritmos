/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 19 de abril de 2021, 8:35
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define NC 10

/*
 * 
 */

void burbujaMejor(imatriz2d m, int primPos, int ultPos) {
    int i, j, aux, ordenado=1;
    for(i=primPos; i<ultPos && ordenado; i++){
        ordenado=0;
        for(j=primPos; j<ultPos-1; j++){ //ultPos-1 para no salirnos del vector cuando comparamos con v[j+1]
            if (m[1][j]<m[1][j+1]){
                aux=m[0][j];
                m[0][j]=m[0][j+1];
                m[0][j+1]=aux;
                aux=m[1][j];
                m[1][j]=m[1][j+1];
                m[1][j+1]=aux;
                ordenado=1;
            }
        }
    }
}

void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}



void heuristica (imatriz2d bombillas, imatriz2d vectorSolucion, ivector vectorDuraciones, int nc, int ncVectorSolucion, int orden){
    int posActual=0;
    burbujaMejor(bombillas, 0, nc);
    
    //inicializamos vector de duraciones
    for (int i=0; i<nc; i++){
        vectorDuraciones[i]=bombillas[1][i];
    }
    //inicializamos
    for (int i=0; i<ncVectorSolucion; i++){
        for (int j=0; j<orden+1; j++){
            vectorSolucion[j][i]=0;         //m0[j][i] para recorrer la matriz verticalmente
        }
    }
    
    for (int i=0; i<ncVectorSolucion; i++){//por cada columna
        vectorSolucion[0][i]=i+1;//pollada para contar indice
        for (int j=1; j<orden+1; j++){ //por cada orden
            int salir=0;
            while(salir!=1){
                salir=0;
                if (vectorDuraciones[posActual]>0){
                    vectorSolucion[j][i]=bombillas[0][posActual];
                    salir=1;;
                }else{
                    posActual++;
                }
            }
            vectorDuraciones[posActual]--;
            posActual++;
            
            if (posActual==nc){
                return; //para que termine en cuanto no haya más datos
            }
        }
        posActual=0;
    }
   
}

//ponemos las bombillas que mas duran al principio así aprovechamos al máximo su durabilidad,
//ya que si se quedan al final se malgastarían
int main(int argc, char** argv) {
    int orden;
    imatriz2d m = icreamatriz2d (2, NC);
    ivector vectorDuraciones = icreavector (NC); //vector de duracion de las bombillas
    
    orden=3;
    
    m[0][0]=1;
    m[0][1]=2;
    m[0][2]=3;
    m[0][3]=4;
    m[0][4]=5;
    m[0][5]=6;
    m[0][6]=7;
    m[0][7]=8;
    m[0][8]=9;
    m[0][9]=10;
    m[1][0]=1;
    m[1][1]=4;
    m[1][2]=2;
    m[1][3]=3;
    m[1][4]=1;
    m[1][5]=1;
    m[1][6]=3;
    m[1][7]=1;
    m[1][8]=5;
    m[1][9]=2;
   
    int suma=0;
    for (int i=0; i<NC; i++){
        suma+=m[1][i];
    }
    
    int ncM0=suma/orden+1;
    imatriz2d m0 = icreamatriz2d (orden+1, ncM0);
    
    heuristica (m, m0, vectorDuraciones, NC, ncM0, orden);
    
    //mostrar (m0, orden+1, ncM0);
    for (int i=0; i<ncM0; i++){
        printf("Bombillas dia %d: ", m0[0][i]);
        for (int j=1; j<orden+1; j++){ 
            printf ("%d ", m0[j][i]);
        }
        printf("\n");
    }
    
    ifreematriz2d(&m);
    ifreematriz2d(&m0);
    ifreevector(&vectorDuraciones);
    return (EXIT_SUCCESS);
}

