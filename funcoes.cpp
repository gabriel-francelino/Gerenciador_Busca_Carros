#include <iostream>
#include <string.h>

#include "funcoes.h"

using namespace std;


tLista* inicia_lista() {
	tLista* tmp = new(tLista);
	tmp->tam = 0;
	tmp->lista = NULL;
    cout << "Iniciou a Lista" << endl;
	return tmp;
}

tLista* encerra_lista(tLista * ptlista) {
	no *ant = ptlista->lista;
	no *pont = ptlista->lista;
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
    cout << "A lista foi removida" <<endl;
    return NULL;
}

bool busca_enc(tLista *ptlista, int placa,  no** ant) {
    *ant = ptlista->lista;
	no *ptr = ptlista->lista;
	while (ptr != NULL && ptr->placa < placa) {
            *ant = ptr;
            ptr = ptr->prox;
        }
	return ptr != NULL && ptr->placa == placa;
}

bool insere_enc(tLista *ptlista, int placa, no *veiculo){
	no* ant;

    if (ptlista->tam == 0){
        ptlista->lista = new(no);

        ptlista->lista->modelo = veiculo->modelo;
        ptlista->lista->marca = veiculo->marca;
        ptlista->lista->tipo = veiculo->tipo;
        ptlista->lista->ano = veiculo->ano;
        ptlista->lista->km = veiculo->km;
        ptlista->lista->potencia = veiculo->potencia;
        ptlista->lista->combustivel = veiculo->combustivel;
        ptlista->lista->cambio = veiculo->cambio;
        ptlista->lista->direcao = veiculo->direcao;
        ptlista->lista->cor = veiculo->cor;
        ptlista->lista->nPortas = veiculo->nPortas;
        ptlista->lista->placa = veiculo->placa;

        ptlista->lista->prox = NULL;
        ptlista->tam++;
        return true;
    }
    if(busca_enc(ptlista, placa, &ant))
        return false;
    
        no * ptr = new(no);

        ptr->modelo = veiculo->modelo;
        ptr->marca = veiculo->marca;
        ptr->tipo = veiculo->tipo;
        ptr->ano = veiculo->ano;
        ptr->km = veiculo->km;
        ptr->potencia = veiculo->potencia;
        ptr->combustivel = veiculo->combustivel;
        ptr->cambio = veiculo->cambio;
        ptr->direcao = veiculo->direcao;
        ptr->cor = veiculo->cor;
        ptr->nPortas = veiculo->nPortas;
        ptr->placa = veiculo->placa;

        ptlista->tam++;        
        if (ant->placa < placa){
            ptr->prox = ant->prox;
            ant->prox = ptr;
    } else {
        ptr->prox = ptlista->lista;
        ptlista->lista = ptr;
    }
    return true;
}

bool remove_enc(tLista * ptlista, int placa){
	no* ant, *ptr;
	if(ptlista->tam == 0 || !busca_enc(ptlista, placa, &ant))
            return false;
        if (ant->placa == placa){
            ptlista->lista = ant->prox;
            ptr = ant;
        } else {
            ptr = ant->prox;
            ant->prox = ptr->prox;
        }
        ptr->prox = NULL;
	return true;
}

void imprime(tLista * ptlista){
	no *ptr = ptlista->lista;
    cout << "Impressão da lista" << endl;
	while(ptr != NULL){
        cout << "----------------------------" << endl;
        cout << "Modelo: " << ptr->modelo << endl;
        cout << "Marca: " << ptr->marca << endl;
        cout << "Tipo: " << ptr->tipo << endl;
        cout << "Ano: " << ptr->ano << endl;
        cout << "KM: " << ptr->km << endl;
        cout << "Potencia: " << ptr->potencia << endl;
        cout << "Combustivel: " << ptr->combustivel << endl;
        cout << "Cambio: " << ptr->cambio << endl;
        cout << "Direcao: " << ptr->direcao << endl;
        cout << "Numero de Portas: " << ptr->nPortas << endl;
        cout << "Placa: " << ptr->placa << endl;
        cout << "----------------------------" << endl;
        ptr = ptr->prox;
	}
}

// ------------------------------------------------------------------

// ------------------------------------------------------------------



void insere_pilha(no *end, Pilha *pilha) {
    noBusca *ptr = new(noBusca);
    if(ptr == NULL) {
        cout << "Erro ao inserir na pilha!" << endl;
    } else {
        ptr->end = end;
        ptr->prox = pilha->topo;
        pilha->topo = ptr->prox;
    }
}

void imprime_pilha(Pilha *pilha) {
    noBusca *ptr = pilha->topo;

    if(ptr != NULL) {
        cout << "Impressão da Fila" << endl;
	    while(ptr != NULL){
            cout << "----------------------------" << endl;
            cout << "Modelo: " << ptr->end->modelo << endl;
            cout << "Marca: " << ptr->end->marca << endl;
            cout << "Tipo: " << ptr->end->tipo << endl;
            cout << "Ano: " << ptr->end->ano << endl;
            cout << "KM: " << ptr->end->km << endl;
            cout << "Potencia: " << ptr->end->potencia << endl;
            cout << "Combustivel: " << ptr->end->combustivel << endl;
            cout << "Cambio: " << ptr->end->cambio << endl;
            cout << "Direcao: " << ptr->end->direcao << endl;
            cout << "Numero de Portas: " << ptr->end->nPortas << endl;
            cout << "Placa: " << ptr->end->placa << endl;
            cout << "----------------------------" << endl;
            ptr = ptr->prox;
	    }
    } else {
        cout << "Pilha Vazia! Sem resultados para a busca.";
    }
}

// ------------------------------------------------------------------

void insere_fila(no *end, Fila *fila) {
    noBusca *ptr = new(noBusca);
    if(ptr == NULL) {
        cout << "Erro ao inserir na fila!" << endl;
    } else {
        ptr->end = end;
        ptr->prox = NULL;
        if(fila->ini == NULL){
            fila->ini = ptr;
        } else {
            fila->fim->prox = ptr;
        }
        fila->fim = ptr;
    }
}

void imprime_fila(Fila *fila) {
    noBusca *ptr = fila->ini;

    if(ptr != NULL) {
        cout << "Impressão da Fila" << endl;
	    while(ptr != NULL){
            cout << "----------------------------" << endl;
            cout << "Modelo: " << ptr->end->modelo << endl;
            cout << "Marca: " << ptr->end->marca << endl;
            cout << "Tipo: " << ptr->end->tipo << endl;
            cout << "Ano: " << ptr->end->ano << endl;
            cout << "KM: " << ptr->end->km << endl;
            cout << "Potencia: " << ptr->end->potencia << endl;
            cout << "Combustivel: " << ptr->end->combustivel << endl;
            cout << "Cambio: " << ptr->end->cambio << endl;
            cout << "Direcao: " << ptr->end->direcao << endl;
            cout << "Numero de Portas: " << ptr->end->nPortas << endl;
            cout << "Placa: " << ptr->end->placa << endl;
            cout << "----------------------------" << endl;
            ptr = ptr->prox;
	    }
    } else {
        cout << "Fila Vazia! Sem resultados para a busca.";
    }
}

// ------------------------------------------------------------------
