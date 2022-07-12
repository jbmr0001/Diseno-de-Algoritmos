/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 21 de abril de 2022, 18:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d.h"

void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}

void burbujaMejor(imatriz2d m, int primPos, int ultPos) {    
    int i, j, aux, ordenado=1; 
    for(i=primPos; i<ultPos && ordenado; i++){
        ordenado=0;
        for(j=primPos; j<ultPos-1; j++){ //ultPos-1 para no salirnos del vector cuando comparamos con v[j+1]
            if (m[0][j]>m[0][j+1]){
                aux=m[0][j];
                m[0][j]=m[0][j+1];
                m[0][j+1]=aux;
                ordenado=1;
            }
        }
    }
}

int monedas (imatriz2d m, imatriz2d aux, int aCambiar, int numMonedas){
    int compara1, compara2;
    int aCambiar2=aCambiar;
    for (int i=0; i<=numMonedas; i++){//primera columna a 0
        m[i][0]=0;
        aux[1][i]=0; //aprovechamos para poner a 0 inicialmente los valores correspondientes al numero de monedas que necesitamos
    }
    
    for (int i=1; i<=aCambiar; i++){//primera fila a 0 menos la primera posicion
        m[0][i]=9999;
    }
    
    for (int i=1; i<=numMonedas; i++){
        for (int j=1; j<=aCambiar; j++){
            if (aux[0][i]>j){
                m[i][j]=m[i-1][j];
            }else{
                compara1=(1+m[i][j-aux[0][i]]);
                compara2=m[i-1][j];
                if (compara1<compara2){
                    m[i][j]=1+m[i][j-aux[0][i]];
                }else{
                    m[i][j]=m[i-1][j];
                }
            }
        }
    }
    
    int k=numMonedas;
    while(aCambiar2>0){
        if (aCambiar2>=aux[0][k]){
            aCambiar2=aCambiar2-aux[0][k];
            aux[1][k]++;
        }else {
            k--;
        }          
    }
     
    return m[numMonedas][aCambiar];
    
}

int main(int argc, char** argv) {
    int aCambiar;
    int tam;
    aCambiar=12;
    tam=3;
  
    imatriz2d m = icreamatriz2d (tam+1,aCambiar+1); 
    imatriz2d aux = icreamatriz2d (2, tam+1); //matriz con el tipo de monedas y el contado de cada una
                                              //requisito: estar ordenado ascendentemente el tipo de monedas
    aux[0][0]=0;
    aux[0][1]=5;
    aux[0][2]=10;
    aux[0][3]=1;
    
    
    burbujaMejor(aux, 1, tam+1); //ordenamos las monedas para que estén en orden ascendente
    
    printf ("El numero de monedas que necesitamos es %d \n", monedas(m, aux,aCambiar,tam));
    for (int i=1; i<=tam; i++){
        printf("Moneda de %d --> %d moneda/s\n", aux[0][i], aux[1][i]);
    }
    
    printf ("Matriz resultante: \n");
    mostrar (m, tam+1, aCambiar+1);
    
    ifreematriz2d (&m);
    ifreematriz2d (&aux);
    
    return (EXIT_SUCCESS);
}


