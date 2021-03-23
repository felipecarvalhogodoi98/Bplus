/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
  	 Felipe Carvalho Godoi e 
  	 Iorrana Maria do Nascimento
 
  Este arquivo contem a funcao main do projeto,
   	 onde é exibida a interface grafica com todas as operacoes possiveis no projeto
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include "Dado.h"
#include "Key.h"
#include "Bmais.h"
using namespace std;

const int inicioCSV = 1;
const int fimCSV = 5190915;

int main(){
    string nomeArq, dest;
    cout << "Nome do arquivo(sem .txt): ";
    cin >> nomeArq;
    Bmais arvore(nomeArq);
    char op = 0;
    int aux;
    Dado d;
    key k;
    unsigned tam, id;
    while(op!='s'){
        cout 
        << "i - inserir dado" << endl 
        << "u - inserir dado por indice(CSV)" << endl
        << "b - buscar" << endl 
        << "e - editar" << endl 
        << "r - remover" <<  endl 
        << "d - depurar" << endl 
        << "p - depurar dados em arquivo" << endl
        << "a - depurar pela arvore" << endl
        << "l - ler do arquivo CSV" << endl 
        << "s -sair" << endl;
        cin >> op;
        switch(op)
        {
        case 'i':
            cout << "Insercao: " << endl;
            d.lerDado();
            arvore.inserir(d);
            break;
        case 'u':
            cout << "Insercao: " << endl;
            cout << "Digite o indice ate "<< fimCSV << ": ";
            cin >> aux;
            if( aux > fimCSV || aux < inicioCSV){
                cout << "Indice invalido!" << endl << endl;
            }else{
                d.lerDadoCSV(aux);
                arvore.inserir(d);    
            }
            break;
        case 'b':
            cout << "Busca: " << endl;
            cout << "Insira o Destino: ";
            cin >> dest;
            cout << "Insira o Indice: ";
            cin >> id;
            k.setIndice(id);
            k.setDestino(dest);
            arvore.buscar(k);
            break;
        case 'e':
            cout << "Edicao: " << endl;
            cout << "Insira um dado com as chaves (INDICE E DESTINO) originais: " << endl;
            d.lerDado();
            arvore.editar(d);
            break;
        case 'r':
            cout << "Remocao: " << endl;
            cout << "Insira o Destino: ";
            cin >> dest;
            cout << "Insira o Indice: ";
            cin >> id;
            k.setIndice(id);
            k.setDestino(dest);
            arvore.remover(k);

            break;
        case 'd':
            arvore.imprimirPeloSequenceSet();
            break;
        case 'p':
            arvore.imprimirEmArquivo();
            break;
        case 'a':
            arvore.imprimirPelaArvore();
            break;
        case 'l':
            cout << "Trecho disponivel "<< inicioCSV <<" a " << fimCSV << endl;
            cout << "Inicio: ";
            cin >> tam;
            cout << "Fim: ";
            cin >> id;
            if(
            tam > fimCSV || id > fimCSV || 
            tam < inicioCSV || fimCSV < inicioCSV
            || id < tam
            ){
                cout << "Intervalo Invalido do arquivo!" << endl << endl;
            }else{
                arvore.lecsv(tam, id);
            }
            
            break;
        }
    }
    return 0;
}
//-Wall -Wextra -std=c++14 Bmais.cpp Noh.cpp Dado.cpp sequenceSet.cpp Pagina.cpp Key.cpp