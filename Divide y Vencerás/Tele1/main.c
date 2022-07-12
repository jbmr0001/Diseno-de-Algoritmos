/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Juan Bautista Muñoz Ruiz
 *
 * Created on 23 de febrero de 2022, 10:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include <stdbool.h>
#define ene 2

/**
 * @brief Función para mostrar un vector dado un rango
 * @param v ivector con el vector
 * @param inf Entero con el punto inicial del vector
 * @param sup Entero con el punto final del vector
 */
void mostrarVectorR(ivector v, int inf, int sup) {
    printf("Vector de tamaño %i:", sup-inf+1);
    printf("\n");
    for (int i = inf; i < sup+1; i++) {

        printf("%i \t", v[i]);
    }
    printf("\n");
};

/**
 * @Brief Función con el caso base
 * @param x ivector con el vector 1
 * @param infX Entero con la posición incial de x
 * @param supX Entero con la posición superior de x
 * @param y ivector con el vector 2
 * @param infY Entero con la posición inicial de y
 * @param supY Entero con la posición final de y
 * @return Entero con el valor que ocupa la posición central si se unieran esos dos vectores para los casos base
 */
int casoBase(ivector x,int infX,int supX,ivector y,int infY, int supY){
    int n=infX+supX/2;//Punto medio del vector
    //mostrarVectorR(x,infX,supX);
    //mostrarVectorR(y,infY,supY);
    //printf("x=%i",x[n+1]);
    //printf("y=%i",y[infY]);
    if(x[n+1]<y[infY]){//Si el segundo elemento de x es menor que el primero de y
        return x[n+1];//Devolvemos el primer elemento de x
    }else{
        if(y[infY]>x[infX]){//Devolvemos el mayor de los dos primeros
            return y[infY];
        }else{
            return x[infX];
        }
    }
}

/**
 * @Brief Función para calcular el valor intemedio de la unión
 * @param x ivector con el vector 1
 * @param infX Entero con la posición incial de x
 * @param supX Entero con la posición superior de x
 * @param y ivector con el vector 2
 * @param infY Entero con la posición inicial de y
 * @param supY Entero con la posición final de y
 * @return Entero con el valor que ocupa la posición central si se unieran esos dos vectores
 */
int casoGeneral(ivector x,int infX,int supX,ivector y,int infY, int supY){
    int tam=supX-infX+1;
    //mostrarVectorR(x,infX,supX);
    //mostrarVectorR(y,infY,supY);
    if(tam==ene){//En caso de llegar al caso base
        return casoBase(x,infX,supX,y,infY,supY);
    }else{
        int pos= (tam/2)-1;//Calculamos posición central y la comparamos
        if(x[pos]==y[pos]){//Si coindicen las posiciones centrales de los dos vectores devolvemos ese elemento
            return x[pos];
        }else{
            if(x[pos]<y[pos]){//si el del vector x es menor al de y buscamos recursivamente en su segunda parte y en la primera de y
                int a=casoGeneral(x,pos+1,supX,y,infY,pos);
                //printf("   %i  \n",x[pos]);
                return a;
            }else{//si el del vector y es menor al de x buscamos recursivamente en su primera parte y en la segunda de x
                int a=casoGeneral(x,infX,pos,y,pos+1,supY);
                //printf("   %i  \n",x[pos]);
                return a;
                
            }
        }
    }
}

int main(int argc, char** argv) {
    int tam = 4;
    ivector v1,v2;
    v1 = icreavector(tam);
    v1[0] = 3;
    v1[1] = 5;
    v1[2] = 7;
    v1[3] = 8;
    
    v2 = icreavector(tam);
    v2[0] = 1;
    v2[1] = 4;
    v2[2] = 6;
    v2[3] = 7;
    mostrarVectorR(v1,0,tam-1);
    mostrarVectorR(v2,0,tam-1);
    printf("Elemento intermedio union %i",casoGeneral(v1,0,tam-1,v2,0,tam-1));
    return (EXIT_SUCCESS);
}

