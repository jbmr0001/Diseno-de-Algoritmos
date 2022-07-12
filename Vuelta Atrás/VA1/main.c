/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 11 de mayo de 2022, 18:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include "imatriz2d.h"

#define ne 5
#define caras 6
#define num 6

void mostrar(ivector v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf(" %i", v[i]);
    }
    printf("\n");
}

int factible(ivector v, int n, int paso) {
    int suma = 0;
    for (int i = 0; i <= paso; i++) {
        suma += v[i];
    }
    
    
    //printf("\nsuma %i",suma);
    if (paso == n-1) {
        
        if (suma == num) {
            return 1;
        } else {
            return 0;
        }

    } else {
        if (suma < num) {
            return 1;
        } else {
            return 0;
        }
    }
}

void funcion(ivector v, int n, int paso) {
    if (paso == n) {
            mostrar(v, paso);
    } else {
        for (int i = 1; i <= caras; i++) {
            v[paso] = i;
            if (factible(v, n, paso) == 1) {
                funcion(v, n, paso + 1);
            }
        }
    }
}


int main(int argc, char** argv) {
    ivector v = icreavector(ne);
    funcion(v, ne, 0);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

