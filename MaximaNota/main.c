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
 * Created on 19 de febrero de 2022, 19:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define TAM 28

/**
 * 
 * @param v
 * @param ini
 * @param fin
 * @param dini
 * @param dfin
 * @return 
 */
int SumaMax(ivector v, int ini, int fin, int *dini, int *dfin) {
    int mitad, max_izq, max_der, suma, max_aux;

    // casos base
    if (ini == fin) {
        if (v[ini] > 0) {
            *dini = ini;
            *dfin = fin;
            return v[ini];
        } else {
            *dini = ini + 1;
            *dfin = fin;
            return 0;
        }
    } else {
        mitad = (ini + fin) / 2;
        // casos 1 y 2
        int a, b, c, d, e, f, izq, der;
        izq = SumaMax(v, ini, mitad, &a, &b);
        der = SumaMax(v, mitad + 1, fin, &c, &d);
        if (izq > der) {
            max_aux = izq;
            *dini = a;
            *dfin = b;
        } else {
            max_aux = der;
            *dini = c;
            *dfin = d;
        }

        // caso 3: parte izquierda
        max_izq = 0;
        suma = 0;
        e = mitad + 1;

        for (int i = mitad; i >= ini; i--) {
            suma = suma + v[i];
            if (suma > max_izq) {
                max_izq = suma;
                e = i;
            }

        }
        // caso 3: parte derecha
        max_der = 0;
        suma = 0;
        f = mitad;
        for (int i = mitad + 1; i <= fin; i++) {
            suma = suma + v[i];
            if (suma > max_der) {
                max_der = suma;
                f = i;
            }

        }

        //combinacion de resultados
        if (max_der + max_izq > max_aux) {
            *dini = e;
            *dfin = f;
            max_aux = max_der + max_izq;
        }
        return max_aux;
    }
}

int main() {

    int dia_inicio;
    int dia_fin;
    int suma;
    ivector X;
    X = icreavector(TAM);
    X[0] = 29;
    X[1] = -7;
    X[2] = 14;
    X[3] = 21;
    X[4] = 30;
    X[5] = -47;
    X[6] = 10;

    X[7] = 7;
    X[8] = -39;
    X[9] = 23;
    X[10] = -20;
    X[11] = -36;
    X[12] = -41;
    X[13] = 27;

    X[14] = -34;
    X[15] = 7;
    X[16] = 48;
    X[17] = 35;
    X[18] = -46;
    X[19] = -16;
    X[20] = 32;

    X[21] = 18;
    X[22] = 5;
    X[23] = -33;
    X[24] = 27;
    X[25] = 28;
    X[26] = -22;
    X[27] = 1;

    printf("Suma Maxima: %d\n", SumaMax(X, 0, TAM - 1, &dia_inicio, &dia_fin));
    printf("Día de inicio: %d\n", dia_inicio);
    printf("Día de fin: %d\n", dia_fin);

    ifreevector(&X);
    return 0;
}
