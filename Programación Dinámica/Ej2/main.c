/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 17 de abril de 2022, 18:19
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}

int funcionPD(imatriz2d m, int nmax, int mmax){
   
    for(int i=0;i<=nmax;i++){
        for(int j=0;j<=mmax;j++){
            
            if(j==0){
              m[i][j]=0;  
            }else if(j==1){
               m[i][j]=i; 
            }else{
                m[i][j]=m[i][(int)j/2]+m[i][(int)(j/2.0)];
            }
        }
    }
    
    return m[nmax][mmax];
}

int main(int argc, char** argv) {
    int n=2;
    int m=3;

    
    imatriz2d matrix = icreamatriz2d (n+1, m+1);
    
    printf ("Resultado: %d\n", funcionPD(matrix, n, m));
    mostrar(matrix,n+1,m+1);
    
    ifreematriz2d(&matrix);
    return (EXIT_SUCCESS);
}

