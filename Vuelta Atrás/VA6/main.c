/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 12 de mayo de 2022, 16:42
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define num 6
#define letras 8

void mostrarV(ivector v,int n){
    for(int i=0;i<n;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

int factible(ivector v, int n, int paso) {
    if(paso==n-1){
        if(vocalIncluida(v,paso)==1){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 1;
    }
}

int esVocal(int a){
    if(a>=4 && a<9){
        return 1;
    }else{
        return 0;
    }
}

void convertirVocal(ivector v,int n){
    for(int i=0;i<n;i++){
        if(v[i]==1){
            printf("1");
        }else if(v[i]==2){
           printf("2"); 
        }else if(v[i]==3){
            printf("3");
        }else if(v[i]==4){
            printf("A");
        }else if(v[i]==5){
            printf("E");
        }else if(v[i]==6){
            printf("I");
        }else if(v[i]==7){
            printf("O");
        }else if(v[i]==8){
            printf("U");
        }
    }
    printf(" ");
    
}

int vocalIncluida(ivector v,int tam){
    
    for(int i=0;i<tam-1;i++){
        
        if(esVocal(v[i])==1){
            if(esVocal(v[i+1])==1){
                //printf("vocales\n");
                convertirVocal(v,tam);
                return 1;
            }
        }
    }
    return 0;
}



void funcion(ivector v, int n, int paso) {
    //convertirVocal(v,paso);
    if (vocalIncluida(v,paso)==1) {
       //convertirVocal(v,n);
    } else {
        for (int i = 0; i < letras; i++) {
            v[paso] = i;
            if (factible(v, n, paso) == 1) {
                
                funcion(v, n, paso + 1);
            }
        }
    }
}
int main(int argc, char** argv) {
    ivector abc=icreavector(8);
    abc[0]=1;
    abc[1]=2;
    abc[2]=3;
    abc[3]=4;
    abc[4]=5;
    abc[5]=6;
    abc[6]=7;
    abc[7]=8;
    mostrarV(abc,8);
    ivector res=icreavector(5);
    //for(int i=5;i>0;i--){
       funcion(res,5,0); 
    //}
    
    ifreevector(&abc);
    return (EXIT_SUCCESS);
}

