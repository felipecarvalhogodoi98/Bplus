/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe key.
*/

#ifndef KEY_H
#define KEY_H
#include "Dado.h"
#include <string.h>
#include <iostream>
using namespace std;

class key{
    friend class noh;
    friend class Bmais;
    private:
        unsigned indice;
        char destino[40];
    public:
        void setIndice(unsigned id);
        void setDestino(string des);
        key& operator=(const Dado &d);
        bool operator<(const key& k);
        bool operator<(const Dado& d);
        bool operator>(const key& k);
        bool operator>(const Dado& d);
        bool operator==(const Dado& d);
        bool operator==(const key& k);
        bool operator!=(const Dado& d);
        bool operator!=(const key& k);

        friend ostream& operator<<( ostream& output, const key& k);
};


#endif