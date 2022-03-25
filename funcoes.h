/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcoes.h
 * Author: anaca
 *
 * Created on 19 de Março de 2022, 12:42
 */

#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct no_{
    char modelo[20];
    char marca[20];
    char tipo[20];
    char ano[4];
    char km[20];
    char potencia[5];
    char combustivel[20];
    char cambio[20];
    char direcao[20];
    char cor[20];
    char nPortas[2];
    char placa[7];
    
    struct no_* prox;
}no;

typedef struct {
    int tam;
    struct no_ * proxList;
} tLista;

//funções
tLista* inicia_lista();
void insere_ord(tLista* ptlista, no* dados);
void busca_ord(tLista* ptlista,const char* chave, no** ant, no** pont);
 

#endif /* FUNCOES_H */

