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
 * Created on 11 de marzo de 2022, 17:35
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ivector.h"

/**
 * 
 * @param n_cifras
 * @param numero
 * @return 
 */
int factible(int n_cifras, ivector numero) {
    int sumapar = 0;
    int sumaimpar = 0;
    for (int i = 0; i < n_cifras; i++) {
        if (i % 2 == 0) {
            sumapar = sumapar + numero[i];
        } else {
            sumaimpar = sumaimpar + numero[i];
        }
    }
    return (sumaimpar == sumapar);
}

/**
 * 
 * @param nCifras
 * @param paso
 * @param numero
 */
void sumadedigitos(int nCifras, int paso, ivector numero) {
    if (paso == nCifras) {
        if (factible(nCifras, numero)) {
            int num = 0;
            for (int i = 0; i < nCifras; i++) {
                num += (int) numero[i] * powf(10, i);

            }
            printf("%d  ", num);
        }
    } else {
        for (int i = 1; i <= 5; i++) {
            numero[paso] = i;
            sumadedigitos(nCifras, paso + 1, numero);
        }
    }
}

int main() {
    ivector numero;
    int valor = 2;
    
    printf("Introduce el valor n cifras: ");
    fflush(stdin);
    scanf("%d", &valor);
    
    numero = icreavector(valor);

    printf("Los numeros cuyas cifras pares suman lo mismo que las impares son:\n");
    sumadedigitos(valor, 0, numero);

    ifreevector(&numero);
    return EXIT_SUCCESS;
}


