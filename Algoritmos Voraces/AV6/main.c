/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 20 de abril de 2021, 13:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d.h"
#include "ivector.h"

#define N 5
#define M 3

/*
 * 
 */


void mostrar(ivector v,int tam){
    for(int i=0;i<tam;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

void heuristica (ivector libros, ivector pesoBaldas, ivector librosBalda, int n, int m){
    int baldaMenosPeso;
    int posBalda;
    
    for(int i=0; i<n; i++){//por cada libro
        baldaMenosPeso=INT_MAX;
        for(int j=0; j<m; j++){//buscamos la balda de menor peso
            if (pesoBaldas[j]<baldaMenosPeso){
                baldaMenosPeso=pesoBaldas[j];
                posBalda=j;
            }
        }
        pesoBaldas[posBalda]=pesoBaldas[posBalda]+libros[i];
        librosBalda[i]=posBalda;
    }
}

int main(int argc, char** argv) {
    ivector libros = icreavector (N);
    ivector baldas = icreavector (M);
    ivector librosBal = icreavector (N); //para saber la balda a la que va cada libro
    
    for (int i=0; i<M; i++){
        baldas[i]=0;
    }
    
    libros[0]=4;
    libros[1]=10;
    libros[2]=6;
    libros[3]=5;
    libros[4]=4;
    
    heuristica (libros, baldas, librosBal, N, M);
    
    printf ("Peso de las baldas: \n");
    for (int i=0; i<M; i++){
        printf ("Balda %d --> Peso %d\n", i+1, baldas[i]);
    }
    
    for (int i=0; i<N; i++){
        printf ("Libro %d con peso %d Kg --> Balda %d\n", i+1, libros[i], librosBal[i]+1);
    }
    
    ifreevector (&libros);
    ifreevector (&baldas);
    ifreevector (&librosBal);
    return (EXIT_SUCCESS);
}

