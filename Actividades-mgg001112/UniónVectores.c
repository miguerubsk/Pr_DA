/*
 * Copyright (C) 2021 Miguel González García
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
 * @param finY
 * @return 
 */
int base(ivector X, int iniX, int finX, ivector Y, int iniY, int finY) {
    if (X[finX] < Y[iniY])
        return X[finX];
    if (Y[finY] < X[iniX])
        return Y[finY];

    int x;
    if (X[iniX] < Y[iniY]) {
        x = Y[iniY];
    } else {
        x = X[iniX];
    }
    return x;
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

