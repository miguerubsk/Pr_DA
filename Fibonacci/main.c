/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguerubsk
 *
 * Created on 7 de mayo de 2024, 1:10
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if ( n <= 1)
        return n;
    int i;
    long a, b, aux;
    a = 0;
    b = 1;
    for(int i = 2; i <= n; ++i){
        aux = a + b;
        a = b;
        b = aux;
    }
    return b;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("%d", fibonacci(10));

    return (EXIT_SUCCESS);
}

