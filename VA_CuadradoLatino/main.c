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
 * Created on 27 de abril de 2022, 16:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
#define N 3

void MostrarSolución(imatriz2d M, int n) {
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%*d", 5, M[i][j]);
        }
        printf("\n");
    }
}

int Factible(imatriz2d M, int posX, int posY) {
    for(int i = 0; i < posY; ++i)
        if(M[posX][i] == M[posX][posY])
            return 0;
    for(int j = 0; j < posX; ++j)
        if(M[j][posX] == M[posY][posX])
            return 0;
    return 1;
}

void CuadradoLatino(imatriz2d C, int n, int x, int y) {
    printf("X: %d  Y: %d\n", x, y);
    if (y >= n && x >= n) {
        MostrarSolución(C, n);
    } else {
        if (y == n) {
            
            y = 0;
            x+=1;
        }
        for (int i = 1; i <= n; ++i) {
            C[x][y] = i;
            if (Factible(C, x, y)) {
                CuadradoLatino(C, n, x, y + 1);
            }
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    imatriz2d cuadradoL = icreamatriz2d(N, N);
    CuadradoLatino(cuadradoL, N, 0, 0);
    
    return (EXIT_SUCCESS);
}

