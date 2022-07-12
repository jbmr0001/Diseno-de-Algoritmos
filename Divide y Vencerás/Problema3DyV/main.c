/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 21 de marzo de 2021, 16:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


int busquedaTer(int posIni, int posFin, int n){
    int posTer=(posFin-posIni+1)/3;
    if (posFin<posIni){
        return -1;
    }else{
        if (posIni==posFin && n!=(posIni-1)*posIni*(posIni+1)){
            return -1;
        }else if (posIni==posFin && n!=(posIni-1)*posIni*(posIni+1)){
            return posIni;
        }else{
            if ((posIni+posTer-1)*(posIni+posTer)*(posIni+posTer+1)==n){
                return posIni+posTer;
            }else if (n<(posIni+posTer-1)*(posIni+posTer)*(posIni+posTer+1)){
                return busquedaTer(posIni, posIni+posTer-1, n);
            }else if ((posFin-posTer-1)*(posFin-posTer)*(posFin-posTer+1)==n){
                return posFin-posTer;
            }else if(n<(posFin-posTer-1)*(posFin-posTer)*(posFin-posTer+1)){
                return busquedaTer(posIni+posTer+1, posFin-posTer-1, n);
            }else{
                return busquedaTer(posFin-posTer+1, posFin, n);
            }
        }
    }
}

int main(int argc, char** argv) {
    int n, pos;
    printf("Introduce un numero: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        pos=busquedaTer(1,i/3,i);
        
        if (pos!=-1){
        printf("\nExisten 3 numeros consecutivos cuyo producto sea el numero buscado: %d\n", pos);
        printf("\n%d ", i);
    }else{
        //printf ("\nNo existen 3 numeros consecutivos cuyo producto sea el numero buscado");
    }
    }
    
    

    
    return (EXIT_SUCCESS);
}

