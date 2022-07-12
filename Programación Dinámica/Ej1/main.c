/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 17 de abril de 2022, 18:04
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#define numero 5
float funcionPD(ivector v, int nmax){
    float resultado=0;
    float sumatoria=0;

    for (int n=1; n<=nmax; n++){
        resultado = n + (((2.0)/n) * sumatoria);
        printf ("i actual %d \n", n );
        
        printf ("Sumatoria %f\n", sumatoria);
        printf ("Result %f\n", resultado);
        sumatoria+=resultado;
        
    }
    
    printf("Resultado: %f",resultado);
    return resultado;
}

int main(int argc, char** argv) {
    printf("Funcion de %i\n ",numero);
    ivector v = icreavector (numero+1);
    
    funcionPD(v, numero);
    
    ifreevector (&v);
    return (EXIT_SUCCESS);
}
