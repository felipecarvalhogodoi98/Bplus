/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe Dado que representa um pacote de rede (sao salvos nas paginas do sequence set).
*/

#ifndef DADO_H
#define DADO_H

#include <string.h>
#include <iostream>
using namespace std;

class Dado{
    friend class Pagina;
    friend class sequenceSet;
    friend class key;
    friend class Bmais;
    private:
        unsigned indice;
        float tempo;
        char origem[40];
        char destino[40];
        char protocolo[18];
        unsigned tamanho;
        char informacao[1650];
    public:

        Dado(unsigned tam = 0, unsigned id = 0);
        void lerDado();
        void lerDadoCSV(unsigned pos);

        //sobrecarga de atribuicao
        Dado& operator =(const Dado &d);
        //sobrecarga de atribuicao
        bool operator<(const Dado& d);
        //sobrecarga de comparacao (menor)

        bool operator>(const Dado& d);
        //sobrecarga de comparacao (maior)

        bool operator==(const Dado& d);
        //sobrecarga de comparacao (igual)

        friend ostream& operator<<( ostream& output, const Dado& d);
        //sobrecarga de impressao (cout)

        friend fstream& operator<<(fstream& arquivo, const Dado& d);
        //sobrecarga de impressao (arquivo)
};


#endif