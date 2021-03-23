/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de implementacao da classe Pagina que possui um vetor de Dados
     de tamanho definido pela pela constante ORDEM +1 elemento em memoria para possibilitar estouro
     e tem "apontadores" para a posicao da pagina anterior e posterior bem como a quantidade de dados a mesma possui
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include "Dado.h"
#include "Pagina.h"
using namespace std;


Pagina::Pagina(){
    quantidade = 0;
    proxPagina = -1;
    antPagina = -1;
}

void Pagina::insereDado(Dado& d){

    if(quantidade == 0){
        dado[0] = d;
        quantidade ++;
    }else{
        Dado aux;
        int i=0;
        while((dado[i] < d) && (i < quantidade)){
            i++;
        }
        quantidade++;
        while(i < quantidade){
            aux = dado[i];
            dado[i] = d;
            d = aux;
            i++;
        }
    }
}

void Pagina::removeDado(int pos){

    for(int i = pos + 1; i < quantidade; i++){
        dado[i - 1] = dado[i];
    }
    quantidade--;


}

//busca um dado num vetor de dados(busca binaria recursiva)
//se achar o dado, retorna sua posicao, se nao retorna -1
int Pagina::buscaDado(int l, int r, Dado &d){
    if(r >= l){
        int mid = l + (r-l) / 2;


        if(dado[mid] == d){
            return mid;
        }

        if(dado[mid] > d){
            return buscaDado(l, mid - 1, d);
        }

        if(dado[mid] < d){
            return buscaDado(mid + 1, r, d);
        }
    }

    return -1;
}

ostream& operator<<(ostream& output, const Pagina &p){
    output << "Quantidade: " << p.quantidade << endl;
    output << "proxPagina: " << p.proxPagina << endl;
    output << "antPagina: " << p.antPagina << endl << endl;
    return output;
}

fstream& operator<<(fstream& arquivo, const Pagina &p){
    arquivo << "Quantidade: " << p.quantidade << endl;
    arquivo << "proxPagina: " << p.proxPagina << endl;
    arquivo << "antPagina: " << p.antPagina << endl << endl;
    return arquivo;
}

void Pagina::copiarSegundaMetade(Pagina *p){
    for(int i=ORDEM/2; i<ORDEM+1; i++){
        p->dado[p->quantidade] = dado[i];
        p->quantidade++;
    }
    quantidade = ORDEM/2;
}

//copia a primeira metade de uma pagina em outra
//copia n em p
void Pagina::copiarPrimeiraMetade(Pagina *p){
    int metade = ORDEM/2;
    for(int i = 0; i<metade; i++){
        quantidade ++;
        dado[(metade) + i] = p->dado[i];
        p->quantidade --;
    }

}