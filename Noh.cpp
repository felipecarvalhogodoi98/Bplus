/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de implementacao da classe noh.
*/

#include "Noh.h"
#include "Key.h"
#include "Dado.h"
#include "Pagina.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


noh::noh(char f){
    folha = f;
    quantidade = 0;
    pai = NULL;             
    //se o noh for folha, aponta pra uma pagina do sequenceSet, caso contrario, aponta para outro noh              
    for(int i=0;i<ORDEM+2; i++){
        posFilho[i] = -1;    
        filhos[i] = NULL;
    }
    
}

noh* noh::insereChave(key k, int pagEsq, int pagDir){
    if(folha){
        if(quantidade < ORDEM){

            insereChaveFolha(k, pagEsq, pagDir);
            if(pai == NULL) //raiz
                return this;
            return pai->arrumaPai();
        }else{

            //divisao de um noh
            noh *novo;
            novo = new noh();

            if(pai == NULL){// raiz

                noh *novaRaiz; 
                novaRaiz = new noh(0);//nova raiz nao é folha
                insereChaveFolha(k, pagEsq, pagDir);
                copiaMetadeNoh(novaRaiz, this, novo);
                return novaRaiz;
            }else{

                insereChaveFolha(k, pagEsq, pagDir);
                copiaMetadeNoh(pai, this, novo);
                return pai->arrumaPai();
            }
        }
    }else{
        
        //procura a folha
        noh *folha = buscaNohFolha(this, k);
        
        return folha->insereChave(k, pagEsq, pagDir);
    }
    
    
}

void noh::insereChaveFolha(key k, int pagEsq, int pagDir){
    if(quantidade == 0){
        keys[0] = k;
        posFilho[0] = pagEsq;
        posFilho[1] = pagDir;
        quantidade ++;
    }else{
        int i=0;
        while((i<quantidade) && (k > keys[i])){
            i++;
        }
        
        quantidade++;
        key auxK;
        int aux;
        while(i < quantidade){
            auxK = keys[i];
            keys[i] = k;
            k = auxK;

            aux = posFilho[i+1];
            posFilho[i+1] = pagDir;
            pagDir = aux;
            i++;
            
        }
    }
}

void noh::insereChaveNaoFolha(key k, noh* esq, noh* dir){
    folha = 0;
    if(quantidade == 0){
        keys[0] = k;
        filhos[0] = esq;
        filhos[1] = dir;
        quantidade ++;
    }else{
        int i=0;
        while((i < quantidade) && (k > keys[i])){
            i++;
        }
        
        quantidade++;
        key auxK;
        noh* aux;
        while(i < quantidade){
            auxK = keys[i];
            keys[i] = k;
            k = auxK;

            aux = filhos[i+1];
            filhos[i+1] = dir;
            dir = aux;
            i++;
            
        }
    }
}

//insere a chave k na posicao pos do noh 
void noh::insereChavePos(int pos, key k){
    int i = pos;
    key auxK;
    quantidade++;
    while((i < quantidade)){
        auxK = keys[i];
        keys[i] = k;
        k = auxK;
        i++;
    }
}
        
//insere filho na posicao pos do noh folha 
void noh::insereFilhoPos(int pos, int filho){
    int i = pos;
    int aux;
    while(i < (quantidade + 1)){
        aux = posFilho[i];
        posFilho[i] = filho;
        filho = aux;
        i++;
    }
}

//insere filho na posicao ps do noh nao folha
void noh::insereFilhoPos(int pos, noh* filho){
    int i = pos;
    noh* aux;
    filho->pai = this; // filho inserido tem esse noh como pai
    while(i < (quantidade + 1)){
        aux = filhos[i];
        filhos[i] = filho;
        filho = aux;
        i++;
    }
}

//metodo apaga primeira chave e primeiro filho do noh
void noh::apagaPrimeiraChaveEFilho(){
    if(folha){
        int i = 0;
        while(i < (quantidade - 1)){
            keys[i] = keys[i+1];
            i++;
        }

        i = 0;
        while(i < quantidade){
            posFilho[i] = posFilho[i+1];
            i++;
        }
        quantidade--;
    } else{
        int i = 0;
        while(i < (quantidade - 1)){
            keys[i] = keys[i+1];
            i++;
        }
        i = 0;
        while(i < quantidade){
            filhos[i] = filhos[i+1];
            i++;
        }
        quantidade--;
    }
}

noh* noh::buscaNohFolha(noh *umNoh, key k){
    if(umNoh->folha){
        return umNoh;
    }    
     
    int i=1;
    while((i < umNoh->quantidade) && (k > umNoh->keys[i-1])){
        i++;
    }
    if(k < umNoh->keys[i-1]){
        return buscaNohFolha(umNoh->filhos[i-1], k);
    }else{
        return buscaNohFolha(umNoh->filhos[i], k);
    }
    
}

void noh::copiaMetadeNoh(noh* pai, noh* esq, noh* dir){
    pai->folha = 0;
    int metade = ORDEM/2;
    for(int i=0;i < metade; i++){
        //posFilho, filhos e keys estourado
        dir->keys[i] = esq->keys[metade+i+1];
        dir->posFilho[i] = esq->posFilho[metade+i+1];
        dir->filhos[i] = esq->filhos[metade+i+1];
    }
    dir->posFilho[metade] = esq->posFilho[ORDEM+1];
    dir->filhos[metade] = esq->filhos[ORDEM+1];
    esq->pai = pai;
    dir->pai = pai;
    //pai nao eh folha, nao usa ponteiros para paginas do sequenceSet
    esq->quantidade = ORDEM/2;
    dir->quantidade = ORDEM/2;
    pai->insereChaveNaoFolha(esq->keys[ORDEM/2], esq, dir);
    if(!dir->folha){
        for(int i=0; i<metade+1; i++){
            dir->filhos[i]->pai = dir;
            //filhos de dir, apontavam pra esq
        }
    }
}

noh* noh::arrumaPai(){
    
    if(quantidade<=ORDEM){
        if(pai == NULL){
            return this;
        }
        return pai->arrumaPai();
    }else{
        noh *novo;
        novo = new noh(0);
        if(pai == NULL){// raiz

            noh *novaRaiz; 
            novaRaiz = new noh(0);//nova raiz nao é folha
            copiaMetadeNoh(novaRaiz, this, novo);
            return novaRaiz;
        }else{

            copiaMetadeNoh(pai, this, novo);
            return pai->arrumaPai();;
        }
    }
}

void noh::replaceChave(key k, key novaK){
    // percorre todos filhos do noh 
    int i; 
    for (i = 0; i < quantidade; i++){ 
        // Se noh nao for folha percorre a subarvore com raiz filhos[i]
        if (!folha) 
            filhos[i]->replaceChave(k, novaK); 
        if(keys[i] == k)
            keys[i] = novaK; // faz a troca de chave
    } 
  
    // percorre a ultima subarvore :D
    if (!folha) 
        filhos[i]->replaceChave(k, novaK); 
}