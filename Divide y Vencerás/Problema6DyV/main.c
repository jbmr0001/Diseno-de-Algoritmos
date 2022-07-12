/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 24 de marzo de 2021, 12:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

#define TAM 4
/*
 * 
 */

void mostrar (imatriz2d m, int nf, int nc){
    for (int f=0;f<nf;f++){
        for (int c=0; c<nc; c++){
            printf("%d  ", m[f][c]);
        }
        printf("\n");
    }
}

void intercambia (imatriz2d m, int i, int j) {
    int aux;

    aux = m[0][i];
    m[0][i] = m[0][j];
    m[0][j] = aux;
    aux = m[1][i];
    m[1][i] = m[1][j];
    m[1][j] = aux;
}

int encuentraPivote (imatriz2d m, int i, int j) {
    int k = i+1;
    int cantidad = m[1][i];
     
    while (( m[1][k] == cantidad ) && ( k <= j )) { //si la cantidad de la posicion 
        k++;                                        //i y k(i+1) son iguales aumentamos                                                   
    }                                               //la k
    
    if ( k <= j ){
       if ( m[1][k] <= cantidad ) { //devolvemos la posicion que tenga menor cantidad
          return i;
       } else {
          return k;
       }
    }
    return -1;   //si los indices se han intercambiado devolvemos -1
}

int reordena ( imatriz2d m, int i, int j, int pivote) {  
    do {             
        intercambia (m, i, j);
        while ( m[1][i] >= pivote ) {         // {1, 2, 3, 4, 5}
            i++;                              //  ^ ->        ^     
        }                                           
        while ( m[1][j] < pivote) {           // {1, 2, 3, 4, 5}
            j--;                              //  ^        <- ^ 
        }
    } while ( i <= j );
    
    return i; 
}

int k_esimo(imatriz2d m, int i, int j, int k){
    int pivote;

    if (i==j)
            return m[0][i];
    else{
        pivote = encuentraPivote(m,i,j);
        if (pivote==-1)
            return m[0][i];

        pivote = reordena(m,i,j, m[1][pivote]);
        
        if (k<pivote)
            return k_esimo(m, i, pivote-1, k);
        else
            return k_esimo(m, pivote, j, k);
    }
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d (2, TAM);
    int pos;
    int c=0, f=0;
    
    while (c<TAM){
        printf ("Introduce el numero de dorsal: ");
        scanf("%d", &m[f][c]);
        f++;
        printf ("Introduce la cantidad de liquido: ");
        scanf("%d", &m[f][c]);
        c++;
        f--;
        /*for (int i=0; i<TAM; i++){
            m[0][i]= i+1;
        }
        for (int i=0; i<TAM; i++){
            m[1][i]= rand() % 1000;
        }*/
    }
    mostrar (m, 2, TAM);

    printf( "\nIntroduce una posicion para saber el dorsal: ");
    scanf("%d", &pos);
    printf("Esa posicion pertenece al dorsal: %d \n", k_esimo(m,0,TAM-1,pos-1));
    printf ("Posiciones ordenadas: ");
    for (int i=0;i<TAM; i++)
        printf( "%d ",m[0][i]);
    
    ifreematriz2d(&m);
    return (EXIT_SUCCESS);
}

