#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include "funcoes.h"

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
Pilha *pilha;
Fila *fila;

tLista *lista;

// ------------------------------------------------------------------

int main(int argc, char** argv) {
    int op;
    lista = inicia_lista();
    
    ifstream cadastro("testes.txt");
    if(cadastro.is_open()){   
        while(!cadastro.eof()){
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

    do {
        interface();
        cout << "Digite o comando: " << endl;
        cin >> op;
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

                if(insere_enc(lista, veiculo.placa, &veiculo)){
                    cout << "Adicionado com Sucesso!" << endl;
                } else {
                    cout << "Falha ao adicionar." << endl;
                }
                interface();
                op = 2; 
                break;
            case 2:
                cout << "Remover Veículo" << endl;
                cout << "Digite a placa do Veículo que será removida: ";
                int placa;
                placa = 4572; // cin >> placa;
                cout << endl;

                if(remove_enc(lista, placa)){
                    cout << "Removido com sucesso" << endl;
                } else {
                    cout << "Falha ao remover" << endl;
                }

                interface();
                op = 5; 
                break;
            case 3:
                cout << "Busca por veículos ano 2019 ou menos. (Pilha)" << endl;

                // delete(pilha);
                // pilha->topo = NULL;
                    
                // no *ptr = lista->lista;
                // while(ptr != NULL){
                //     if(ptr->ano <= 2019) {
                //         insere_pilha(ptr, pilha);
                //     }
                //     ptr = ptr->prox;
                // }
                // imprime_pilha(pilha);
                interface();
                break;
            case 4:
                cout << "Busca por veículo com menos de 40.000km (Fila)" << endl;
                // delete(fila);
                    
                // no *ptr = lista->lista;
                // while(ptr != NULL){
                //     if(ptr->km < 40000) {
                //         insere_fila(ptr, fila);
                //     }
                //     ptr = ptr->prox;
                // }

                // imprime_fila(fila);

                interface();
                break;
            case 5:
                cout << "Relatório: " << endl;
                imprime(lista);

                interface();
                op = 6; // Temp
                break;
            case 6:
                cout << "Finalizar Programa" << endl;
                op = 7;
                break;
            default:
                cout << "Opcao Inválida" << endl;
                interface();
                break;
        }
    } while (op != 7);
    
    return 0;
}

