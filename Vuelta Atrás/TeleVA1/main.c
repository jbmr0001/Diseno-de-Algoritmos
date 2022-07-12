/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 18 de abril de 2022, 22:04
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include <math.h>
#define digitomax 5//numero maximo con elque rellenar las posiciones de los vectores
/**
 * Función para mostrar el vector
 * @param v Ivector v a mostrar
 * @param tam Entero con el tamaño de v
 */
void mostrar(ivector v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf(" %i", v[i]);
    }
    printf("\n");
}
/**
 * Función de factibilidad
 * @param v Ivector de digitos a comprobar
 * @param n Entero n con el numero de dígitos a generar
 * @param paso Entero con la ultima posicion rellenada
 * @return Entero que indica 1 si es factible
 */
int factible(ivector v, int n, int paso) {
    if (paso == n - 1) {
        //printf("pas %i",paso);
        int sumaPar = 0;
        int sumaImpar = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                //printf("%i",v[i]);
                sumaPar += v[i];
            } else {
                //printf("%i",v[i]);
                sumaImpar += v[i];
            }

        }
        //printf("\n");
        //Si nos encontramos en la ultima posición comprobamos si la suma es la misma para devolver true
        if (sumaPar == sumaImpar) {
            //printf("%i==%i \n", sumaPar, sumaImpar);
            return 1;
        } else {
            return 0;
        }
    } else {
        //si nos encontramos en mas de la mitad del llenado
        int salir=1;
        if (paso >n/2) {
            int suma = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {//sumamos pares y restamos impares
                    suma += v[i];
                } else {
                    suma -= v[i];
                }

            }
            //podamos en caso de que la suma sea inalcanzable, cuando ni sumando en las n-paso casillas siguientes el máximo digito es alcanzable el 0 (equlibrio en la suma de parese impares) 
            if (suma<=-digitomax*n-paso) {
                return 0;

            } else if (suma >= digitomax*n-paso) {
                return 0;
            }
        }
        return 1;

    }
}
/**
 * Funcón para convertir el vector en un float
 * @param v Ivector con el vector a convertir
 * @param tam Entero con el tamaño del vector
 * @return Float con el número convertido
 */
float convertir(ivector v, int tam) {
    float num = 0;
    int j = 0;
    //Se trata de una conversion decimal 
    for (int i = tam - 1; i >= 0; i--) {//por cada posicion multiplicamos el valor por 10^tam-i-1
        num += v[i] * pow(10, tam - i - 1);
        //printf("%f \n",v[i]*pow(10,tam-i-1));
    }

    return num;
}
/**
 * Función principal de VA
 * @param v Ivector de la solucion actual
 * @param n Entero n con el tamaño de la solucion actual
 * @param paso Entero con la posicion a rellenar
 */
void funcion(ivector v, int n, int paso) {
    if (paso == n) {
        mostrar(v, n);
        printf("%f \n", convertir(v, n));
    } else {
        for (int i = 1; i <= digitomax; i++) {//iremos intentenado con todos los digitos por cada solucion y continuaremos el arbol cuando sea factible
            v[paso] = i;
            if (factible(v, n, paso) == 1) {
                funcion(v, n, paso + 1);
            }
        }
    }
}
/**
 * Funcion main
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    ivector v = icreavector(2);
    funcion(v, 4, 0);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

