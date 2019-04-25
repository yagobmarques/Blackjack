#Makefile for "LP1" C++ application
#Created by Yago Marques
 
 PROG = blackjack!
 CC = g++
 FLAGS = -O0 -g -Wall
 OBJS = main.o mesa.o jogador.o dado.o

 $(PROG):$(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)

 main.o:
	$(CC) $(FLAGS) -c main.cpp
 mesa.o:
	$(CC) $(FLAGS) -c mesa.cpp
 jogador.o:
	$(CC) $(FLAGS) -c jogador.cpp
 dado.o:
	$(CC) $(FLAGS) -c dado.cpp
 clean:
	rm -f $(PROG) $(OBJS)
	