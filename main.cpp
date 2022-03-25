/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: anaca
 *
 * Created on 19 de Março de 2022, 12:34
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include "funcoes.h"

using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {
    tLista* lista = inicia_lista();
    
    ifstream cadastro("BD_veiculos.txt");
    if(cadastro.is_open()){
        while(!cadastro.eof()){
           no* dados = new(no);
           
           cadastro >> dados->modelo;
           cout << dados->modelo << endl;
           cadastro >> dados->marca;
           cout << dados->marca << endl;
           cadastro >> dados->tipo;
           cout << dados->tipo << endl;
           cadastro >> dados->ano;
           cout << dados->ano << endl;
           cadastro >> dados->km;
           cout << dados->km << endl;
           cadastro >> dados->potencia;
           cout << dados->potencia << endl;
           cadastro >> dados->combustivel;
           cout << dados->combustivel << endl;
           cadastro >> dados->cambio;
           cout << dados->cambio << endl;
           cadastro >> dados->direcao;
           cout << dados->direcao << endl;
           cadastro >> dados->cor;
           cout << dados->cor << endl;
           cadastro >> dados->nPortas;
           cout << dados->nPortas << endl;
           cadastro >> dados->placa;
           cout << dados->placa << endl;
           dados->prox = NULL;
           cout << "-------------------------------------------";
           insere_ord(lista, dados);
        }
        cadastro.close();
    }else{
        cout << "Arquivo não encontrado!" << endl;
    }
    
    return 0;
}

