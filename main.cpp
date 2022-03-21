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
           //insere(lista, dados->placa);
        }
        cadastro.close();
    }else{
        cout << "Arquivo não encontrado!" << endl;
    }
    
    return 0;
}

