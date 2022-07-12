/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 19 de abril de 2022, 0:04
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
#define nf 7
#define nc 7

/**
 * Funcion para mostrar una matriz
 * @param m Imatriz2d con la matriz
 * @param nfil Entero con el numero de filas
 * @param ncol Entero con el numero de columnas
 */
void mostrar(imatriz2d m, int nfil, int ncol){
    for (int f=0;f<nfil;f++){
        for (int c=0; c<ncol; c++){
            printf("%i ", m[f][c]);
        }
        printf("\n");
    }
}

/**
 * Funcion para mostrar un vector
 * @param v Ivector con el vector
 * @param tam Entero con el tamaño del vector
 */
void mostrarV(ivector v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf(" %i", v[i]);
    }
    printf("\n");
}

/**
 * Función de factibilidad
 * @param m Matriz con los datos de litros
 * @param v Vector solución a comprobar
 * @param paso Ultima posicion rellenada del vector solucion actual
 * @param valorMejorSolucion Puntero a la mejor solucion en litros actual
 * @return Entero que indica la factibilidad de la solucion
 */
int factible(imatriz2d m,ivector v,int paso,int *valorMejorSolucion){
    //Si el destino ya se encontraba en el vector solucion, establecemos esta solucion como no factible
    for(int i=0;i<paso;i++){
        if(v[i]==v[paso]){
            return 0;
        }
    }
    int litros=0;
    //Si la suma de litros ya es peor que la mejor solucion la decretamos no factible
    for(int i=0;i<paso;i++){

        litros+=m[i][v[i]];
        if(litros>*valorMejorSolucion){
            return 0;
        }
    }
    return 1;
}
/**
 * Función para calcular los litros de una solución
 * @param m Matriz de litros 
 * @param v Vector con la solucion
 * @param paso Entero con la última posicion rellenada del vector
 * @return 
 */
int calculaLitros(imatriz2d m,ivector v,int paso){
    int litros=0;
    //Realizamos la suma
    for(int i=0;i<paso;i++){
        litros+=m[i][v[i]];
    }
    return litros;
}

/**
 * Funcion VA
 * @param m Imatriz2d con los datos
 * @param v Vector solucion a rellenar
 * @param paso Entero que indica la posicion a rellenar
 * @param valorMejorSolucion Puntero al valor de los litros de la mejor solucion
 */
void funcion(imatriz2d m,ivector v,int paso,int *valorMejorSolucion){
    if (paso == nf) {
        
        int litros=calculaLitros(m,v,paso);
        //mostrarV(v, nf);
        if(litros<*valorMejorSolucion){//vamos mostrando la mejor solucion
            *valorMejorSolucion=litros;
            printf("\nNUEVA SOLUCION\n");
            mostrarV(v,nf);
            printf("Litros solucion: %i\n",*valorMejorSolucion);
            
        }
        
    } else {
        for (int i = 1; i <= nf; i++) {//por cada viajante rellenamos con un destino
            v[paso] = i;
            if (factible(m,v,paso,valorMejorSolucion) == 1) {//si no es factible podamos
                funcion(m,v,paso + 1,valorMejorSolucion);
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
    imatriz2d m=icreamatriz2d(nf,nc);
    m[0][0]=17;
    m[0][1]=45;
    m[0][2]=90;
    m[0][3]=51;
    m[0][4]=55;
    m[0][5]=58;
    m[0][6]=83;
    
    m[1][0]=40;
    m[1][1]=38;
    m[1][2]=73;
    m[1][3]=77;
    m[1][4]=83;
    m[1][5]=29;
    m[1][6]=11;
    
    m[2][0]=51;
    m[2][1]=56;
    m[2][2]=14;
    m[2][3]=86;
    m[2][4]=22;
    m[2][5]=75;
    m[2][6]=37;
    
    m[3][0]=41;
    m[3][1]=24;
    m[3][2]=67;
    m[3][3]=49;
    m[3][4]=19;
    m[3][5]=91;
    m[3][6]=12;
    
    m[4][0]=28;
    m[4][1]=26;
    m[4][2]=56;
    m[4][3]=33;
    m[4][4]=67;
    m[4][5]=32;
    m[4][6]=62;
    
    m[5][0]=38;
    m[5][1]=68;
    m[5][2]=53;
    m[5][3]=73;
    m[5][4]=83;
    m[5][5]=21;
    m[5][6]=43;
    
    m[6][0]=52;
    m[6][1]=76;
    m[6][2]=44;
    m[6][3]=10;
    m[6][4]=42;
    m[6][5]=31;
    m[6][6]=12;
    int mejorSolucion=300;
    
    mostrar(m,nf,nc);
    ivector v=icreavector(nf);
    funcion(m,v,0,&mejorSolucion);
    ifreevector(&v);
    ifreematriz2d(&m);
    return (EXIT_SUCCESS);
}

