/*
 * Copyright (C) 2022 Miguel González García
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
 * Created on 27 de abril de 2022, 16:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

/**
 * 
 * @param v
 * @param n
 */
void ImprimirSolucion(ivector v, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%*d", 2, v[i]);
    }
    printf("\n");
}

/**
 * 
 * @param sol
 * @param nDados
 * @param pObjetivo
 * @param nCaras
 * @param k
 * @return 
 */
int Factible(ivector sol, int nDados, int pObjetivo, int nCaras, int k) {
    int pAux = 0;
    int pRestante = pObjetivo;
    int maxPuntuacion = nCaras * nDados;
    for (int i = 0; i <= k; ++i) {
        pRestante -= (pAux += sol[i]);
        maxPuntuacion -= (nCaras - sol[i]);
        if (pAux > pObjetivo || maxPuntuacion < pRestante)
            return 0;
    }
    return 1;
}

/**
 * 
 * @param sol
 * @param nDados
 * @param pObjetivo
 * @param k
 * @return 
 */
int EsSolucion(ivector sol, int nDados, int pObjetivo, int k) {
    int pAux = 0;
    for (int i = 0; i < k; ++i) {
        pAux += sol[i];
    }
    if (pAux == pObjetivo)
        return 1;
    return 0;
}

/**
 * Calcula todas las formas posibles de obtener un valor con un número dado de dados con una cantidad determinada de caras
 * @param sol vector que almacena la solución parcial
 * @param nDados número de dados de los que se disponen para alcanzar el valor objetivo
 * @param pObjetivo puntuación que se desea alcanzar
 * @param nCaras número de caras que tienen los dados
 * @param k paso por que va el algoritmo, inicialmente 0
 * @param nFormas formas distintas de obtener la puntuación
 */
void Formas(ivector sol, int nDados, int pObjetivo, int nCaras, int k, int *nFormas) {
    if (k == nDados) {
        if (EsSolucion(sol, nDados, pObjetivo, k)) {
            *nFormas = *nFormas + 1;
            ImprimirSolucion(sol, nDados);
        }
    } else {
        for (int i = 1; i <= nCaras; ++i) {
            sol[k] = i;
            if (Factible(sol, nDados, pObjetivo, nCaras, k)) {
                Formas(sol, nDados, pObjetivo, nCaras, k + 1, nFormas);
            }
        }
    }
}

#define n 25
#define numDados 6
#define numCaras 6
#define paso 0

/*
 * 
 */
int main(int argc, char** argv) {

    ivector v = icreavector(numDados);
    int *nFormas = malloc(sizeof (int));

    Formas(v, numDados, n, numCaras, paso, nFormas);

    printf("Formas: %d", *nFormas);

    return (EXIT_SUCCESS);
}

