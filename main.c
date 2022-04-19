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
#include <stdlib.h>
#define TAM 14

struct File {
    int id;
    int size;
};

typedef struct File File;

int compare(const void *_a, const void *_b) {
    File *a, *b;
    a = (File*) _a;
    b = (File*) _b;

    return (a->size - b->size);
}

int maxFiles(File files[], int nFiles, int sDisc, File *saved[]) {
    qsort(files, nFiles, sizeof (File), compare);
    int used = 0;
    int i = 0;
    int nSaved = 0;
    while (used + files[i].size <= sDisc && i < nFiles) {
        used += files[i].size;
        *saved[nSaved] = files[i];
        nSaved++;
        i++;
    }
    return nSaved;
}

int maxSize(File files[], int nFiles, int sDisc, File *saved[]) {
    qsort(files, nFiles, sizeof (File), &compare);
    int used = 0;
    int nSaved = 0;
    for (int i = nFiles; i >= 0; --i) {
        if (used + files[i].size <= sDisc) {
            used += files[i].size;
            *saved[nSaved] = files[i];
            nSaved++;
        }
    }
    return nSaved;
}

/*
 * 
 */
int main(int argc, char** argv) {

    File files[TAM], files2[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; ++i) {
        files[i].id = i + 1;
        files[i].size = (rand() % 100) + 1;
        printf("Archivo: %d - Tamaño: %d\n", files[i].id, files[i].size);
    }

    int selected = maxFiles(files, TAM, 150, &files2);

    printf("ARCHIVOS GUARDADOS:\n");
    for (int i = 0; i < selected; ++i) {
        printf("Archivo: %d - Tamaño: %d\n", files2[i].id, files2[i].size);
    }

    return (EXIT_SUCCESS);
}

