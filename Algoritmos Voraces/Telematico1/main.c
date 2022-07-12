/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pc
 *
 * Created on 15 de marzo de 2022, 21:37
 */

#include <stdio.h>
#include <stdlib.h>
/**
 * @Brief Función para mostrar un cuadrado
 * @param a Entero con la altura en casillas
 * @param b Entero con la anchura en casillas
 */
void mostrarCuadrado(int a,int b){
    printf("Cuadrado de %i x %i \n",a,b);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("0 ");
        }
        printf("\n");
    }
}
/**
 * @Brief Función base
 * @param a Altura del cuadrado base
 * @param b Anchura del cuadrado base
 * @return Entero con el numero de cuadrados de mayor tamaño en los que se puede descomponer
 */
int funcionSolucion(int a, int b){
    mostrarCuadrado(a,b);
    int tam=0;
    int numDeCuadrados=0;
    while(tam!=-1){//Hasta que no recibamos la señal de salida desde la función de selección
        //printf("a %i b %i",a,b);
        //Seleccionamos uno de los dos valores de la dimensión
        tam=funcionSeleccionFactible(a,b);
        //Restamos a la dimensión contraria el valor seleccionado para actualizar las dimensiones actuales
        //Un cuadrado 7x5 - Un cuadrado 5x5 = Un cuadrado 2x5 //Un cuadrado 2x3 - Un cuadrado 2x2 = Un cuadrado 2x1
        if(tam==a){
           b=b-tam; 
        }else{
            a=a-tam;
        }  
        numDeCuadrados++;
    }
    printf("Número de cuadrados %i",numDeCuadrados);
    return numDeCuadrados;
}
/**
 * @Brief Función de selección, siempre elige el mayor cuadrado factible disponible
 * @param a Entero con la altura
 * @param b Entero con la anchura
 * @return Entero con el valor de dimensión elegido que a su vez será el valor de las dos dimensiones del nuevo cuadrado
 */
int funcionSeleccionFactible(int a, int b){
    //En caso de no quedar mas huecos libres 
    if(a==0 || b==0){
        return -1;
    }
    //Elegimos vorazmente el menor de los dos valores de anchura o altura de esta manera siempre obtendremos el máximo cuadrado factible
    if(a<b){
        printf("Cuadrado de %i \n",a);
        mostrarCuadrado(a,a);
        return a;
    }else if(b<=a){
        printf("Cuadrado de %i \n",b);
        mostrarCuadrado(b,b);
        return b;
    }
}

int main(int argc, char** argv) {
    funcionSolucion(7,8);
    return (EXIT_SUCCESS);
}

