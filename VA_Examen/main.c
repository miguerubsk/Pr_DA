/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguerubsk
 *
 * Created on 24 de mayo de 2022, 20:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imatriz2d.h"
#include "ivector.h"

#define TAM 5

void MostrarMatriz(imatriz2d m, int fil, int col) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; ++j) {
            if (i != j){
                printf("%*d", 2, m[i][j]);
            }else{
                printf(" - ");
            }
        }
        printf("\n");
    }
}

int Factible(imatriz2d F, ivector amigos, int k){
    for(int i =0; i < k; ++i){
        if(F[i][k]==1 && amigos[i] == amigos[k]){
            return 0;
        }
    }
    return 1;
}

void AsignarMesas(imatriz2d F, ivector amigos, ivector mejor, int tam, int k, int *minMesas, int mesas){
    if(k == tam){
        if(mesas < *minMesas){
            *minMesas = mesas;
            memcpy(mejor, amigos, sizeof(int)*tam);
/*
            for(int i = 0; i < tam; i++){
                mejor[i] = amigos[i];
            }
*/
        }
    }else{
        for(int i = 1; i <= mesas; ++i){
            amigos[k] = i;
            if(Factible(F, amigos, k) == 1){
                AsignarMesas(F, amigos, mejor, tam, k+1, minMesas, mesas);
            }
        }
        amigos[k] = mesas+1;
        AsignarMesas(F, amigos, mejor, tam, k+1, minMesas, mesas+1);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    imatriz2d F = icreamatriz2d(TAM, TAM);
    ivector amigos = icreavector(TAM);
    ivector mejor = icreavector(TAM);
    F[0][1] = 0;
    F[0][2] = 1;
    F[0][3] = 0;
    F[0][4] = 0;

    F[1][0] = 0;
    F[1][2] = 0;
    F[1][3] = 1;
    F[1][4] = 1;

    F[2][0] = 1;
    F[2][1] = 0;
    F[2][3] = 1;
    F[2][4] = 1;

    F[3][0] = 0;
    F[3][1] = 1;
    F[3][2] = 1;
    F[3][4] = 0;

    F[4][0] = 0;
    F[4][1] = 1;
    F[4][2] = 1;
    F[4][3] = 0;
    
    MostrarMatriz(F, TAM, TAM);

    int *minMesas = malloc(sizeof(int));
    *minMesas = RAND_MAX;
    AsignarMesas(F, amigos, mejor, TAM, 0, minMesas, 1);
    
    printf("\nMínimo de mesas requeridas: %d\n", (*minMesas));
    for(int i = 0; i < TAM; ++i){
        printf("Amigo %d mesa %d\n", i+1, mejor[i]);
    }
    
    ifreematriz2d(&F);
    ifreevector(&amigos);
    ifreevector(&mejor);
    return (EXIT_SUCCESS);
}

