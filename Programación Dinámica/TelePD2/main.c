/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 29 de marzo de 2022, 21:25
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include <time.h>
/**
 * Función para mostrar el vector
 * @param v ivector
 * @param tam Entero con el tamaño
 */
void mostrar(ivector v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%i ", v[i]);
    }
}

/**
 * Función en basada en programación dinámica
 * @param n Elemento n-simo a a buscar
 * @return Entero con el elemento
 */
int sternPD(int n) {
    ivector v = icreavector(n);
    for (int i = 0; i <= n; i++) {//Vamos rellenando cada posición siguiendo las reglas de las serie de stern
        if (i == 0) {
            v[i] = 0;
        }
        if (i == 1) {
            v[i] = 1;
        }
        if (i % 2 == 0) {
            v[i] = v[i / 2];
        } else {
            v[i] = v[(i - 1) / 2] + v[((i - 1) / 2) + 1];
        }
    }
    //mostrar(v, n);
    int re = v[n];
    ifreevector(&v);
    return re;
}

/**
 * Versión recursiva de la función para comparar tiempos
 * @param n Elemento n-simo a buscar
 * @return Entero con el elemento enesimo
 */
int sternRecursivo(int n) {//Seguimos el mismo procedimientoque en la programación dinámica pero con llamadas recursivas
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return sternRecursivo(n / 2);
    } else {

        int s1 = sternRecursivo((n - 1) / 2);
        int s2 = sternRecursivo(((n - 1) / 2) + 1);
        return s1 + s2;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    clock_t comienzo1 = clock();


    printf("Elemento %i-esimo=%i ALG Recursivo", 20, sternPD(200000000));//Podemos ver que este algoritmo tarda mas que el PD
    clock_t fin1 = clock();
    
    clock_t comienzo2 = clock();


    printf("\nElemento %i-esimo=%i ALG PD", 20, sternRecursivo(200000000));
    clock_t fin2 = clock();
    
    double resultado1 = (double)(fin1-comienzo1)/CLOCKS_PER_SEC;
    double resultado2 = (double)(fin2-comienzo2)/CLOCKS_PER_SEC;
    
    printf("\nTiempo 1: %f\n", resultado1);
    printf("Tiempo 2: %f\n", resultado2);
    return (EXIT_SUCCESS);
}

