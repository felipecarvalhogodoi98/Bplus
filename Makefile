#Makefile utilizado para otimizar a compilacao do projeto
#Copyright 2020 by Arthur Silveira Franco,
#     Felipe Carvalho Godoi e 
#     Iorrana Maria do Nascimento


#Variavel tipo de compilador
CC = g++

#flags utilizadas
CFLAGS = -c -std=c++14

#
all: executavel

#Linka arquivos compilados (objetos) ao executavel "executavel"
executavel: main.o Bmais.o Dado.o Pagina.o sequenceSet.o Noh.o Key.o
	$(CC) main.o Bmais.o Dado.o Pagina.o sequenceSet.o Noh.o Key.o -o executavel

#compila main.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

#compila Bmais.cpp
Bmais.o: Bmais.cpp
	$(CC) $(CFLAGS) Bmais.cpp

#compila Dado.cpp
Dado.o: Dado.cpp
	$(CC) $(CFLAGS) Dado.cpp

#compila Pagina.cpp
Pagina.o: Pagina.cpp
	$(CC) $(CFLAGS) Pagina.cpp

#compila sequenceSet.cpp
sequenceSet.o: sequenceSet.cpp
	$(CC) $(CFLAGS) sequenceSet.cpp

#compila Noh.cpp
Noh.o: Noh.cpp
	$(CC) $(CFLAGS) Noh.cpp

#compila Key.cpp
Key.o: Key.cpp
	$(CC) $(CFLAGS) Key.cpp

#remove todos os arquivos compilados (objetos) e o executavel (executavel do projeto)
clear:
	rm -rf *.o executavel
