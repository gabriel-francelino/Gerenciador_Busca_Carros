/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <stdlib.h>
#include "funcoes.h"

using namespace std;

//inicia lista
tLista* inicia_lista() {
    tLista* tmp = new(tLista);
    tmp->tam = 0;
    tmp->proxList = NULL;

    cout << "A lista foi iniciada." << endl;

    return tmp;
}
/*
//encerra lista
tLista* encerra_lista(){
    
}

//insere ordenado na lista principal
void insere_ord(){
    
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