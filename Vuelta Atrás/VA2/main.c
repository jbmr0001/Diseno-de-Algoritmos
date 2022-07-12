/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 11 de mayo de 2022, 19:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define nf 5
#define nc 5

/*
 * 
 */

void mostrar(imatriz2d m, int nfi, int nco) {
    for (int i = 0; i < nfi; i++) {
        for (int j = 0; j < nco; j++) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void laberintoNormal(imatriz2d m, int x, int y, int *encontrado) {
    printf("x=%i y=%i \n",x,y);
    if (m[x][y] == 4) {
        *encontrado = 1;
    } else if (m[x][y] != 1 && m[x][y] != 2) {//factible? s no es visitado ni obataculo

        m[x][y] = 2; //visitamos
        if (*encontrado != 1) {
            if(y-1>=0){
                laberintoNormal(m,x,y - 1, encontrado);
            }
        }
        
        if(*encontrado!=1){
           if(x+1<nc){
               laberintoNormal(m,x+1,y,encontrado); 
           }
        }
        
        if(*encontrado!=1){
            if(y+1<nc){
               laberintoNormal(m,x,y+1,encontrado); 
            }
        }

        if(*encontrado!=1){
           if(x-1>=0){
            laberintoNormal(m,x-1,y,encontrado); 
           }
        }
        if(*encontrado!=1){
           m[x][y]=0;//vuelta atras 
        }
    }

}

void laberintoEdit(imatriz2d m, int x, int y,int numCasillas,int *casillasMejor,imatriz2d sol) {
    //printf("x=%i y=%i \n",x,y);
    //printf("num=%i max=%i \n",numCasillas,*casillasMejor);
    if (m[x][y] == 4) {
        //*encontrado = 1;
        if(numCasillas<*casillasMejor){
            printf("Camino mejor encontrado \n");
            *casillasMejor=numCasillas;
             mostrar(m, nf, nc);
             //copiamos
             for (int i = 0; i < nf; i++) {
                for (int j = 0; j < nc; j++) {
                    sol[i][j]=m[i][j];
                } 
            }
             
        }

    } else if (m[x][y] != 1 && m[x][y] != 2) {//factible? s no es visitado ni obataculo

        m[x][y] = 2; //visitamos
        //mostrar(m, nf, nc);
        numCasillas++;
        //if (*encontrado != 1) {
            if(y-1>=0){
                laberintoEdit(m,x,y - 1,numCasillas,casillasMejor,sol);
            }
        //}
        
        //if(*encontrado!=1){
           if(x+1<nc){
               laberintoEdit(m,x+1,y,numCasillas,casillasMejor,sol);
           }
        //}
        
        //if(*encontrado!=1){
            if(y+1<nc){
               laberintoEdit(m,x,y+1,numCasillas,casillasMejor,sol); 
            }
        //}

        //if(*encontrado!=1){
           if(x-1>=0){
            laberintoEdit(m,x-1,y,numCasillas,casillasMejor,sol);  
           }
        //}
        //if(*encontrado!=1){
           m[x][y]=0;//vuelta atras 
        //}
    }

}

void prueba(int *encontrado) {
    printf("%i", *encontrado);
}

int main(int argc, char** argv) {
    imatriz2d m = icreamatriz2d(nf, nc);
    m[0][0] = 3;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 1;
    m[0][4] = 0;
    m[1][0] = 1;
    m[1][1] = 0;
    m[1][2] = 0;
    m[1][3] = 0;
    m[1][4] = 4;
    m[2][0] = 0;
    m[2][1] = 1;
    m[2][2] = 0;
    m[2][3] = 1;
    m[2][4] = 0;
    m[3][0] = 0;
    m[3][1] = 1;
    m[3][2] = 0;
    m[3][3] = 1;
    m[3][4] = 0;
    m[4][0] = 0;
    m[4][1] = 0;
    m[4][2] = 0;
    m[4][3] = 0;
    m[4][4] = 0;
    imatriz2d sol = icreamatriz2d(nf, nc);
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            sol[i][j]=0;
        } 
    }
    int encontrado = 0;
    //prueba(&encontrado);
    //mostrar(m, nf, nc);
    int casillasMejor=99;
    //laberintoNormal(m, 0, 0, &encontrado);
    laberintoEdit(m,0,0,0,&casillasMejor,sol);
    //mostrar(m, nf, nc);
    printf("El mejor camino es \n");
    mostrar(sol, nf, nc);
    ifreematriz2d(&m);
    ifreematriz2d(&sol);
    return (EXIT_SUCCESS);
}

