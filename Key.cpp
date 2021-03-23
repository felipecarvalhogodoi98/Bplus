/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de implementacao da classe key.
*/

#include "Key.h"
#include "Dado.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void key::setIndice(unsigned id){
    this->indice = id;
}

void key::setDestino(string des){
    strcpy(this->destino, des.c_str());
}

key& key::operator=(const Dado& d){
    strcpy(destino, d.destino);
    indice = d.indice;
    return *this;
}

bool key::operator<(const key& k){

    int r;
    r = strcmp(this->destino, k.destino);

    if((r < 0) || ((r == 0) && (this->indice < k.indice))){
        return true;
    }else{
        return false;
    }
}

bool key::operator<(const Dado& d){

    int r;
    r = strcmp(this->destino, d.destino);

    if((r < 0) || ((r == 0) && (this->indice < d.indice))){
        return true;
    }else{
        return false;
    }
}

bool key::operator>(const key& k){
    
    int r;
    r = strcmp(this->destino, k.destino);

    if((r > 0) || ((r == 0) && (this->indice > k.indice))){
        return true;
    }else{
        return false;
    }
}

bool key::operator>(const Dado& d){

    int r;
    r = strcmp(this->destino, d.destino);

    if((r > 0) || ((r == 0) && (this->indice > d.indice))){
        return true;
    }else{
        return false;
    }
}

ostream& operator<<( ostream& output, const key& k){   
    output << "[d: " << k.destino << "," << "id: " << k.indice << "]";
    return output;
}

bool key::operator==(const Dado& d){
    int r;
    r = strcmp(this->destino, d.destino);

    if((r == 0) && (this->indice == d.indice)){
        return true;
    }else{
        return false;
    }
}

bool key::operator==(const key& k){
    int r;
    r = strcmp(this->destino, k.destino);

    if((r == 0) && (this->indice == k.indice)){
        return true;
    }else{
        return false;
    }
}

bool key::operator!=(const Dado& d){
    int r;
    r = strcmp(this->destino, d.destino);

    if((r == 0) && (this->indice == d.indice)){
        return false;
    }else{
        return true;
    }
}

bool key::operator!=(const key& k){
    int r;
    r = strcmp(this->destino, k.destino);

    if((r == 0) && (this->indice == k.indice)){
        return false;
    }else{
        return true;
    }
}