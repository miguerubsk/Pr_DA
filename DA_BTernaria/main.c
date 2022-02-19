/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: admin
 *
 * Created on 18 de febrero de 2022, 13:43
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define UMBRAL 4
#define TAM 100

/**
 * Algoritmo de búsqueda secuencial
 * @param v vector en el que se va a realizar la búsqueda
 * @param ini posición de inicio del vector
 * @param fin posición de fin del vector
 * @param ele elemento a buscar
 * @return posición del elemento buscado o -1 si no se ha encontrado
 */
int BSecuencial(ivector v, int ini, int fin, int ele) {
    int i;
    for (i = ini; i <= fin; ++i) {
        if (v[i] == ele)
            return i;
    }
    return -1;
}

/**
 * Algoritmo de búsqueda divide y vencerás en un vector ordenado
 * @param v vector en el que se va a realizar la búsqueda
 * @param ini posición de inicio del vector
 * @param fin posición de fin del vector
 * @param ele elemento a buscar
 * @return posición del elemento buscado o -1 si no se ha encontrado
 */
int BTernaria(ivector v, int ini, int fin, int ele) {
    if ((fin - ini + 1) <= UMBRAL)
        return BSecuencial(v, ini, fin, ele);

    int tercio1, tercio2, tam;
    tam = fin - ini;
    tercio1 = ini + (tam / 3);
    tercio2 = fin - (tam / 3);

    if (v[tercio1] == ele)
        return tercio1;
    if (v[tercio2] == ele)
        return tercio2;
    if (v[tercio1] > ele)
        return BTernaria(v, ini, tercio1, ele);
    if (v[tercio2] < ele)
        return BTernaria(v, tercio2 + 1, fin, ele);
    return BTernaria(v, tercio1 + 1, tercio2, ele);

}

/*
 * 
 */
int main(int argc, char** argv) {

    ivector v = icreavector(TAM);
    int i, ele = 40;
    for (i = 0; i < TAM; ++i) {
        v[i] = i + 1;
        printf("%*d", 4, v[i]);
    }
    printf("\n");

    i = BTernaria(v, 0, (TAM - 1), ele);

    if (i != -1) {
        printf("Se ha encontrado el elemento %d en la posición %d", ele, i);
    } else {
        printf("No se ha encontrado el elemento %d en el vector", ele);
    }
    ifreevector(&v);
    return (EXIT_SUCCESS);
}

