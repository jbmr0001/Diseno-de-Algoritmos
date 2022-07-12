#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include "imatriz2d.h"
//Funcion que devuelve un entero que es la cantidad que bebe Listillo usando la programacion dinamica para ello
//Entrada: tam, entero con el tamano del vector de los vasos

int botellonofi(int tam, ivector v) {//vasos: vector con los vasos con la bebida que tomaran, cada vaso tiene un contenido >0
    if (tam > 0) {//Para usar eficazmenta la funcion se necesita que haya vasos
        imatriz2d m; //matriz con la que obtendremos la solucion
        m = icreamatriz2d(tam, tam); //la matriz sera del tamano del vector (tamxtam)
        for (int i = 0; i < tam; i++) { //rellenamos la matriz con -1 para ejemplificar que no se tomaria nada 
            for (int j = 0; j < tam; j++) {//alla donde se deja un -1 pues le tocaria a agonioso coger
                m[i][j] = -1; //O llegariamos a una parte que el vector no contempla
            }
        }
        for (int i = 0; i < tam; i++) { //rellenamos los casos base, en caso de que haya solo dos numeros en los vasos
            m[i][i + 1] = mayor(v[i], v[i + 1]); //a elegir elegiremos el mas mayor
        } //en las posiciones donde hay solo 1 numero de diferencia entre i y j (1,2)...
        //int i = 0; //definimos i y j para los indices del vector, i como el inicio y j como el final


        if (tam > 3) { //Si hay al menos 4 numeros tendremos que hacer uso de otra funcion para calcular la sol
            for (int j = 3; j <= tam - 1; j += 2) { //recorremos la matriz desde la pos 3 hasta el final pasando de 2 en 2 columnas 
                for (int i = 0; i + j <= tam - 1; i++) { //y las filas desde de 1 en 1 pero reduciendo en cada recorrido hasta donde llegan, al final solo llega a 1 (la sol)
                    int mayor1 = -1; //definimo mayor1 y mayor2 para calcular cual de los elementos de los dos lados nos conviene más
                    int mayor2 = -1; //ademas de tener en cuenta el propio elemento debemos tener en cuenta los elementos colindantes a este

                    //Para calcular mayor 1 hacemos las siguientes comprobaciones como si hubieramos seleccionado el primer vaso de el vector (n a n+c)
                    if (v[i + 1] > v[i + j]) { //Si el vaso a la derecha del primer vaso es mayor que el ultimo vaso 
                        mayor1 = v[i] + m[i + 2][i + j]; //guardamos en mayor1 el primer vaso y el vaso de la matriz que esta dos filas abajo y c columnas a la derecha
                    }//En caso de que sea al reves (vaso derecho del primero menor que el ultimo)
                    else {
                        mayor1 = v[i] + m[i + 1][i + j - 1];
                    } //guardamos en mayor 1 el primer vaso y el vaso de la matriz que esta una fila abajo y  c-1 columnas a la derecha

                    //para calcular mayor2 hacemos las siguientes comprobaciones como si hubieramos seleccionado el ultimo vaso de el vector (n a n+c) 
                    if (v[i] > v[i + j - 1]) { //Si el primer vaso es mayor que el vaso a la izquierda del ultimo vaso entonces
                        mayor2 = v[i + j] + m[i + 1][i + j - 1]; //en mayor2 guardamos el primer vaso + el vaso de la matriz que ocupa una fila abajo y c-1 columnas a la derecha
                    }//En caso de que sea al reves( vaso a la izq del ultimo mayor que el primero)
                    else {
                        mayor2 = v[i + j] + m[i][i + j - 2];
                    } //en mayor2 guardamos el primer vaso + el vaso de la matriz que ocupa la misma linea y c-2 columnas a la derecha
                    //finalmente con lo guardado comparamos mayor1 y mayor2
                    if (mayor1 > mayor2) { //si mayor1 > mayor2 
                        m[i][i + j] = mayor1; //guardamos en la misma linea pero c columnas a la derecha el dato de mayor 1 
                    }//en caso contrario 
                    else {
                        m[i][i + j] = mayor2;
                    }//guardamos en la misma linea pero c columnas a la derecha el dato de mayor 2
                }
            }
        }
        printf("\n La matriz es: \n"); //Mostramos la matriz
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                printf("%*d", 4, m[i][j]);
            }
            printf("\n");
        }
        return m[0][tam - 1]; //devolveremos el numero de la primera linea y la ultima columna (la solucion)
        ifreematriz2d(&m); //Liberamos el espacio de la matriz
    } else {
        printf("\n No funciona para tamanos <= 0"); //En caso de que el tamano sea <= 0 lo notificaremos
    }
}

