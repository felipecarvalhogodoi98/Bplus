/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de cabecalho da classe noh.
*/

#ifndef NOH_H
#define NOH_H
#include "Dado.h"
#include "Key.h"
#include "Pagina.h"
#include <string.h>
#include <iostream>
using namespace std;

class noh{
    friend class Bmais;
    private:
        int folha; // 1 -> folha ---- 0-> nao folha
        int quantidade;

        noh *pai;    //ponteiros para noh's so vao existir em memoria
        noh *filhos[ORDEM+2];//possibilita estouro, vetor de ponteiros apenas em memoria
        
        int posFilho[ORDEM+2]; //posicao no sequenceSet ou no arquivo INDEX
        key keys[ORDEM+1]; //chaves
        
        void insereChaveFolha(key k, int pagEsq, int pagDir);
        //insere uma chave em um noh que seja folha
        //copia a chave que vem do sequenceSet

        void insereChaveNaoFolha(key k, noh* esq, noh* dir);
        //insere uma chave em um noh que nao seja folha
        //"pega" uma chave de uma folha ou outro noh nao folha

        void insereChavePos(int pos, key k);
        //insere a chave k na posicao pos do noh 

        void insereFilhoPos(int pos, int filho);
        //insere filho na posicao pos do noh folha 

        void insereFilhoPos(int pos, noh* filho);
        //insere filho na posicao ps do noh nao folha

        void apagaPrimeiraChaveEFilho();
        //metodo apaga primeira chave e primeiro filho da folha

        void copiaMetadeNoh(noh* pai, noh*esq, noh* dir);
        //copia metade de esq em dir
        //o noh ja esta estourado
        //passa o elemento central para o pai

        noh* arrumaPai();
        //a partir do noh verifica se precisa de ser arrumado
        //verifica todos os pais, ate chegar na raiz

        
    public:
        noh(char f = 1);

        noh* buscaNohFolha(noh *umNoh, key k);
        //busca um noh onde a chave pode ser inserida, ou onde pode conter a chave

        noh* insereChave(key k, int pagEsq, int pagDir);
         //insere uma chave em um noh qualquer
        
        void replaceChave(key k, key novaK);
        //troca a chave k por novaK

};


#endif