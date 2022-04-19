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
 * Created on 11 de marzo de 2022, 19:06
 */

#include <stdio.h>
#include <stdlib.h>
#define ALTO 9
#define ANCHO 5

int cuadradosPerfectos(int a, int b){
    int numCuadrados = 0;
    while(a > 1 && b > 1){
        if(a<b){
            b-=a;
        }else{
            a-=b;
        }
        numCuadrados++;
    }
    return numCuadrados+a*b;
}

/*
 * 
 */
int main(int argc, char** argv) {

    printf("=========================PROBLEMA 1. CUADRADOS PERFECTOS============================\n");
    printf("Número de cuadros para un rectangulo de %dx%d: %d", ALTO, ANCHO, cuadradosPerfectos(ALTO, ANCHO));
    
    return (EXIT_SUCCESS);
}