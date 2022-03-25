/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>

using namespace std;

//inicia lista
tLista* inicia_lista() {
    tLista* tmp = new(tLista);
    tmp->tam = 0;
    tmp->proxList = NULL;

    cout << "A lista foi iniciada." << endl;

    return tmp;
}

void busca_ord(tLista* ptlista,const char* chave, no** ant, no** pont){
    *ant = ptlista->proxList;
    *pont = NULL;
    
    no* ptr = ptlista->proxList;
    
    while(ptr != NULL){
        if(strcmp(ptr->placa,chave) == -1){
            *ant = ptr;
            ptr = ptr->prox;
        }else{
            if(strcmp(ptr->placa, chave) == 0){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

//insere ordenado na lista principal
void insere_ord(tLista* ptlista, no* dados){
    no* ant;
    no* pont;
    
    busca_ord(ptlista, dados->placa, &ant, &pont);
    
    if(pont == NULL){
        no* ptr = new(no);
        ptr = dados;
        ptr->prox = ant; //declaração do ant pode estar errada
        ant = ptr;       
    }
}

/*
//busca para verificar se a chave já existe 
void busca(){
    
}

//encerra lista
tLista* encerra_lista(){
    
}


//remove da lista principal
no* remove(){
    
}

//ordena a lista principal em pilha
void pilha(){
    
} 

//ordena a lista principal em fila
void fila(){
  
} 
*/
