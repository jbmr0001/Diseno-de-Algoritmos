/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 17 de abril de 2022, 20:33
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
void mostrar (imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}

int funcion(imatriz2d matrix,ivector v, int nmax, int mmax){
   
    for(int n=0;n<=nmax;n++){
        for(int m=0;m<=mmax;m++){
            
            if(n==0){
              matrix[n][m]=1;  
            }else if(m==0){
               matrix[n][m]=1; 
            }else if(n<=v[n]){
               
                matrix[n][m]=matrix[n-1][m];
            }else{
                
                int suma=0;
                for(int i=1;i<v[m-1];i++){
                    suma+=matrix[m][n-i];
                }
                matrix[n][m]=suma;
            }
        }
    }
    mostrar(matrix,nmax,mmax);
    return matrix[nmax][mmax];
}
/*
 * 
 */
int main(int argc, char** argv) {
    ivector v=icreavector(5);
     int n=3;
    int m=4;

    
    imatriz2d matrix = icreamatriz2d (n+1, m+1);
    v[0]=0;
    v[1]=5;
    v[2]=0;
    v[3]=1;
    v[4]=3;
    
    funcion(matrix,v,n,m);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

