/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 13 de abril de 2021, 9:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d.h"
#include "ivector.h"
#include <stdbool.h>

#define nf 3
#define nc 10

void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}

int maxPlazo (imatriz2d m, int ncol){
    int maximo=m[1][0];
    for (int i=1; i<ncol; i++){
        if (maximo<m[1][i]){
            maximo=m[1][i];
        }
    }
    return maximo;
}

void burbujaMejor(imatriz2d m, int primPos, int ultPos) {
    int i, j, aux, ordenado=1;
    for(i=primPos; i<ultPos && ordenado; i++){
        ordenado=0;
        for(j=primPos; j<ultPos-1; j++){ //ultPos-1 para no salirnos del vector cuando comparamos con v[j+1]
            if (m[2][j]<m[2][j+1]){
                aux=m[0][j];
                m[0][j]=m[0][j+1];
                m[0][j+1]=aux;
                aux=m[1][j];
                m[1][j]=m[1][j+1];
                m[1][j+1]=aux;
                aux=m[2][j];
                m[2][j]=m[2][j+1];
                m[2][j+1]=aux;
                ordenado=1;
            }
        }
    }
}

//Recorremos n-1 veces y vamos comparando x1 con x1+1 empezamos desde 1 hasta n-1
void burbujaMejorada(ivector v, int n) {
    bool flag;
    int aux;
    for (int i = 1; i < n; i++) {
        //printf("%i:", v[i]);
        flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j]; //Proceso de cambio
                v[j] = v[j + 1];
                v[j + 1] = aux;
                flag = true;
            }
            if (flag == false)break;
        }
    }

};

/* Brassard:
 * k = tareas acumuladas
 * d = plazos
 * j = secuencia optima
 * r = tarea
 * m = variable aux
 * n = numero tareas
 */

int heuristicaBrassard(imatriz2d m, int ncol, ivector v, int *k){
    int r, beneficio=0;
    *k=v[1]=1;
    beneficio+=m[2][v[1]];
    for (int i=2; i<=ncol; i++){
        r=*k;
        while (r>0 && m[1][r]>m[1][i] && m[1][r]>r){
            r=r-1;
        }
        if (m[1][i]>r){
            for (int j=*k; j>=r+1; j--){
                v[j+1]=v[j];
            }
            v[r+1]=i;
            beneficio+=m[2][v[r+1]];
            *k=*k+1;
        }
    }
    return beneficio;
}

int heuristicaInvent(imatriz2d m, int ncol, ivector v){
    
    int maximoTiempoLimite=maxPlazo(m, ncol);
    printf("%i",maximoTiempoLimite);
    int beneficio=0;
    float minimo;
    int posMinimo;
    float proporcion;
    ivector repartidos = icreavector (ncol);
    //vector auxiliar 0 si no esta usado 1 si esta usado
    for (int i=1; i<ncol; i++){
        repartidos[i]=0;
    }
    
    for (int instante=0; instante<maximoTiempoLimite; instante++){//por cada tiempo limite buscamos el menor proporcion
        minimo=INT_MAX;
        for (int j=1; j<ncol; j++){
            proporcion=(float)m[1][j]/m[2][j];//dividimos tiempo limite entre coste
            //si pos no usada y si minimo y si tiempo limite mayor o igual del k actual
            if (proporcion<=minimo && repartidos[j]==0 && m[1][j]>instante){
                minimo=proporcion;  
                posMinimo=j;
            } 
        }
        repartidos[posMinimo]=1;
        printf("%f coje final \n \n",minimo);
        beneficio=beneficio+m[2][posMinimo];
        v[instante]=m[0][posMinimo];
    }
    return beneficio;
    ifreevector(&repartidos);
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d (nf, nc);
    ivector v = icreavector (nc);
    int k;
    int bene;
    
    m[0][0]=0;
    m[0][1]=1;
    m[0][2]=2;
    m[0][3]=3;
    m[0][4]=4;
    m[0][5]=5;
    m[0][6]=6;
    m[0][7]=7;
    m[0][8]=8;
    m[0][9]=9;
    m[1][0]=0;
    m[1][1]=1;
    m[1][2]=5;
    m[1][3]=5;
    m[1][4]=6;
    m[1][5]=6;
    m[1][6]=4;
    m[1][7]=4;
    m[1][8]=2;
    m[1][9]=2;
    m[2][0]=0;
    m[2][1]=60; //0'016
    m[2][2]=70; //0'071
    m[2][3]=80; //0'062
    m[2][4]=20; //0'3
    m[2][5]=20; //0'3
    m[2][6]=30; //0'13
    m[2][7]=50; //0'08
    m[2][8]=50; //0'04
    m[2][9]=90; //0'022
    mostrar(m,nf,nc);
    burbujaMejor(m,1,nc);
    mostrar(m,nf,nc);
    
    //bene=heuristicaBrassard(m, nc, v, &k);
    bene=heuristicaInvent(m, nc, v);
    
    printf ("Secuencia óptima: ");
    for (int i=0; i<8; i++){  //hay que cambiar el rango dependiendo de la heuristica, i=0; i<k -> invent, i=1; i<=k -> Brassard
        printf ("%d ", v[i]);
    }
    printf ("Beneficio: %d", bene );
    
    
    //mostrar(m,nf,nc);
    ifreematriz2d(&m);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

