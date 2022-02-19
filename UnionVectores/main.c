/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguerubsk
 *
 * Created on 19 de febrero de 2022, 18:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#define TAM 64
/*
 * 
 */

/**
 * 
 * @param X
 * @param iniX
 * @param finX
 * @param Y
 * @param iniY
 * @param iniX
 * @return 
 */
int base(ivector X, int iniX, int finX, ivector Y, int iniY, int finY) {
    if (X[finX] < Y[iniY])
        return X[finX];
    if (Y[finY] < X[iniX])
        return Y[finY];
    if (X[iniX] < Y[iniY])
        return Y[iniY];
    return X[iniX];
}

/**
 * Sean X e Y dos vectores de tamaño n potencia de 2, ordenados de forma creciente. 
 * Implementar un algoritmo DyV para calcular el elemento que ocuparía la posición n que resulta de la unión ordenada de los vectores X e Y
 * @param X
 * @param iniX
 * @param finX
 * @param Y
 * @param iniY
 * @param iniX
 * @return 
 */
int centro(ivector X, int iniX, int finX, ivector Y, int iniY, int finY) {
    int tam = finX - iniX + 1;
    int mid = (tam - 1) / 2;

    if (tam <= 2)
        return base(X, iniX, finX, Y, iniY, finY);

    if (X[mid] == Y[mid])
        return X[mid];

    if (X[mid] < Y[mid])
        return centro(X, mid + 1, finX, Y, iniY, mid);

    if (Y[mid] < X[mid])
        return centro(X, iniX, mid, Y, mid + 1, finY);

}

/*
 * 
 */
int main(int argc, char** argv) {

    ivector X = icreavector(4);
    X[0] = 2;
    X[1] = 3;
    X[2] = 4;
    X[3] = 8;
    ivector Y = icreavector(4);
    Y[0] = 1;
    Y[1] = 2;
    Y[2] = 6;
    Y[3] = 9;

    int ele = centro(X, 0, 3, Y, 0, 3);
    printf("El centro de la unión es: %d", ele);

    return (EXIT_SUCCESS);
}

