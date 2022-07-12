/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 23 de marzo de 2021, 11:39
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

#define TAM 8
#define umbral 1

/*
 * 
 */

void mostrar (imatriz2d m, int tam){
    for (int f=0;f<tam;f++){
        for (int c=0; c<tam; c++){
            printf("%d  ", m[f][c]);
        }
        printf("\n");
    }
}


void cargaMatriz (imatriz2d m, imatriz2d m1, imatriz2d m2, imatriz2d m3, imatriz2d m4, int tam){
    int nf1=0,nc1=0,nf2=0,nc2=0,nf3=0,nc3=0,nf4=0,nc4=0;
    for (int f=0; f<tam; f++){
        for (int c=0; c<tam; c++){
            if (f>=tam/2 && c>=tam/2){
                if (nc4+1==tam/2){
                    m4[nf4][nc4]=m[f][c];
                    nf4++;
                    nc4=0;
                }else{
                    m4[nf4][nc4]=m[f][c];
                    nc4++;
                }
            }else if (f>=tam/2 && c<tam/2){
                if (nc3+1==tam/2){
                    m3[nf3][nc3]=m[f][c];
                    nf3++;
                    nc3=0;
                }else{
                    m3[nf3][nc3]=m[f][c];
                    nc3++;
                }
            }else if (f<tam/2 && c>=tam/2){
                if (nc2+1==tam/2){
                    m2[nf2][nc2]=m[f][c];
                    nf2++;
                    nc2=0;
                }else{
                    m2[nf2][nc2]=m[f][c];
                    nc2++;
                }
            }else{
                if (nc1+1==tam/2){
                    m1[nf1][nc1]=m[f][c];
                    nf1++;
                    nc1=0;
                }else{
                    m1[nf1][nc1]=m[f][c];
                    nc1++;
                }
            }
        }
    }
    
}

void sumaPorPartes (imatriz2d m, int tam, int *sumaAcumulada){
    //mostrar(m,tam);
    for (int f=0; f<tam; f++){
        for (int c=0; c<tam; c++){
            *sumaAcumulada+=m[f][c];
        }
    }
}

int suma (imatriz2d m, int tam, int *sumaAcumulada){
    if (tam<=umbral){
        sumaPorPartes(m, tam, sumaAcumulada);
        return *sumaAcumulada;
        
    }else{
        imatriz2d m1 = icreamatriz2d (tam/2, tam/2);
        imatriz2d m2 = icreamatriz2d (tam/2, tam/2);
        imatriz2d m3 = icreamatriz2d (tam/2, tam/2);
        imatriz2d m4 = icreamatriz2d (tam/2, tam/2);
        cargaMatriz(m,m1,m2,m3,m4,tam);
        
        suma(m1, tam/2, sumaAcumulada);
        suma(m2, tam/2, sumaAcumulada);
        suma(m3, tam/2, sumaAcumulada);
        suma(m4, tam/2, sumaAcumulada);
        
        ifreematriz2d(&m1);
        ifreematriz2d(&m2);
        ifreematriz2d(&m3);
        ifreematriz2d(&m4);
    }
    return *sumaAcumulada;
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d (TAM, TAM);
    int sumaAcumulada=0;
    printf("Introduce los elementos de la matriz: ");
    m[0][0]=1;
    m[0][1]=-3;
    m[0][2]=2;
    m[0][3]=-5;
    m[1][0]=0;
    m[1][1]=9;
    m[1][2]=-4;
    m[1][3]=-7;
    m[2][0]=8;
    m[2][1]=-2;
    m[2][2]=-5;
    m[2][3]=6;
    m[3][0]=2;
    m[3][1]=0;
    m[3][2]=4;
    m[3][3]=-6;
    
    /*for (int f=0; f<TAM; f++){
        for (int c=0; c<TAM; c++){
            scanf("%d", &m[f][c]);
        }
    }*/
    int sumaTotal=suma(m, TAM, &sumaAcumulada);
    if (sumaTotal==0){
        printf ("La suma de todos los elementos de la matriz da 0");
    }else{
        printf ("La suma de todos los elementos de la matriz NO da 0");
    }
    
    ifreematriz2d(&m);
    return (EXIT_SUCCESS);
}

