/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 29 de marzo de 2022, 19:41
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
#define TE 12
#define N 4

/**
 * Función para mostrar la matriz
 * @param m imatriz a mostrar
 * @param nf Entero con el número de filas
 * @param nc Entero con el número de columnas
 */
void mostrar(imatriz2d m,int nf,int nc){
    for(int i=0;i<nf;i++){
        for(int j=0;j<nc;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }
}

/**
 * Función principal
 * @param sellos ivector con los sellos
 * @param n Entero con el tamaño del vector de sellos
 * @param T Entero con la cantidad a franquear
 * @return 
 */
int formas(ivector sellos,int n,int T){
    int nc=T+1;
    int nf=n+1;
    imatriz2d m=icreamatriz2d(nf,nc);
    for(int i=0;i<nc;i++){//Inicializamos a 0 primera fila
        m[0][i]=0;
    }
    
    for(int i=1;i<nf;i++){//Inicializamos a 1 primera columna menos la primera posición
        m[i][0]=1;
    }
       
    for(int i=1;i<nf;i++){//Rellanamos la matriz aplicando los pasos vistos en clase
        int si=sellos[i-1];
        for(int j=1;j<nc;j++){
            if(si>j){
                m[i][j]=m[i-1][j];//Posicion de arriba
            }else{
                m[i][j]=m[i-1][j]+m[i][j-si];
            }
        }
    }
    mostrar(m,nf,nc);
    int formas=m[n][T];//guardamos en un entero el resultado antes de eliminar la matriz
    ifreematriz2d(&m);
    return formas;
}
/*
 * 
 */
int main(int argc, char** argv) {
    ivector n=icreavector(4);
    n[0]=1;
    n[1]=5;
    n[2]=10;
    n[3]=20;
    printf("Se puede de %i formas",formas(n,N,TE));
    ifreevector(&n);
    return (EXIT_SUCCESS);
}

