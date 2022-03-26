#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

#include "funcoes.h"
#include "pilha.h"
#include "fila.h"

using namespace std;

void interface() {
    cout << "+---------------------------------------+" << endl;
    cout << "|       GERENCIAMENTO DE BUSCA          |" << endl;
    cout << "|   Escolha qual comando deseja fazer:  |" << endl;
    cout << "|     1)Adicinar veículo.               |" << endl;
    cout << "|     2)Remover veículo.                |" << endl;
    cout << "|     3)Busca 1.                        |" << endl;
    cout << "|     4)Busca 2.                        |" << endl;
    cout << "|     5)Relatório.                      |" << endl;
    cout << "|     6)Finalizar.                      |" << endl;
    cout << "+---------------------------------------+" << endl;
}

// Variaveis
//Pilha *pilha;
//Fila *fila;

tLista *lista;

// ------------------------------------------------------------------

int main(int argc, char** argv) {
    int op;
    ifstream cadastro("BD-int.txt");
    if (cadastro.is_open()) {
        lista = inicia_lista();
        while (!cadastro.eof()) {
            no *dados = new(no);
            cadastro >> dados->modelo;
            cadastro >> dados->marca;
            cadastro >> dados->tipo;
            cadastro >> dados->ano;
            cadastro >> dados->km;
            cadastro >> dados->potencia;
            cadastro >> dados->combustivel;
            cadastro >> dados->cambio;
            cadastro >> dados->direcao;
            cadastro >> dados->cor;
            cadastro >> dados->nPortas;
            cadastro >> dados->placa;
            dados->prox = NULL;
            insere_enc(lista, dados->placa, dados);
            delete(dados);
        }
        cadastro.close();
    } else {
        cout << "Arquivo não encontrado!" << endl;
        delete(lista);
        return 0;
    }

    // Daqui pra cima no main ta funcionando
    // ------------------------------------------------
    no* ptr = lista->lista;
    tPilha* pilha = inicia_pilha();
    tFila* fila = inicia_fila();
    do {
        interface();
        cout << "Digite o comando: ";
        cin >> op;
        cout << endl << "+---------------------------------------+" << endl;
        switch (op) {
            case 1:
                cout << "Adicionar Veículo" << endl;
                no veiculo;

                cout << "Digite as informações do veículo:" << endl;

                // Fazer leitura do teclado dos dados e tratamento

                veiculo.modelo = 14;
                veiculo.marca = 4444;
                veiculo.tipo = 11;
                veiculo.tipo = 2015;
                veiculo.km = 23412;
                veiculo.potencia = 1.0;
                veiculo.combustivel = 1;
                veiculo.cambio = 1;
                veiculo.direcao = 2;
                veiculo.cor = 40;
                veiculo.nPortas = 2;
                veiculo.placa = 7865;
                veiculo.prox = NULL;

                if (insere_enc(lista, veiculo.placa, &veiculo)) {
                    cout << "Adicionado com Sucesso!" << endl;
                } else {
                    cout << "Falha ao adicionar." << endl;
                }
                break;
            case 2:
                cout << "Remover Veículo" << endl;
                cout << "Digite a placa do Veículo que será removida: ";
                int placa;
                placa = 4572; // cin >> placa;
                cout << endl;

                if (remove_enc(lista, placa)) {
                    cout << "Removido com sucesso" << endl;
                } else {
                    cout << "Falha ao remover" << endl;
                }
                break;
            case 3:
                cout << "Busca por veiculos ano 2019 ou menos. (Pilha)" << endl;

                if (ptr == NULL) {
                    cout << "A lista está vazia!!" << endl;
                } else {
                    while (ptr != NULL) {
                        if (ptr->ano <= 2019) {
                            insere_pilha(pilha, ptr);
                        }
                        ptr = ptr->prox;
                    }
                    imprime(pilha);
                }
                break;
            case 4:
                cout << "Busca por veículo com menos de 40.000km (Fila)" << endl;

                if (ptr == NULL) {
                    cout << "A lista está vazia!!" << endl;
                } else {
                    while (ptr != NULL) {
                        if (ptr->km < 40000) {
                            insere_fila(fila, ptr);
                        }
                        ptr = ptr->prox;
                    }

                    imprime(fila);
                }
                break;
            case 5:
                cout << "Relatório: " << endl;
                imprime(lista);
                break;
            case 6:
                cout << "Finalizar Programa" << endl;
                break;
            default:
                cout << "Opcao Inválida" << endl;
                interface();
                break;
        }
    } while (op != 6);

    return 0;
}

