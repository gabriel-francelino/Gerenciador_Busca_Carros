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

// Estrutura de nós da lista----------------------------------------------------
typedef struct no_ {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int nPortas;
    string placa;
    struct no_* prox;
} no;

// Estrutura do "nó cabeça" da lista--------------------------------------------
typedef struct {
    int tam;
    struct no_ *lista;
} tLista;

// Estrutura de buscas para PILHA e FILA----------------------------------------
typedef struct noBusca {
    no *end;
    struct noBusca *prox;
} noBusca;

typedef struct pilha {
    noBusca *topo;
} tPilha;

typedef struct fila {
    noBusca *inicio;
    noBusca *fim;
} tFila;

// Inicialização da lista--------------------------------------------------------
tLista* inicia_lista();
void encerra_lista(tLista *ptlista);

//funções de gerenciamento
bool busca_enc(tLista *ptlista, string placa, no **ant);
bool insere_enc(tLista *ptlista, string placa, no *veiculo);
bool remove_enc(tLista *ptlista, string placa);
void imprime(tLista *ptlista);

//-----------------------------------PILHA--------------------------------------
tPilha* inicia_pilha();
void insere_pilha(no **end, tPilha *pilha);
void imprime_pilha(tPilha *pilha);
void encerra_pilha(tPilha *ptPilha);

//FILA-------------------------------FILA---------------------------------------
tFila* inicia_fila();
void insere_fila(no **end, tFila *fila);
void imprime_fila(tFila *fila);
void encerra_fila(tFila *ptFila);

#endif /* FUNCOES_H */
