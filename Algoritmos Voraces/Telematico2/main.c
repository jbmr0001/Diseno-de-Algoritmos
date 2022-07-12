/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 16 de marzo de 2022, 0:16
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

/**
 * @Brief Función para mostrar un vector
 * @param tam Entero con el tamaño del vector
 * @param v ivector v
 */
void mostrarVector(int tam, ivector v) {
    for (int i = 0; i < tam; i++) {
        printf("%i ", v[i]);
    }
    printf("\n");
}

/**
 * @Brief Función de comparación para el qsort
 * @param a
 * @param b
 * @return 
 */
int cmpfunc(const void * a, const void * b) {
    return ( *(int*) a - *(int*) b);
}

/**
 * @Brief Función en la que ordenamos el vector y elegimos el primero y le asignamos un valor inalcanzable
 * @param tam Entero con el tamaño del vector
 * @param v ivector v
 * @return entero con el valor elegido
 */
int funcionSeleccionMenor(int tam, ivector v) {
    //mostrarVector(tam, v);
    qsort(v, 10, sizeof (int), cmpfunc);
    //mostrarVector(tam, v);
    int aux = v[0]; //Devolvemos la posción del menor
    v[0] = 9999999; //Asignamos valor inalcanzable
    //mostrarVector(tam, v);
    return aux;
}

/**
 * @Brief Función en la que ordenamos el vector y elegimos el último y le asignamos un valor inalcanzable
 * @param tam Entero con el tamaño del vector
 * @param v ivector v
 * @return Entero con el valor elegido
 */
int funcionSeleccionMayor(int tam, ivector v) {
    //mostrarVector(tam, v);
    qsort(v, 10, sizeof (int), cmpfunc);
    //mostrarVector(tam, v);
    int aux = v[tam - 1]; //Devolvemos la posición del mayor
    v[tam - 1] = -9999999; //Asignamos valor inalcanzable
    //mostrarVector(tam, v);
    return aux;
}

/**
 * @Brief Función que prioriza el número de archivos en disco eligiendo siempre los de menor tamaño
 * @param tamMax Entero con el tamaño máximo del disco
 * @param tamVec Entero con el tamaño del vector
 * @param disco ivector con el disco a rellenar
 * @param archivos ivector con el los archivos
 */
void funcionObjetivo1(int tamMax, int tamVec, ivector disco, ivector archivos) {
    int tam = 0;
    int i = 0;
    while (i < tamVec) {//Vamos llenando el vector
        disco[i] = funcionSeleccionMenor(tamVec, archivos);
        tam = tam + disco[i];
        if (tam > tamMax) {//Función factibilidad, paramos cuando superamos el valor máximo
            tam = tam - disco[i]; //Restamos ese valor que infringe el límite
            i = tamVec; //Salimos del bucle
        }
        i++;

    }
    mostrarVector(tamVec, disco);
    printf("Tamaño %i \n", tam);
}

/**
 * @Brief Función que prioriza el tamaño ocupado en disco eligiendo siempre los de mayor tamaño hasta que llega al límite y elige los de menor tamaño
 * @param tamMax Entero con el tamaño máximo del disco
 * @param tamVec Entero con el tamaño del vector
 * @param disco ivector con el disco a rellenar
 * @param archivos ivector con el los archivos
 */
void funcionObjetivo2(int tamMax, int tamVec, ivector disco, ivector archivos) {
    int tam = 0;
    int i = 0;
    int auxI = 0;
    //Elegimos los de mayor tamaño hasta que lleguemos al límite
    while (i < tamVec) {
        disco[i] = funcionSeleccionMayor(tamVec, archivos);
        tam = tam + disco[i];

        if (tam > tamMax) {//Función factibilidad
            tam = tam - disco[i]; //Restamos ese valor que infringe el límite
            disco[i] = 0;
            auxI = i; //Guardamos la posición de i para cuando no quepan mas mayores
            i = tamVec; //Salimos del bucle
        }
        i++;
    }
    //Reseteamos el valor inalcanble para poder usarlo con la otra función de selección
    for (int i = 0; i < tamVec; i++) {
        if (archivos[i] == -9999999) {
            archivos[i] = 9999999;
        }
    }
    i = auxI;//recuperamos la posición en la que salimos de la función de selección de mayores
    while (i < tamVec) {
        disco[i] = funcionSeleccionMenor(tamVec, archivos);
        tam = tam + disco[i];

        if (tam > tamMax) { //Función factibilidad
            tam = tam - disco[i]; //Restamos ese valor que infringe el límite
            disco[i] = 0;
            i = tamVec; //Salimos del bucle
        }
        i++;
    }
    mostrarVector(tamVec, disco);
    printf("Tamaño %i \n", tam);
}

int main(int argc, char** argv) {
    ivector archivos, disco1, disco2;
    int tam = 10;
    int tamDisco = 100; //Tamaño del disco
    archivos = icreavector(tam);
    disco1 = icreavector(tam);
    disco2 = icreavector(tam);

    for (int i = 0; i <= 9; i++) {//Inicializacion
        disco1[i] = 0;
        disco2[i] = 0;
    }
    archivos[0] = 1;
    archivos[1] = 3;
    archivos[2] = 7;
    archivos[3] = 6;
    archivos[4] = 10;
    archivos[5] = 22;
    archivos[6] = 30;
    archivos[7] = 18;
    archivos[8] = 12;
    archivos[9] = 42;

    printf("Maximizando numero de elementos \n");
    funcionObjetivo1(tamDisco, tam, disco1, archivos);
    archivos[0] = 1;
    archivos[1] = 3;
    archivos[2] = 7;
    archivos[3] = 6;
    archivos[4] = 10;
    archivos[5] = 22;
    archivos[6] = 30;
    archivos[7] = 18;
    archivos[8] = 12;
    archivos[9] = 42;
    printf("Maximizando espacio ocupado\n");
    funcionObjetivo2(tamDisco, tam, disco2, archivos);
    ifreevector(&archivos); //Liberamos memoria
    ifreevector(&disco1);
    ifreevector(&disco2);
    return (EXIT_SUCCESS);
}
