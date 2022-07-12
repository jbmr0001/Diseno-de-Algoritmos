/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 11 de mayo de 2022, 22:19
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define numMonedas 8
#define cantMonedas 5


void mostrar(imatriz2d m, int nfi, int nco) {
    for (int i = 0; i < nfi; i++) {
        for (int j = 0; j < nco; j++) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mostrarV(ivector v,int n){
    for(int i=0;i<n;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

int factible(ivector v,int cantidad,ivector monedas){

    for(int i=0;i<8;i++){
        //printf("%i ",v[i]);
        if(v[i]>5){
            return 0;
        }
    }
    if(calculaCantidad(v,8,monedas)>cantidad){
        return 0;
    }
    return 1;
}
int calculaCantidad(ivector v,int pos,ivector monedas){
    int suma=0;
    for(int i=0;i<pos;i++){
        suma+=v[i]*monedas[i];
    }
    return suma;
}

int contarMonedas(ivector v,int pos,ivector monedas){
    int suma=0;
    for(int i=0;i<pos;i++){
        suma+=v[i];
    }
    return suma;
}

void funcion(ivector v,int cantidad,ivector monedas,int *valorMejor,int cantidadOriginal){
    if (cantidad == 0) {
        int cant=contarMonedas(v,8,monedas);
        printf("monedas=%i monedasmejor=%i ",cant,*valorMejor);
        printf("%i \n",calculaCantidad(v,8,monedas)); 
        mostrarV(v,8);
        if(cant<*valorMejor){
            printf("\n------------MEJOR ACTUAL----------\n");
            printf("monedas=%i monedasmejor=%i ",cant,*valorMejor);
            printf("%i \n",calculaCantidad(v,8,monedas));
            mostrarV(v,8);
            printf("\n------------MEJOR ACTUAL----------\n");
           *valorMejor=cant;
        }
       
    }else{
    
        for (int i = 7; i >= 0; i--) {
            if(cantidad>=monedas[i]){
                v[i]++;
                if(factible(v,cantidadOriginal,monedas)==1){
                    funcion(v,cantidad-monedas[i],monedas,valorMejor,cantidadOriginal);
                    v[i]--;
                }   

            }
        }
    }
}
int main(int argc, char** argv) {
    ivector monedas=icreavector(numMonedas);
    monedas[0]=1;
    monedas[1]=2;
    monedas[2]=5;
    monedas[3]=10;
    monedas[4]=20;
    monedas[5]=50;
    monedas[6]=100;
    monedas[7]=200;
    ivector sol=icreavector(8);
    for(int i=0;i<8;i++){
        sol[i]=0;
    }
    int cantidad=600;
    int mininoMonedas=99;
    funcion(sol,cantidad,monedas,&mininoMonedas,cantidad);
    ifreevector(&sol);
    ifreevector(&monedas);
    return (EXIT_SUCCESS);
}

