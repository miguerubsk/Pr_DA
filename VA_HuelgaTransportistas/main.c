/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguerubsk
 *
 * Created on 12 de abril de 2022, 13:06
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
#define TAM 7

/**
 * 
 * @param m
 * @param v
 * @param paso
 * @param max
 * @return 
 */
int Coste(imatriz2d m, ivector v, int paso, int max) {
    int aux = 0;
    int rep[max];
    for (int i = 0; i < max; ++i)
        rep[i] = 0;

    for (int i = 0; i <= paso; ++i) {
        aux += m[i][v[i]];
        rep[v[i]]++;
    }

    for (int i = 0; i < max; ++i)
        if (rep[i] > 1)
            aux = RAND_MAX;

    return aux;
}

/**
 * 
 * @param m
 * @param v
 * @param mejor
 * @param n
 * @param paso
 * @param mejorCoste
 */
void Min_Combustible(imatriz2d m, ivector v, ivector mejor, int n, int paso, int *mejorCoste) {
    int costeActual;
    if (paso == n) {
        costeActual = Coste(m, v, paso-1, n);
        if (costeActual < *mejorCoste) {
            *mejorCoste = costeActual;
            for (int i = 0; i < n; ++i) {
                mejor[i] = v[i];
            }
        }
        return;
    }

    for (int i = paso; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i] = j;
            costeActual = Coste(m, v, i, n);
            if (costeActual < RAND_MAX && costeActual < *mejorCoste) {
                Min_Combustible(m, v, mejor, n, i+1, mejorCoste);
            }
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    imatriz2d tabla = icreamatriz2d(TAM, TAM);

    if (1) {
        tabla[0][0] = 17;
        tabla[0][1] = 45;
        tabla[0][2] = 90;
        tabla[0][3] = 51;
        tabla[0][4] = 55;
        tabla[0][5] = 58;
        tabla[0][6] = 83;

        tabla[1][0] = 40;
        tabla[1][1] = 38;
        tabla[1][2] = 73;
        tabla[1][3] = 77;
        tabla[1][4] = 83;
        tabla[1][5] = 29;
        tabla[1][6] = 11;

        tabla[2][0] = 51;
        tabla[2][1] = 56;
        tabla[2][2] = 14;
        tabla[2][3] = 86;
        tabla[2][4] = 22;
        tabla[2][5] = 75;
        tabla[2][6] = 37;

        tabla[3][0] = 41;
        tabla[3][1] = 24;
        tabla[3][2] = 67;
        tabla[3][3] = 49;
        tabla[3][4] = 19;
        tabla[3][5] = 91;
        tabla[3][6] = 12;

        tabla[4][0] = 28;
        tabla[4][1] = 26;
        tabla[4][2] = 56;
        tabla[4][3] = 33;
        tabla[4][4] = 67;
        tabla[4][5] = 32;
        tabla[4][6] = 62;

        tabla[5][0] = 38;
        tabla[5][1] = 68;
        tabla[5][2] = 53;
        tabla[5][3] = 73;
        tabla[5][4] = 83;
        tabla[5][5] = 21;
        tabla[5][6] = 43;

        tabla[6][0] = 52;
        tabla[6][1] = 76;
        tabla[6][2] = 44;
        tabla[6][3] = 10;
        tabla[6][4] = 42;
        tabla[6][5] = 31;
        tabla[6][6] = 12;
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%*d", 5, tabla[i][j]);
        }
        printf("\n");
    }

    int coste = RAND_MAX;
    ivector v = icreavector(TAM);
    ivector mejor = icreavector(TAM);
    Min_Combustible(tabla, v, mejor, TAM, 0, &coste);

    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%*d", 5, mejor[i]);
    }
    printf(" -> %d litros gastados", coste);

    ifreematriz2d(&tabla);
    ifreevector(&v);
    ifreevector(&mejor);

    return (EXIT_SUCCESS);
}

