/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguerubsk
 *
 * Created on 24 de mayo de 2022, 20:14
 */

#include <stdio.h>
#include <stdlib.h>

#include "imatriz2d.h"
#include "ivector.h"

#define TAM 7

int microfonos(imatriz2d m, int tam, ivector v) {
    ivector marcado = icreavector(tam); //vector para marcar los días en los que un espía ya ha salido a comprar
    for (int i = 0; i < tam; ++i) {
        marcado[i] = 0; //Se inicializa el vector de marcaje para no repetir días
    }
    int microfonos = 0; //Total de micrófonos que se podrán contruir
    for (int i = 0; i < tam; ++i) { //Para cada espía
        int max = 0;
        int dia = 0;
        for (int j = 0; j < tam; ++j) { //Se recorren los días
            if (m[i][j] >= max && !marcado[j]) { //si ese día puede comprar más y ningún espía ha salido a comprar ese día
                max = m[i][j]; //Se actualiza el número máximo de micrófonos que podría construir
                dia = j; //Se guarda el día nuevo
            }
        }
        if (max == 0) { //Si ha recorrido toda la fila y no ha podido ir ningún día
            v[i] = -1;
        } else {
            v[i] = dia; //se guarda el día que va a comprar el espía
            microfonos += max; //se actualizan los micrófonos totales que se pueden construir
            marcado[dia] = 1; // se marca el día para que no salga otro espía el mismo día
        }
    }

    ifreevector(&marcado);
    return microfonos;
}

/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(NULL));
    imatriz2d datos = icreamatriz2d(TAM, TAM);
    ivector resultado = icreavector(TAM);
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            datos[i][j] = rand() % 10;
            printf("%d ", datos[i][j]);
        }
        printf("\n");
    }

    
    int total = microfonos(datos, TAM, resultado);

    printf("=========================================================================\n");
    for (int i = 0; i < TAM; ++i) {
        if(resultado[i] != -1){
            printf("El espía %d va a comprar el día %d\n", i, resultado[i]);
        }else{
            printf("El espía %d no ha podido ir a comprar\n", i);
        }
    }

    printf("En total se han podido comprar %d micrófonos", total);
    return (EXIT_SUCCESS);
}

