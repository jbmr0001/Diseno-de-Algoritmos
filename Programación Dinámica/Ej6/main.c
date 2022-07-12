/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 21 de abril de 2022, 22:13
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#define num 2

void floyd(imatriz2d adyacencia, imatriz2d resultados,imatriz2d padres, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultados[i][j] = adyacencia[i][j];
            padres[i][j]=0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(resultados[i][k]+resultados[k][j]<resultados[i][j]){//lo modificamos para guardar la maxima anchura
                    resultados[i][j]=resultados[i][k]+resultados[k][j];
                    //modificacion guardar vertice
                    padres[i][j]=k;
                }
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
    printf("\n");
}
/*
 * 
 */
int main(int argc, char** argv) {
    imatriz2d d=icreamatriz2d(3,3);
    d[0][0]=0;
    d[0][1]=1;
    d[0][2]=2;
    d[1][0]=0;
    d[1][1]=0;
    d[1][2]=10;
    d[2][0]=1;
    d[2][1]=5;
    d[2][2]=0;
    
    imatriz2d D=icreamatriz2d(3,3);
    imatriz2d padres=icreamatriz2d(3,3);
    floyd(d,D,padres,3);
    
    mostrar(d,3,3);
    mostrar(D,3,3);
    mostrar(padres,3,3);
    return (EXIT_SUCCESS);
}

