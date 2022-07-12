/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 11 de mayo de 2022, 20:59
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define nf 5
#define nc 5

#define numSitios 5

void mostrar(imatriz2d m, int nfi, int nco) {
    for (int i = 0; i < nfi; i++) {
        for (int j = 0; j < nco; j++) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mostrarV(ivector v, int nfi) {
    for (int i = 0; i < nfi; i++) {
        printf("%i ", v[i]);
    }
    printf("\n");
}

int factible(ivector v, int n, int paso, imatriz2d ady, int *mejorActual) {
    if (paso > 0) {
        if(buscaRepetidos(v,paso)==1){
            //printf("hay repetidos \n");
            return 0;
        }else{
            int actual = v[paso];
            int anterior = v[paso - 1];
            if (ady[actual][anterior] != 0 && ady[anterior][actual] != 0) {
                if(suma(v,paso,ady)>*mejorActual){
                    //printf("Poda \n");
                    return 0;
                }else{
                    return 1;
                }
                
            } else {
                //printf("%i y %i no son adyacentes \n",actual,anterior);
                return 0;
            }
        }
    } else {//caso inicial
        return 1;
    }
}

int suma(ivector v,int paso, imatriz2d ady) {
    int sum = 0;
    for (int i = 0; i < paso; i++) {
        //printf("ady[%i][%i]=%i \n",i,i+1,ady[v[i]][v[i + 1]]);
        sum=sum+ady[v[i]][v[i + 1]];
    }
    //printf("suma%i \n",suma);
    return sum;
}

int buscaRepetidos(ivector v,int paso){
    for (int i = 0; i < paso; i++) {
            if(v[i]==v[paso]){
                return 1;
            }
        
    }
    return 0;
}

void funcion(ivector v, int n, int paso, imatriz2d ady, int *mejorActual) {
    if (paso == n) {
        int sum=suma(v,paso,ady);
        if(sum<*mejorActual){
            mostrarV(v, n);
            printf("suma=%i mejoractual=%i \n",sum,*mejorActual);
            *mejorActual=sum;
        }
    } else {
        for (int i = 0; i < numSitios; i++) {
            v[paso] = i;
            if (factible(v, n, paso, ady, mejorActual) == 1) {
                funcion(v, n, paso + 1, ady, mejorActual);
            }
        }
    }
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d(nf, nc);
    m[0][0] = 0;
    m[0][1] = 3;
    m[0][2] = 4;
    m[0][3] = 1;
    m[0][4] = 1;
    m[1][0] = 3;
    m[1][1] = 0;
    m[1][2] = 2;
    m[1][3] = 1;
    m[1][4] = 8;
    m[2][0] = 4;
    m[2][1] = 2;
    m[2][2] = 0;
    m[2][3] = 1;
    m[2][4] = 0;
    m[3][0] = 1;
    m[3][1] = 1;
    m[3][2] = 1;
    m[3][3] = 0;
    m[3][4] = 6;
    m[4][0] = 1;
    m[4][1] = 8;
    m[4][2] = 0;
    m[4][3] = 6;
    m[4][4] = 0;
    mostrar(m, nf, nc);
    ivector v = icreavector(numSitios);
    int mejorActual = 999;
    funcion(v, numSitios, 0, m, &mejorActual);
    ifreevector(&v);
    ifreematriz2d(&m);
    return (EXIT_SUCCESS);
}

