#Makefile for "LP1" C++ application
#Created by Yago Marques
 
 PROG = blackjack! 
 CC = g++
 FLAGS = -std=c++11 -O0 -g -Wall
 OBJS = $(BIN_PATH)/main.o $(BIN_PATH)/mesa.o $(BIN_PATH)/jogador.o $(BIN_PATH)/dado.o $(BIN_PATH)/lobby.o
 BIN_PATH = ./BinFiles
 $(PROG):$(OBJS)
	$(CC) -o $(PROG) $(OBJS)
 all:
	$(PROG)
 $(BIN_PATH)/main.o:
	$(CC) $(FLAGS) -c ./Classes/Main/main.cpp
 $(BIN_PATH)/mesa.o: ./Classes/Mesa/mesa.h
	$(CC) $(FLAGS) -c ./Classes/Mesa/mesa.cpp
 $(BIN_PATH)/jogador.o: ./Classes/Jogador/jogador.h
	$(CC) $(FLAGS) -c ./Classes/Jogador/jogador.cpp
 $(BIN_PATH)/dado.o: ./Classes/Dado/dado.h
	$(CC) $(FLAGS) -c ./Classes/Dado/dado.cpp
 $(BIN_PATH)/lobby.o: ./Classes/Lobby/lobby.h
	$(CC) $(FLAGS) -c ./Classes/Lobby/lobby.cpp
	mv *.o ./BinFiles/
 cls:
	rm -f $(PROG) $(OBJS)