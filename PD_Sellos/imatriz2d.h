//
// Created by Fernando on 25/03/2022.
//

#ifndef PROBLEMA01_PD_IMATRIZ2D_H
#define PROBLEMA01_PD_IMATRIZ2D_H

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   imatriz2d.h
 * Author: Fernando
 *
 * Created on 18 de marzo de 2021, 12:14
 */
/*************************imat2d.h****************************/
/*         MÃ³dulo de cabeceras para uso de objetos           */
/*              ARRAY DINAMICO  2D DE ENTEROS                */
/*************************************************************/

typedef int **imatriz2d;

imatriz2d icreamatriz2d(int nf, int nc);
void ifreematriz2d (imatriz2d *matriz2d);

#endif //PROBLEMA01_PD_IMATRIZ2D_H