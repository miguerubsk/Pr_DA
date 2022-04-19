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

int factible(int n_cifras, ivector digito) {
    int sumapar = 0;
    int sumaimpar = 0;
    for (int i = 0; i < n_cifras; i++) {
        if (i % 2 == 0) {
            sumapar = sumapar + digito[i];
        } else {
            sumaimpar = sumaimpar + digito[i];
        }
    }
    return (sumaimpar == sumapar);
/*
    if (sumapar == sumaimpar)
        return 1;
    return 0;
*/

}

void sumadedigitos(int cifras, int paso, ivector solActual) {
    /*
        if((*num_)==4){
            int k=0;
        }
     */
    if (paso == cifras) {
        if (factible(cifras, solActual)) {
            int num = 0;
            for (int i = 0; i < cifras; i++) {
                num += (int) solActual[i] * powf(10, i);

            }
            /*
                        salida[(*num_)] = aux;
             */

            printf("%d  ", num);
        }

    } else {
        for (int i = 1; i <= 5; i++) {
            //for (int j = 1; j <= 5; j++) {
            solActual[paso] = i;
            sumadedigitos(cifras, paso + 1, solActual);
            //}
        }
    }


}

int main() {
    ivector vector_salida;
    ivector aux;
    int TAM = 99;
    vector_salida = icreavector(TAM);
    int valor = 2;
        printf("Introduce el valor n cifras: ");
        fflush(stdin);
        scanf("%d", &valor);
    aux = icreavector(valor);
    int n_sol = 0;
    for (int i = 0; i < TAM; ++i) {
        vector_salida[i] = 0;
    }

    printf("Los numeros cuyas cifras pares suman lo mismo que las impares son:\n");
    sumadedigitos(valor, 0, aux);

    ifreevector(&vector_salida);
    return EXIT_SUCCESS;
}


