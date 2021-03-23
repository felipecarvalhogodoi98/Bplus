/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe Bmais, estrutura principal do projeto que contem
  	 um ponteiro para o noh raiz da arvore de indices
  	 e um ponteiro para o sequenceSet (estrutura que armazena os dados em disco)
*/



#ifndef BMAIS_H
#define BMAIS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "Dado.h"
#include "Pagina.h"
#include "Key.h"
#include "Noh.h"
#include "sequenceSet.h"
using namespace std;

class Bmais{
    private:
        string nomeArqBmais;
        sequenceSet *set;
        noh *raiz;

        void lerFilhosArq(noh* umNoh);
        //faz leitura de todos os noh recursivamente do arquivo para memoria

        void escreveFilhosArq(noh *umNoh, int num);
        //com arquivo aberto escreve os noh's recursivamente

        int posFilhosArq(noh *umNoh, int *num);
        //retorna a posicao onde o noh deve ser arquivado
        //semelhante a recursao de percorer em ordem de uma ABB

        int buscaAux(noh *umNoh, Dado &d);
        //busca uma pagina do sequenceSet a partir da raiz da arvore B+
        //funcao recursiva

        void removerInterno(key k, noh* umNoh, noh* filho);
        //funcao recursiva para remocao nos nohs nao folha

        void removerInterno(key k, noh* umNoh, int filho);
        //funcao recursiva para remocao nos nohs foha

        void imprimirPelaArvoreAux(noh* umNoh, string nomeArq, int espaco);
        //percorre todos noh's da arvore imprimindo-os em arquivo

        int irmaoEsq(noh* umNoh, int &posP);
        //retorna a posicao de uma pagina do sequence set(pagina é anterior de posP)
        //metodo para nohs folha 

        int irmaoDir(noh* umNoh, int &posP);
        //retorna a posicao de uma pagina do sequence set(pagina é proxima de posP)
        //metodo para nohs folha 

        int irmaoEsq(noh* umNoh, noh* irmao);
        //retorna a posicao do irmao esquerdo no vetor de filhos de um noh pai, dado o noh irmao
        //metodo para nohs nao folha 

        int irmaoDir(noh* umNoh, noh* irmao);
        //retorna a posicao do irmao direito no vetor de filhos de um noh pai, dado o noh irmao
        //metodo para nohs nao folha 

        void destruirNoh(noh* umNoh);
        //a partir de um noh, destroi todos seus filhos

    public:
        Bmais(string nome);
        //se o sequenceSet existe com mais de uma pagina, faz leitura da raiz e de seus respectivos filhos
        //caso contrario, apenas deixa a raiz como nula
        
        ~Bmais();
        //arquiva a arvore num arquivo
        //destroi todos os noh's da arvore

        void inserir(Dado &d);
        //insere um dado(se nao ja nao estiver arquivado) no sequenceSet
        //faz as operacoes necessarias na arvore

        void editar(Dado &d);
        //se o dado existir no arquivo, faz a edicao(menos das chaves)

        void buscar(key &k);
        //com auxilio de buscaAux, busca um dado na pagina do sequenceSet
        //se este dado existr na pagina, faz impressao do mesmo
        //caso contrario exibe mensagem de erro

        void remover(key &k);
        //busca pela chave, se houver o dado, remove o do sequenceSet
        //apos remocao, arruma a arvore se necessario

        void imprimirPelaArvore();
        //imprime a arvore da raiz aos noh's folhas

        void imprimirPeloSequenceSet();
        //imprime os dados e as informacoes de paginas

        void imprimirEmArquivo();
        //semelhante a imprirPeloSequenceSet(), faz o mesmo tipo de impressao, mas em arquivo

        void lecsv(unsigned inicio, unsigned fim);
        //a partir de 'inicio' e 'fim', insere um intevalo de dados do arquivo CSV disponibilizado

};




#endif