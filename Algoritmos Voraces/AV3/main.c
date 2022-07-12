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
#include <limits.h>
#include "ivector.h"
#include "imatriz2d.h"

#define TAM 10

#define MAX 100  //maximo numero de Nodos

void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}

int Prim (imatriz2d L, imatriz2d minCam, int tamM, int *tamMinCam){
    int T = 0; //coste
    int k;
    int minimo;
    //los dos vectores
    ivector mascerca = icreavector (tamM);
    ivector mindist = icreavector (tamM);
    //inicializamos
    for (int i=1; i<tamM; i++){
        mascerca[i]=0;
        mindist[i]=L[i][0];
    }
    
    for(int i=1; i<tamM; i++){ //Lazo Greedy
        minimo=INT_MAX;
        for (int j=1; j<tamM; j++){
            if (0<=mindist[j] && mindist[j]<minimo){
                minimo=mindist[j];
                k=j;
            }
        }
        T=T+minimo;
        minCam[0][*tamMinCam]=k;
        minCam[1][*tamMinCam]=mascerca[k];
        (*tamMinCam)++;
        mindist[k]=-1;
        for (int j=1; j<tamM; j++){
            if (L[k][j]<mindist[j]){
                mindist[j]=L[k][j];
                mascerca[j]=k;
            }
        }
    }
    
    ifreevector (&mascerca);
    ifreevector (&mindist);
    return T;
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d(TAM, TAM);
    imatriz2d minCam = icreamatriz2d(2, TAM);
    imatriz2d prueba = icreamatriz2d(2, 2);
    ivector vPrueba = icreavector (3);
    
    int tamMinCam=0;
    int costeTotal=0;
    
    for (int i=0; i<TAM; i++){
        for (int j=0; j<TAM; j++){
            m[i][j]=(i+j+2) % 8;
        }
        m[i][i]=INT_MAX;
    }
    
    mostrar(m,10,10);
    
    costeTotal=Prim(m,minCam,TAM,&tamMinCam);

    printf ("Caminos mínimos: ");
    for (int i=0; i<tamMinCam; i++){
        printf("%d --> %d \n" , minCam[0][ i ]+1 , minCam[1][ i ]+1);
    }
    
    printf ("Coste minimo total: %d", costeTotal);
        
    ifreevector (&vPrueba);
    ifreematriz2d (&prueba);
    ifreematriz2d (&m);
    ifreematriz2d (&minCam);
    
    return (EXIT_SUCCESS);
}


