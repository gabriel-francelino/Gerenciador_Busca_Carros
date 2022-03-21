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
    char modelo;
    char marca;
    char tipo;
    int ano;
    int km;
    int potencia;
    char combustivel;
    char cambio;
    char direcao;
    char cor;
    int nPortas;
    char placa[7];
    
    struct no_* prox;
}no;

typedef struct {
    int tam;
    struct no_ * proxList;
} tLista;

//funções
tLista* inicia_lista();
 

#endif /* FUNCOES_H */

