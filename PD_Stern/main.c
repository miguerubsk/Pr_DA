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
 * Created on 28 de marzo de 2022, 16:31
 */

#include <stdio.h>
#include <stdlib.h>

#include "ivector.h"

#define ELEMENTO 500
/**
 *  
 */

int Stern(int pos){
    ivector v = icreavector(pos +1);
    
    v[0] = 0;
    v[1] = 1;
    
    for (int i = 0; i <= pos; i++) {
        if(i%2 == 0){
            v[i] = v[i/2];
        }else{
            v[i] = v[(i-1)/2] + v[((i-1)/2)+1];
        }
    }
    int aux = v[pos];
    ifreevector(&v);
    
    return aux;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("El elemento %d de la serie de Stern es %d", ELEMENTO, Stern(ELEMENTO-1));

    return (EXIT_SUCCESS);
}

