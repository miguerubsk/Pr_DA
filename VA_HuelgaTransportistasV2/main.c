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
 * Author: Miguel González García
 *
 * Created on 12 de abril de 2022, 13:06
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
#define TAM 7

/**
 * Calcula la asignación de destinos a los transportistas gastando el menor combustible posible
 * @param m tabla que contiene para cada transportista y destino el gasto de combustible asociado
 * @param solActual vector donde se almacena la solución que está construyendo el algoritmo
 * @param marcado vector donde se marca un destino ya asignado para no asignarlo a otro transportista, inicializado a 0
 * @param mejorSol mejor asignación de destinos encontrada hasta el momento
 * @param n número de transportistas y destinos
 * @param paso transportista al que se está intentado asignar un destino, inicialmente vale 0
 * @param costeActual combustible gastado de la solución que se está construyendo, inicialmente vale 0
 * @param mejorCoste combustible gastado de la mejor solución encontrada hasta el momento, inicialmente vale infinito
 */
void MinCombustible(imatriz2d m, ivector solActual, ivector marcado, ivector mejorSol, int n, int paso, int costeActual, int *mejorCoste) {
    if (paso == n) {
        if (costeActual < *mejorCoste) {
            *mejorCoste = costeActual;
            for (int i = 0; i < n; ++i) {
                mejorSol[i] = solActual[i];
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (!marcado[i]) {
                solActual[paso] = i;
                marcado[i] = 1;
                costeActual += m[paso][i];
                if (costeActual < *mejorCoste) { //poda
                    MinCombustible(m, solActual, marcado, mejorSol, n, paso + 1, costeActual, mejorCoste);
                }
                marcado[i] = 0;
                costeActual -= m[paso][i];
            }
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    imatriz2d tabla = icreamatriz2d(TAM, TAM);
    ivector marcado = icreavector(TAM);

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
        marcado[i] = 0;
        for (int j = 0; j < TAM; j++) {
            printf("%*d", 5, tabla[i][j]);
        }
        printf("\n");
    }

    int coste = RAND_MAX;
    ivector v = icreavector(TAM);
    ivector mejor = icreavector(TAM);
    MinCombustible(tabla, v, marcado, mejor, TAM, 0, 0, &coste);

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