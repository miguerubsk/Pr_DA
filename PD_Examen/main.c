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
 * Author: Miguel González García
 *
 * Created on 22 de abril de 2022, 13:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"

#define M 10
#define N 10

/**
 * 
 */

int Funcion(int m, int n, ivector v) {
    if (n == 0 || m == 0)
        return 1;

    imatriz2d mat = icreamatriz2d(m + 1, n + 1);
    for (int i = 0; i <= m; ++i) {
        mat[i][0] = 1;
    }
    for (int i = 0; i <= n; ++i) {
        mat[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            mat[i][j] = 0;
            if (i < v[i]) {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] + 1;
            } else {
                mat[i][j] += mat[i - 1][j];
            }
        }
    }

    int result = mat[m][n];
    ifreematriz2d(&mat);
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(NULL));
    ivector v = icreavector(N + 1);

    printf("Vector v=");
    for (int i = 0; i <= N; i++) {
        v[i] = rand() % (M + 1);
        printf(" %d", v[i]);
    }

    printf("\nResultado de la función para m=%d y n=%d : %d\n", M, N, Funcion(M, N, v));

    ifreevector(&v);

    return (EXIT_SUCCESS);
}