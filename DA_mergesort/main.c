/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: admin
 *
 * Created on 11 de febrero de 2022, 12:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define UMBRAL 2
#define TAM 100


/**
 * 
 * @param T
 * @param ini
 * @param fin
 */
void burbujaMejorado(ivector T, int ini, int fin) {
    int i, j;
    int aux;
    int entra = 1;
    for (i = ini; i < fin && entra; i++) {
        entra = 0;
        for (j = ini; j < fin; j++)
            if (T[j] > T[j + 1]) {
                aux = T[j];
                T[j] = T[j + 1];
                T[j + 1] = aux;
                entra = 1;
            }
    }
}

/**
 * 
 * @param v
 * @param ini
 * @param fin
 */
void insercion2(ivector v, int ini, int fin) {
    int j, aux;
    for (int i = ini + 1; i < fin; i++) {
        j = i;
        while ((v[j] < v[j - 1]) && (j > 0)) {
            aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j--;
        };
    };
}

/**
 * 
 * @param v
 * @param ini
 * @param fin
 */
void insercion(ivector v, int ini, int fin) {
    int j, aux;
    for (int i = ini; i < fin; ++i) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = aux;
    }
}

/**
 * 
 * @param v
 * @param ini
 * @param fin
 */
void burbuja(ivector v, int ini, int fin) {
    int i, j, aux;
    for (i = ini; i < fin; ++i) {
        for (j = ini; j < fin; ++j) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

/**
 * 
 * @param v
 * @param ini
 * @param fin
 * @param centro
 */
void merge(ivector v, int ini, int fin, int centro) {
    int x, y, z;
    ivector aux;
    x = ini;
    y = centro + 1;
    z = 0;
    aux = icreavector(fin - ini + 1);
    
    while ((x <= centro) && (y <= fin)) {

        if (v[x] <= v[y]) {
            aux[z] = v[x];
            x++;
        } else {
            aux[z] = v[y];
            y++;
        }
        z++;
    }
    
    while (x <= centro) {
        aux[z] = v[x];
        x++;
        z++;
    }

    while (y <= fin) {
        aux[z] = v[y];
        y++;
        z++;
    }
    
    z = 0;
    for (x = ini; x <= fin; x++) {
        v[x] = aux[z];
        z++;
    }

    ifreevector(&aux);

}

/**
 * 
 * @param v
 * @param ini
 * @param fin
 */
void mergesort(ivector v, int ini, int fin) {
    int tam = fin - ini;
    if (tam + 1 <= UMBRAL) {
        burbujaMejorado(v, ini, fin);
    } else {
        int centro = ini + ((fin - ini) / 2);
        mergesort(v, ini, centro);
        mergesort(v, centro + 1, fin);

        merge(v, ini, fin, centro);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    ivector v;
    v = icreavector(TAM);
    for (int i = 0; i < TAM; ++i) {
        v[i] = TAM - i;
        printf("%*d - ", 4, v[i]);
    }
    printf("\n");

    mergesort(v, 0, (TAM - 1));

    for (int i = 0; i < TAM; i++) {
        printf("%*d - ", 4, v[i]);
    }

    return (EXIT_SUCCESS);
}