#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <string>

#include "funcoes.h"

using namespace std;

void interface() {
    cout << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << "|         GERENCIAMENTO DE BUSCA            |" << endl;
    cout << "|     Escolha qual comando deseja fazer:    |" << endl;
    cout << "|       1)Adicinar veiculo.                 |" << endl;
    cout << "|       2)Remover veiculo.                  |" << endl;
    cout << "|       3)Busca (Ano <= 2015 - Pilha).      |" << endl;
    cout << "|       4)Busca (Km < 20.000 - Fila).       |" << endl;
    cout << "|       5)Relatorio.                        |" << endl;
    cout << "+-------------------------------------------+" << endl;
}

// Variaveis---------------------------------------------------------
tPilha *pilha;
tFila *fila;
tLista *lista;

// ------------------------------------------------------------------

int main(int argc, char** argv) {
    int op;
    ifstream cadastro("BD_veiculos.txt");
    if (cadastro.is_open()) {
        lista = inicia_lista();
        pilha = inicia_pilha();
        fila = inicia_fila();
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
        cout << "Arquivo nao encontrado!" << endl;
        delete(lista);
        return 0;
    }
    do {
        interface();
        cout << "Digite a opcao que deseja realizar: ";
        cin >> op;
        cout << endl;
        switch (op) {
            case 1:
            {
                cout << "Digite as informacoes do veiculo:" << endl << endl;
                no veiculo;

                cout << "Modelo do veiculo: (Para nomes compostos: nome1_nome2)" << endl;
                cin >> veiculo.modelo;

                cout << "Marca do veiculo: " << endl;
                cin >> veiculo.marca;

                cout << "Tipo do veiculo: " << endl;
                cin >> veiculo.tipo;

                cout << "Ano do veiculo: " << endl;
                cin >> veiculo.ano;

                cout << "Km do veiculo: " << endl;
                cin >> veiculo.km;

                cout << "Potencia do veiculo: " << endl;
                cin >> veiculo.potencia;

                cout << "Combustivel do veiculo: " << endl;
                cin >> veiculo.combustivel;

                cout << "Cambio do veiculo: " << endl;
                cin >> veiculo.cambio;

                cout << "Direcao do veiculo: " << endl;
                cin >> veiculo.direcao;

                cout << "Cor do veiculo: " << endl;
                cin >> veiculo.cor;

                cout << "Numero de portas do veiculo: " << endl;
                cin >> veiculo.nPortas;

                cout << "Placa do veiculo: " << endl;
                cin >> veiculo.placa;

                veiculo.prox = NULL;

                if(insere_enc(lista, veiculo.placa, &veiculo)){
                    cout << "Adicionado com sucesso!" << endl;
                } else {
                    cout << "Falha ao adicionar." << endl;
                }
            };
            break;
            case 2:
            {
                cout << "Digite a placa do veiculo que sera removida: ";
                string placa;

                cin >> placa;
                cout << endl;

                if (remove_enc(lista, placa)) {
                    cout << "Removido com sucesso!" << endl;
                } else {
                    cout << "Falha ao remover." << endl;
                }
            }
            break;
            case 3:
            {
                cout << "Busca por veiculos ano 2015 ou menos. (Pilha)" << endl;
                no *ptr = lista->lista;
                while (ptr != NULL) {
                    if (ptr->ano <= 2015) {
                        insere_pilha(&ptr, pilha);
                    }
                    ptr = ptr->prox;
                }
                imprime_pilha(pilha);
            }
            break;
            case 4:
            {
                cout << "Busca por veiculo com menos de 20.000km (Fila)" << endl;
                no *ptr = lista->lista;
                while (ptr != NULL) {
                    if (ptr->km < 20000) {
                        insere_fila(&ptr, fila);
                    }
                    ptr = ptr->prox;
                }
                imprime_fila(fila);
            }
            break;
            case 5:
            {
                cout << "Relatorio: " << endl;
                imprime(lista);
            }
            break;
            default:
            {
                encerra_pilha(pilha);
                encerra_fila(fila);
                encerra_lista(lista);
                cout << "+-------------------------------------------+" << endl;
                cout << "|      Programa finalizado com sucesso!!    |" << endl;
                cout << "+-------------------------------------------+" << endl;
                op = 6;
            }
            break;
        }
    } while (op != 6);
    return 0;
}
