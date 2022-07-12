/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 21 de marzo de 2021, 11:42
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define TAM 10
#define umbral 0

void mostrar (ivector v, int tam){
    for (int i=0;i<tam;i++)
        printf("%d  ", v[i]);
    printf("\n");
}

int busquedaSec (ivector v, int posIni, int posFin, int n){
    for (int i=posIni; i<=posFin; i++){
        if (v[i]==n){
            return i;
        }
    }
    return -1;
}

int busquedaTer (ivector v, int posIni, int posFin, int n){
    int posTer=(posFin-posIni+1)/3;
    if (posFin<posIni){
        return -1; //los indices se han cruzado por lo tanto no existe el numero
    }else{
        if (posIni==posFin && n!=v[posIni]){
            return -1; //el numero no existe 
        }else if (posIni==posFin && n==v[posIni]){
            return posIni;
        }else if (posFin-posIni+1 <= umbral){
            return busquedaSec(v, posIni, posFin, n);
        }else{
            if (v[posIni+posTer]==n){
                return posIni+posTer;
            }else if(n<v[posIni+posTer]){
                return busquedaTer(v, posIni, posIni+posTer-1, n);
            }else if(v[posFin-posTer]==n){
                return posFin-posTer;
            }else if(n<v[posFin-posTer]){
                return busquedaTer(v, posIni+posTer+1, posFin-posTer-1, n);
            }else{
                return busquedaTer(v, posFin-posTer+1, posFin, n);
            }
        }
    }
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    int n, pos;
    ivector v=icreavector(TAM);
    printf ("Inserte de uno en uno los elementos del vector: ");
    for (int i=0; i<TAM; i++){
        scanf("%d", &n);
        v[i]=n;
    }
    mostrar(v, TAM);
    printf ("Inserte el numero entero que se desea buscar: ");
    scanf("%d", &n);

    pos=busquedaTer(v, 0, TAM-1, n);
    
    if (pos!=-1){
        printf("El elemento ha sido encontrado en la posicion %d\n", pos);
    }else{
        printf("El elemento no existe dentro del vector");
    }
    
    ifreevector(&v);
    
    return (EXIT_SUCCESS);
}

