/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 22 de marzo de 2021, 9:58
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define TAM 10
#define umbral 1

/*
 * 
 */

void mostrar (ivector v, int tam){
    for (int i=0;i<tam;i++)
        printf("%d  ", v[i]);
    printf("\n");
}

void busq2Menores (ivector v, int posIni, int posFin, int *minimo1, int *minimo2){ //algoritmo clasico
    int repetido=1;
    for (int i=posIni; i<=posFin; i++){ //<= ya que le estamos dando posiciones no el tamaño real
        if (*minimo1>v[i]){
            *minimo1=v[i];
        }
    }
    for (int i=posIni; i<=posFin; i++){
        if (*minimo1==v[i]){
            repetido=0;
        }
        if (*minimo1!=v[i] && repetido==1 && *minimo2>v[i]){
            *minimo2=v[i];
        }
    }
}

int suma (ivector v, int posIni, int posFin, int *minimo1, int *minimo2, int tam){
    int tama=posFin-posIni+1; // ya que el 0 cuenta como elemento
    if (tama <= umbral){
        busq2Menores (v,posIni, posFin, minimo1, minimo2);
    }else{
        int medio=(posIni+posFin)/2;
        suma (v, posIni, medio, minimo1, minimo2, tam);
        suma (v, medio+1, posFin, minimo1, minimo2, tam);
        if (tam==tama){ //para recorrer el vector en la primera llamada a la funcion habiendo calculado ya los 2 minimos
            int sum=0;
            int repetido1=0, repetido2=0;
            for (int i=0; i<tam; i++){  
                if(*minimo1==v[i] && repetido1==0){
                    repetido1=1;
                }else if(*minimo2==v[i] && repetido2==0){
                    repetido2=1;
                }else if ((*minimo1!=v[i] && *minimo2!=v[i]) || //este if lo ponemos el último ya que
                        (*minimo2==v[i] && repetido2==1) ||     //se puede dar el caso en el que minimo1 = minimo2
                        (*minimo1==v[i] && repetido1==1)){      //y haya algún numero repetido mas                           
                    sum = sum + v[i];
                }
            }
            return sum;
        }
    }
}

int main(int argc, char**argv) {
    ivector v = icreavector(TAM);
    int minimo1, minimo2;
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }
    minimo1=v[0], minimo2=v[1];
    int sumaTotal=suma(v, 0, TAM-1, &minimo1, &minimo2, TAM);
    printf("La suma total de todos los elementos del vector excepto los dos menores es: %d\n", sumaTotal);
    printf("Vector: ");
    mostrar(v, TAM);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}