/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 12 de mayo de 2022, 2:32
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define numElems 5

void mostrarV(ivector v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%i ", v[i]);
    }
    printf("\n");
}

int factible(ivector v, int n, int paso, int num, ivector nums) {
    int suma = 0;
    for (int i = 0; i < numElems; i++) {
        suma += v[i] * nums[i];
    }
    //if(suma>num){
    //return 0;
    //}else{
    //return 1;
    //}
    return 1;
}

void funcion(ivector v, int paso, int n, ivector nums, int num, int sum) {
    if (sum == num) {
        mostrarV(v, n);
    } else {
        for (int i = paso; i < numElems; i++) {
            v[i]++;
            funcion(v, paso + 1, n, nums, num, sum + nums[i]);
            v[i]--;

        }
    }

}

int factible2(ivector v, int paso, int n) {
    for (int i = 0; i < paso; i++) {
        //printf("%i ",v[i]);
        if (v[i] == v[paso]) {
            return 0;
        }
    }
    int suma = 0;
    for (int i = 0; i <= paso; i++) {
        suma += v[i];
    }
    if (suma > 6) {
        return 0;
    }
    return 1;

}

int calcularSuma(ivector v, int paso) {
    int suma = 0;
    for (int i = 0; i < paso; i++) {
        suma += v[i];
    }
    //mostrarV(v, paso);
    //printf("suma%i \n\n",suma);
    return suma;
}


void funcion2(ivector v, int n, int paso, ivector nums, int sumaBuscada) {
    
    if (calcularSuma(v,paso) == sumaBuscada) {
        mostrarV(v, paso);
    } else {
        for (int i = 0; i < 5; i++) {
            v[paso] = nums[i];
            if (factible2(v, paso, n) == 1) {
                funcion2(v, n, paso + 1, nums,sumaBuscada);
            }
        }
    }
}

int main(int argc, char** argv) {
    ivector nums = icreavector(numElems);
    ivector v = icreavector(numElems);
    for (int i = 0; i < numElems; i++) {
        nums[i] = i + 1;
        v[i] = 0;
    }
    int sumaBuscada = 6;
    funcion2(v, numElems, 0, nums, sumaBuscada);
    ifreevector(&nums);
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

