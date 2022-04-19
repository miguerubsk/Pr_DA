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
 * Created on 28 de marzo de 2022, 16:42
 */

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"
#include "ivector.h"
/*
 * 
 */
int Formas(ivector sellos, int n_Sellos, int tarifa){
    imatriz2d m = icreamatriz2d(n_Sellos+1, tarifa+1);
    
    for(int i = 0; i <= n_Sellos; ++i){
        m[i][0] = 1;
    }
    for(int i = 0; i <= tarifa; ++i){
        m[0][i] = 0;
    }
    
    for(int i=1; i <= n_Sellos; i++){
        for(int j=1; j <= tarifa; j++){
            if(sellos[i-1] > j){
                m[i][j] = m[i - 1][j];
            }else{
                m[i][j] = m[i - 1][j] + m[i][j - sellos[i-1]];
            }
        }
    }
    
    for (int i = 0; i <= n_Sellos; i++) {
           for (int j = 0; j <= tarifa; j++)
            printf("%*d", 5, m[i][j]);
       printf("\n");
    }
    int aux = m[n_Sellos][tarifa];
    ifreematriz2d(&m);
    return aux;
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    ivector sellos = icreavector(4);
    sellos[0] = 1;
    sellos[1] = 5;
    sellos[2] = 10;
    sellos[3] = 20;
    
    printf("Formas de poner sellos: %d", Formas(sellos, 4, 12));

    return (EXIT_SUCCESS);
}

