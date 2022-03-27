/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   fila.h
 * Author: anaca
 *
 * Created on 25 de Março de 2022, 22:03
 */

#ifndef FILA_H
#define FILA_H

#include "funcoes.h"

typedef tLista tFila;

inline tFila* inicia_fila(){
    return inicia_lista();
};

inline void insere_fila(tFila* ptlista, no* dados){
    return insere_fim(ptlista, dados);
};

#endif /* FILA_H */

