/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe sequenceSet, uma das principais estuturas do projeto
     ela é responsavel por armazenar, fazer leitura e modificacao dos dados em disco.
     a classe sequenceSet possui um cabecalho do arquivo com informacoes como a posicao da primeira Pagina,
     numero de paginas armazenadas e a proxima pagina dispnivel. 
     Possuí tambem o nome do Arquivo em que os dados estao/serao armazenados
*/
#ifndef SEQUENCESET_H
#define SEQUENCESET_H

#include <iostream>
#include <string.h>
#include "Dado.h"
#include "Pagina.h"
using namespace std;

struct Cabecalho{
    unsigned nSequencia;
    int pSequencia;
    int proxPaginaDisponivel;
};

class sequenceSet{
    friend class Bmais;
    private:
        Cabecalho cab;
        string nomeArq;

        //faz a leitura da pagina com sua posicao
        void lerPaginaArquivo(Pagina *p, int posPagina);
        //atualiza o cabecalho no arquivo
        void atualizaCabecalhoArquivo();
        //insere uma pagina no arquivo com sua posicao, se houver a pagina reescreve por cima
        void inserirPaginaArq(Pagina p, int pos);

    public:
        sequenceSet(string Arq);
        bool vazio();
        //retorna 1 se nao houver nenhum dado

        void depurar();

        void depurarEmArq();
};


#endif