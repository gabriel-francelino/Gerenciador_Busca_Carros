/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcoes.h
 * Author: anaca
 *
 * Created on 25 de Março de 2022, 15:13
 */

#ifndef FUNCOES_H
#define FUNCOES_H

using namespace std;

typedef struct no_ {
    int modelo;
    int marca;
    int tipo;
    int ano;
    int km;
    float potencia;
    int combustivel;
    int cambio;
    int direcao;
    int cor;
    int nPortas;
    int placa;
    struct no_* prox;
} no;

// Lista
typedef struct {
	int tam;            
	struct no_ *lista;
} tLista;



tLista* inicia_lista();
tLista* encerra_lista(tLista * ptlista);
bool busca_enc(tLista *ptlista, int placa,  no** ant);
bool insere_enc(tLista *ptlista, int placa, no *veiculo);
bool remove_enc(tLista * ptlista, int placa);
void imprime(tLista * ptlista);

//PILHA
void insere_inicio(tLista* topo, no* dados);
//FILA
void insere_fim(tLista* ptlista, no* dados);

#endif /* FUNCOES_H */