int mayor(int pri, int seg) { //funcion auxiliar para comparar dos enteros entre ellos devolviendo el mayor
    if (pri > seg) {
        return pri;
    } else {
        return seg;
    }
}

int indice(ivector v,int c,int tam){
    for(int i=0;i<tam;i++){
        if(v[i]==c){
            return i;
        }
       
    }
     return -1;
}

void mostrar(imatriz2d m, int nfil, int ncol) {
    for (int f = 0; f < nfil; f++) {
        for (int c = 0; c < ncol; c++) {
            printf("%d   ", m[f][c]);
        }
        printf("\n");
    }
}


void botellonMio(ivector v, int tam) {
    imatriz2d m = icreamatriz2d(tam, tam); 
    imatriz2d sol = icreamatriz2d(tam, tam);//la matriz sera del tamano del vector (tamxtam)
    for (int i = 0; i < tam; i++) { //rellenamos la matriz con -1 para ejemplificar que no se tomaria nada 
        for (int j = 0; j < tam; j++) {//alla donde se deja un -1 pues le tocaria a agonioso coger
            m[i][j] = -1; //O llegariamos a una parte que el vector no contempla
            sol[i][j] = -1;
        }
    }

    int k = 2;
    int i=0;
    int j=1;
    int posSol=0;
    while (i<tam&& k<=6) {
        i=0;
        j=k-1;
        while(j<tam){
            if(j-1==i){
                m[i][j]= mayor(v[i], v[j]);
                sol[i][j]=indice(v,m[i][j],tam)+1;
            }else{
            //printf("%i %i \n",i,j);
                int mayor1=-1;
                int mayor2=-1;
                if(v[i+1]>v[j]){
                    mayor1=v[i]+m[i+2][j];
                }else{
                    mayor1=v[i]+m[i+1][j-1];
                }
                
                if(v[i]>v[j+1]){
                    mayor2=v[j]+m[i+1][j-1];
                }else{
                    mayor2=v[j]+m[i][j-2];
                }
             m[i][j]=mayor(mayor1, mayor2);
             if(m[i][j]==mayor1){
                 sol[i][j]=v[i];
             }else{
                 sol[i][j]=v[j];
             }
            
             posSol++;
            }
            j++;
            i++;
        }
       
        k=k+2;
        
    }
    
    mostrar(m, tam, tam);
    printf("\n");
    mostrar(sol, tam, tam);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int tama = 10; //tamano de el vector de los vasos 
    ivector vas; //vector en el que estan los vasos
    vas = icreavector(tama); //inicializamos el vector
    vas[0] = 5;
    vas[1] = 7;
    vas[2] = 3;
    vas[3] = 2;
    vas[4] = 11;
    vas[5] = 12;
    vas[6] = 6;
    vas[7] = 5;
    vas[8] = 11;
    vas[9] = 3;
    /**
    printf(" El vector de vasos es: "); //mostramos el vector
    for (int i = 0; i < tama; i++) {
        printf("%*d", 4, vas[i]);
    } //llamamos a la funcion y esta nos devuelve la solucion
    int num = botellonofi(tama, vas);
    printf("\n El total que toma listillo es: "); //mostramos el resultado
    printf("%*d", 4, num);
     * **/
    ivector v = icreavector(6);
    v[0] = 5;
    v[1] = 6;
    v[2] = 4;
    v[3] = 1;
    v[4] = 8;
    v[5] = 2;
    botellonMio(v,6);
    ifreevector(&vas); //liberamos el vector de los vasos
    return (EXIT_SUCCESS);
}

