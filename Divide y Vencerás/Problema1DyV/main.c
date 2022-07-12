/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 20 de marzo de 2021, 12:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ivector.h"

#define TAM 100
#define umbral 6

void mostrar (ivector v, int tam){
    for (int i=0;i<tam;i++)
        printf("%d  ", v[i]);
    printf("\n");
}

void cargaVec (ivector v0, ivector v1, ivector v2, int tam){
    int j=0;
    for (int i=0; i<tam; i++){
        if (i<tam/2)
            v1[i]=v0[i];
        else{
            v2[j]=v0[i];
            j++;
        }
    }
}

void burbujaMejor(ivector v, int primPos, int ultPos) {
    int i, j, aux, ordenado=1;
    for(i=primPos; i<ultPos && ordenado; i++){
        ordenado=0;
        for(j=primPos; j<ultPos-1; j++){ //ultPos-1 para no salirnos del vector cuando comparamos con v[j+1]
            if (v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                ordenado=1;
                //mostrar(v, TAM);
            }
        }
    }
}

void mergesort (ivector v, int tam, double *tiempo){
    if (tam <= umbral){
        clock_t t1=clock();
        burbujaMejor (v, 0, tam);
        clock_t t2=clock();
        double diff= (double)(t2 - t1)/CLOCKS_PER_SEC;
        *tiempo+=diff;
    }else{
        ivector u=icreavector(tam/2);
        ivector w=icreavector(tam-(tam/2));  //por si fuera impar el tamaño
        
        cargaVec(v,u,w,tam); //O(n)
        mergesort(u, tam/2, tiempo);
        mergesort(w, tam-(tam/2), tiempo); //O(log n)
        merge(v,u,w,tam); //O(n)
        
        ifreevector(&u);
        ifreevector(&w);
    }
    
}

void merge(ivector v0, ivector v1, ivector v2, int tam){
    int i=0, j=0, k=0;
    while (i<tam/2 && j<tam-(tam/2)){
        if (v1[i]<=v2[j]){
            v0[k]=v1[i];
            i++;
            k++;
        }else{
            v0[k]=v2[j];
            j++;
            k++;
        }
    }
    
    if(i==tam/2){
        for (i=j; i<tam-(tam/2); i++){
            v0[k]=v2[i];
            k++;
        }
    }else{
        for (j=i; j<tam/2; j++){
            v0[k]=v1[j];
            k++;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    ivector v = icreavector(TAM);
    double tiempo=0;

    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }
    printf("Vector original: ");
    mostrar(v, TAM);
    clock_t t3=clock();
    mergesort(v, TAM, &tiempo);
    clock_t t4=clock();
    double diff= (double)(t4 - t3)/CLOCKS_PER_SEC;
    //printf("%.16g milisegundosTA\n", tiempo * 1000.0);
    //printf("%.16g milisegundos\n", diff * 1000.0);
    
    printf("Vector ordenado: ");
    mostrar (v,TAM);
    
    ifreevector (&v);

    return (EXIT_SUCCESS);
}

