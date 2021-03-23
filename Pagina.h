/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe Pagina que possui um vetor de Dados
     de tamanho definido pela pela constante ORDEM +1 elemento em memoria para possibilitar estouro
     e tem "apontadores" para a posicao da pagina anterior e posterior bem como a quantidade de dados a mesma possui
*/

#ifndef PAGINA_H
#define PAGINA_H

#include <string.h>
#include <iostream>
#include "Dado.h"
using namespace std;

const int ORDEM = 80;

class Pagina{
    friend class sequenceSet;
    friend class Bmais;
    private:
        int quantidade;
        int proxPagina;
        int antPagina;
        //cabecalho da pagina
        //duplo encadeamento
        Dado dado[ORDEM+1];
        //possibilita estouro de dados na pagina, feito apenas em memoria
    public:
        Pagina();
        void insereDado(Dado &d);
        void removeDado(int pos);
        int buscaDado(int l, int r, Dado &d);
        
        void copiarSegundaMetade(Pagina *p);
        void copiarPrimeiraMetade(Pagina *p);
        friend ostream& operator<<( ostream& output, const Pagina& p);
        friend fstream& operator<<( fstream& arquivo, const Pagina& p);
};

#endif