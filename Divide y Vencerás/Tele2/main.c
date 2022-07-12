/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Juan Bautista Muñoz Ruiz
 *
 * Created on 23 de febrero de 2022, 15:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#define umbral 4

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
 * @Brief Función para calcular el subvector con nota máxima en un rango usando fuerza bruta
 * @param v ivector con el vector
 * @param inf Entero con la posición inicial
 * @param sup Entero con la posición final
 * @return Entero con el valor de la subvector
 */
int clasico(ivector v,int inf,int sup){
    int suma=0;//Entero para guardar la suma de cada subcadena
    int max=0;//Entero para guardar la suma máxima
    for(int i=inf;i<=sup;i++){//Iteracion por cada punto inicial
        for(int j=i;j<=sup;j++){//Iteración por cada punto final
            suma=0;
            for(int k=i;k<=j;k++){//Recorremos entre ese punto inicial y final
                suma=suma+v[k];
            }
            //printf("%i \n",suma);
            if(suma>max){//Almacenamos si supera a la máxima suma
                max=suma;
            }
        }
    }
    return max;
}

/**
 * @brief Función para calcular el subvector con máxima nota partiendo del punto medio 
 * @param v ivector con el vector
 * @param inf Entero con la posición inicial del vector
 * @param sup Entero con la posición final del vector
 * @return Entero con el valor de la subcadena máxima
 */
int Medio(ivector v,int inf,int sup){
    int medio=(sup+inf)/2;//Calculamos el punto medio del vector
    int sum=0;
    int sumaIz=0;
    int sumaDer=0;
    //Desde el punto medio vamos actualizamos la sumaIz si encontramos una suma mayor
    for(int i=medio;i>=inf;i--){
        sum=sum+v[i];
        if(sum>sumaIz){
            sumaIz=sum;
        }
    }

    sum=0;//Reseteamos la suma
    //Desde el punto medio+1 vamos actualizamos la sumaDer si encontramos una suma mayor
    for(int i=medio+1;i<=sup;i++){
        sum=sum+v[i];
        if(sum>sumaDer){
            sumaDer=sum;
        }
    } 
    return sumaIz+sumaDer;//De esta manera sumando las dos el valor de nota máxima obtenemos el subvector central con mayor nota
}
/**
 * @Brief Función Divide y vencerás para nuestro problema
 * @param v ivector con los elementos 
 * @param inf Entero con la posición inicial del vector
 * @param sup Entero con la posición final del vector
 * @return int con el valor de la máxima subcadena
 */
int DYV(ivector v,int inf,int sup){
    int tam=sup-inf+1;
    if(tam<=umbral){//Llamamos al clásico
        //mostrarVectorR(v,inf,sup);
        //printf("%i \t", tam);
        return clasico(v,inf,sup);
    }else{
        //printf("%i \t", tam);
        int medio=(sup+inf)/2;
        //mostrarVectorR(v,n+1,sup);
        int a=DYV(v,inf,medio);//Realizamos 2 llamadas recursivas, una por cada lado desde el punto medio
        int b=DYV(v,medio+1,sup);
        int c=Medio(v,inf,sup);//Final mente llamamos a la función de sub vector de nota máximo que parte desde el punto medio
      
        //Ifs anidados para comprobar qué valor es el mayor
        if(a>b){
            if(a>c){
                return a;
            }else{
                return c;
            }
        }else if(b>c){
            return b;
        }else{
            return c;
        } 
    }
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    int tam = 28;
    ivector v1;
    v1 = icreavector(tam);
    v1[0]=29;
    v1[1]=-7;
    v1[2]=14;
    v1[3]=21;
    v1[4]=30;
    v1[5]=-47;
    v1[6]=10;
    v1[7]=7;
    v1[8]=-39;
    v1[9]=23;
    v1[10]=-20;
    v1[11]=-36;
    v1[12]=-41;
    v1[13]=27;
    v1[14]=-34;
    v1[15]=7;
    v1[16]=48;
    v1[17]=35;
    v1[18]=-46;
    v1[19]=-16;
    v1[20]=32;
    v1[21]=18;
    v1[22]=5;
    v1[23]=-33;
    v1[24]=27;
    v1[25]=28;
    v1[26]=-22;
    v1[27]=1;
    //mostrarVector(v1,tam);
    //int a=clasico(v1,0,tam-1); 
    int a=DYV(v1,0,tam-1); 
    printf("%i",a);
    
    
    return (EXIT_SUCCESS);
}

