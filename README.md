Galera, eu adicionei o cabeçaçho(comentario) em todos arquivos do projeto, tem alguns que a descrição ta meio meh pq to com sono kkkk

Eu implementei o Makefile, não sei se funciona do mesmo jeito no windows, mas no linux é só escrever "make" no terminal que ele compila todos arquivos do projeto
que tiveram modificação (na primeira vez todos :D) e gera uns arquivos com extenção .o (sao objetos -> o .cpp compilado só que sem um executavel lincado) e um arquivo que chama "executavel" -> ele é o executavel... se cês digitarem "make clear" no terminal ele vai deletar todos esses objetos (.o) e o executavel do projeto :D

se não tiver funcionando no windows o make file tem que lembrar de adicionar os novos cpp que eu dividi as classe e adicionei um main com a função main

Tipo assim agora: "g++ -o executavel main.cpp Bmais.cpp Dado.cpp Pagina.cpp sequenceSet.cpp Noh.cpp Key.cpp"

Modifiquei a funcao de imprimir a arvore(agora so imprime em arquivo "printINDEX'nome'"), ficou mais facil de visualizar


