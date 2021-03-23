/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de implementacao da classe Dado que representa um pacote de rede (sao salvos nas paginas do sequence set).
*/
#include "Dado.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


Dado::Dado(unsigned tam, unsigned id){
    indice = id;
    tempo = 0;
    strcpy(origem, "0");
    strcpy(destino,"0");
    strcpy(protocolo, "0");
    tamanho = tam;
    strcpy(informacao,"0");
}

void Dado::lerDado(){
    cout << "Indice: ";
    cin >> indice;
    cout << "Tempo: ";
    cin >> tempo;
    cout << "Origem: ";
    cin >> origem;
    cout << "Destino: ";
    cin >> destino;
    cout << "Protocolo: ";
    cin >> protocolo;
    cout << "Tamanho: ";
    cin >> tamanho;
    cout << "Informacao: ";
    cin >> informacao;
}

void Dado::lerDadoCSV(unsigned pos){
    ifstream arquivo_csv("captura_pacotes.csv");

    if (arquivo_csv) {

        string linha;


        string campo; // variavel para obter um campo de cada linha lida
        string delimitador = "\",\""; // delimitador entre os campos
        unsigned posFimCampo; // posicao final do campo

        Dado nDado;

        for(unsigned i = 0; i < pos; i++) getline(arquivo_csv,linha);
        //DESCARTA AS LINHAS ANTES DO INICIO

        getline(arquivo_csv,linha);


        campo = linha.erase(0,1); // remove primeiro caracter da linha (")

        // obtendo primeiro campo, um inteiro - No.
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        indice = stoul(campo, NULL, 10);

        // obtendo segundo campo, um float - Time
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        tempo = stof(campo);

        // obtendo terceiro campo, um texto - Source
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        strcpy(origem, campo.c_str());

        // obtendo quarto campo, um texto - Destination
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        strcpy(destino, campo.c_str());

        // obtendo quinto campo, um texto - Protocol
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        strcpy(protocolo, campo.c_str());

        // obtendo sexto campo, um texto - Length
        posFimCampo = linha.find(delimitador);
        campo = linha.substr(0, posFimCampo);
        linha.erase(0, posFimCampo + delimitador.length());
        tamanho = stoul(campo);

        // obtendo �ltimo campo, um texto - Info
        // nesse caso, procuro o �ltimo aspas, fazendo busca reversa
        posFimCampo = linha.rfind("\"");
        campo = linha.substr(0, posFimCampo);
        strcpy(informacao, campo.c_str());
    }
}

//sobrecarga de atribuicao
Dado& Dado::operator =(const Dado& d){
    indice = d.indice;
    tempo = d.tempo;
    strcpy(origem, d.origem);
    strcpy(destino, d.destino);
    strcpy(protocolo, d.protocolo);
    tamanho = d.tamanho;
    strcpy(informacao, d.informacao);
    return *this;
}

//sobrecarga de comparacao (menor)
bool Dado::operator<(const Dado& d){

    int r;
    r = strcmp(this->destino, d.destino);

    if((r < 0) || ((r == 0) && (this->indice < d.indice))){
        return true;
    }else{
        return false;
    }
}

//sobrecarga de comparacao (maior)
bool Dado::operator>(const Dado& d){

    int r;
    r = strcmp(this->destino, d.destino);

    if((r > 0) || ((r == 0) && (this->indice > d.indice))){
        return true;
    }else{
        return false;
    }
}

//sobrecarga de comparacao (igual)
bool Dado::operator==(const Dado& d){
    
    int r;
    r = strcmp(this->destino, d.destino);

    if((r == 0) && (this->indice == d.indice)){
        return true;
    }else{
        return false;
    }
}

//sobrecarga de impressao (cout)
ostream& operator<<(ostream& output, const Dado& d){
    output << "Indice: " << d.indice << endl;
    output << "Tempo: " << d.tempo << endl;
    output << "Origem: " << d.origem << endl;
    output << "Destino: " <<d.destino << endl;
    output << "Protocolo: " <<d.protocolo << endl;
    output << "Tamanho: " << d.tamanho << endl;
    output << "Informacao: " << d.informacao << endl;
    return output;
}

//sobrecarga de impressao (arquivo)
fstream& operator<<(fstream& arquivo, const Dado& d){
    arquivo << "Indice: " << d.indice << endl;
    arquivo << "Tempo: " << d.tempo << endl;
    arquivo << "Origem: " << d.origem << endl;
    arquivo << "Destino: " <<d.destino << endl;
    arquivo << "Protocolo: " <<d.protocolo << endl;
    arquivo << "Tamanho: " << d.tamanho << endl;
    arquivo << "Informacao: " << d.informacao << endl;
    return arquivo;
}