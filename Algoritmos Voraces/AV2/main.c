/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 24 de marzo de 2022, 0:36
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#define TAM 5

void mostrar (ivector v, int tam){
    for (int f=0;f<tam;f++){
            printf("%d   ", v[f]);  
        
    }
    printf("\n");
}

/**
 * @Brief Función de comparación para el qsort
 * @param a
 * @param b
 * @return 
 */
int cmpfunc(const void * a, const void * b) {
    return ( *(int*) a - *(int*) b);
}

/**
 * @brief, método de selección 
 * @post, los vectores debem tener igual tamaño
 * @param A, vector de elementos
 * @param B, vector de elementos
 * @param tam, tamaño de los vectores
 * @param pos, posición anterior
 * @return devuelve el elemento más optimo en caso de existir
 */
int seleccion(ivector v2, int tam, int elem) {
    for (int i = 0; i < tam; i++) {
        //Comprueba si es factible 
            if (elem <= v2[i]) { 
                return i;
        }
    }
    return -1;
}

void funcionSolucion(ivector v1,ivector v2,int tam){
    mostrar(v2,tam);
    int suma=0;
    for(int i=0;i<tam;i++){
        if((v1[i]<=v2[i])){
            suma=suma+v1[i];
        }
    }
    printf("%i",suma);
   
}

void voraz(ivector v1, ivector v2, int tam){
    int resultadoSeleccion=0;
    int posicionInicialesV1=0;//para contar los menores

    int pos = tam-1; //Empieza en la posición 0, del vector A
    ivector vectorSolucion=icreavector(tam);
    //Bucle voraz
    while(pos >= 0){
 
        resultadoSeleccion = seleccion(v2, tam, v1[pos]);
        if(resultadoSeleccion==-1){
            //printf("%i no puedeer %i \n",v1[pos],v2[posicionInicialesV1]);
            vectorSolucion[pos]=v2[posicionInicialesV1];
            v2[posicionInicialesV1]=0;
            posicionInicialesV1++;
        }else{
            //printf("%i Si puedeer %i \n",v1[pos],v2[resultadoSeleccion]);
            vectorSolucion[pos]=v2[resultadoSeleccion];
            v2[resultadoSeleccion]=0;
            //h++;
        }
        pos--;
        
    }
    v2=vectorSolucion;
    
    funcionSolucion(v1,v2,tam);
       
}



/*
 * 
 */
int main(int argc, char** argv) {
    ivector v1 = icreavector (TAM);
    ivector v2 = icreavector (TAM);
    
    v1[0]=1;
    v1[1]=4;
    v1[2]=6;
    v1[3]=7;
    v1[4]=9;
    
    v2[0]=3;
    v2[1]=2;
    v2[2]=4;
    v2[3]=6;
    v2[4]=5;
    qsort(v2, TAM, sizeof (int), cmpfunc);
    
    voraz(v1,v2,TAM);
    
    ifreevector(&v1);
    ifreevector(&v2);
    
    return (EXIT_SUCCESS);
}

