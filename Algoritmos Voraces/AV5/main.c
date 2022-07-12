/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 19 de abril de 2021, 17:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define TAM 5

/*
 * 
 */

void heuristica (ivector vectorGasolineras, ivector vectorSolucion, int tam, int capacidadMaxima, int *k){
    int depActual=capacidadMaxima;
    int gas=0;
    int ka=0;
    for (int i=0; i<tam; i++){
        if (depActual-vectorGasolineras[i]>=0){
            depActual=depActual-vectorGasolineras[i]; //no hace falta repostar
        }else{
            vectorSolucion[ka]=i-1; 
            printf("%i",i-1);//hay que respostar en la anterior a esta no llegamos
            depActual=capacidadMaxima;//repostamos
            ka++;
        }
    }
}

int main(int argc, char** argv) {
    ivector distanciaGasolineras = icreavector (TAM); //vector de gasolineras
    int deposito; //capacidad del deposito
    int suma=0;
    int k=0;
   
    deposito=70;
    
    distanciaGasolineras[0]=15; //distancia a la primera gasolinera desde el punto de partida
    distanciaGasolineras[1]=50;
    distanciaGasolineras[2]=30;
    distanciaGasolineras[3]=40;
    distanciaGasolineras[4]=45;
    
    for (int i=0; i<TAM; i++){
        suma+=distanciaGasolineras[i];
    }
    
    ivector vectorSolucion = icreavector (TAM); //ese es el tamaño ya que es imposible que se pase de ese tamaño
    
    heuristica (distanciaGasolineras, vectorSolucion, TAM, deposito, &k);
    
    for (int i=0; i<2; i++){
        printf ("Parada %i \n",vectorSolucion[i]);
    }
    
    ifreevector (&distanciaGasolineras);
    ifreevector (&vectorSolucion);
    return (EXIT_SUCCESS);
}

