/*
  Projeto pratico de Estrutura de dados - Parte 2
     (Estrutura de Dados)

  Sequence Set com Arvore B+ de indices
     para armazenamentos de pacotes de rede

  Copyright 2020 by Arthur Silveira Franco,
     Felipe Carvalho Godoi e 
     Iorrana Maria do Nascimento
 
  Este e o arquivo de implementacao da classe sequenceSet, uma das principais estuturas do projeto
     ela é responsavel por armazenar, fazer leitura e modificacao dos dados em disco.
     a classe sequenceSet possui um cabecalho do arquivo com informacoes como a posicao da primeira Pagina,
     numero de paginas armazenadas e a proxima pagina dispnivel. 
     Possuí tambem o nome do Arquivo em que os dados estao/serao armazenados
*/
#include "sequenceSet.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;



sequenceSet::sequenceSet(string Arq){
    nomeArq = Arq;
    fstream arq(nomeArq.c_str(), ios:: in | ios::out | ios::binary);
    if(arq){
        //se abrir o arquivo, copia o cabecalho
        arq.read((char*) &(cab), sizeof(Cabecalho));
        arq.close();
    }else{
        //caso nao abrir o arquivo, apenas coloca o set como vazio
        ofstream arq(nomeArq.c_str(),ios::binary);
        cab.nSequencia = 0;
        cab.pSequencia = -1;
        cab.proxPaginaDisponivel = 0;
        arq.write((char*) &(cab), sizeof(Cabecalho));
        arq.close();
    }
    
}

bool sequenceSet::vazio(){
    return cab.pSequencia == -1;
}

//faz a leitura da pagina com sua posicao
void sequenceSet::lerPaginaArquivo(Pagina *p, int posPagina){
    fstream arq(nomeArq.c_str(), ios::in | ios:: out | ios:: binary);

    int posArq = sizeof(Cabecalho) + sizeof(Pagina)*posPagina;

    arq.seekg(posArq);
    arq.read((char*) (p), sizeof(Pagina));

    arq.close();

}

//atualiza o cabecalho no arquivo
void sequenceSet::atualizaCabecalhoArquivo(){
    fstream arq(nomeArq.c_str(), ios::in | ios:: out | ios:: binary);

    arq.write((char*) &(cab), sizeof(Cabecalho));

    arq.close();
}

//insere uma pagina no arquivo com sua posicao, se houver a pagina reescreve por cima
void sequenceSet::inserirPaginaArq(Pagina p, int pos){
    fstream arq(nomeArq.c_str(), ios::binary | ios::in | ios::out);
    arq.seekg(sizeof(Cabecalho) + sizeof(Pagina)*pos); //posiciona no arquivo o local da pagina
    arq.write((char*) &(p), sizeof(Pagina));
    arq.close();
}

//a partir da primeira pagina(se houver, imprime todas elas)
void sequenceSet::depurar(){
    cout << "nSequencia: " << cab.nSequencia << endl;
    cout << "proxPaginaDisponivel: " << cab.proxPaginaDisponivel << endl;
    cout << "pSequencia: " << cab.pSequencia << endl;
    if(vazio()){
        cout << "------------------------------------------------------------" << endl;
        cout << "sequenceSet vazio!" << endl << endl;
    }else{
        Pagina p;
        int i=cab.pSequencia;
        do{
            lerPaginaArquivo(&p, i);
            cout << "------------------------------------------------------------" << endl;
            cout << "Pagina: " << i << endl;
            cout << p << endl;
            for(int i=0; i<p.quantidade; i++) cout << p.dado[i] << endl; 
            i = p.proxPagina;
        }while(i!= -1);
        
    }
}

void sequenceSet::depurarEmArq(){
    string nome;
    nome = "print" + nomeArq;

    ofstream arq(nome.c_str());
    arq << "nSequencia: " << cab.nSequencia << endl;
    arq << "proxPaginaDisponivel: " << cab.proxPaginaDisponivel << endl;
    arq << "pSequencia: " << cab.pSequencia << endl;
    if(vazio()){
        arq << "------------------------------------------------------------" << endl;
       arq << "sequenceSet vazio!" << endl << endl;
    }else{
        Pagina p;
        int i=cab.pSequencia;
        do{
            lerPaginaArquivo(&p, i);
            arq << "------------------------------------------------------------" << endl;
            arq << "Pagina: " << i << endl;
            arq << p << endl;
            for(int i=0; i<p.quantidade; i++) arq << p.dado[i] << endl;
            i = p.proxPagina;
        }while(i!= -1);
        
    };
    cout << "Arquivo 'print"<< nomeArq << "' criado/atualizado!" << endl << endl;
    arq.close();
}