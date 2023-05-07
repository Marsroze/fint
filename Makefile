COMPILER = gcc
SRC = src
FLAGS = -O2

main: $(SRC)/interpreter.o $(SRC)/main.o
	$(COMPILER) $(FLAGS) interpreter.o main.o -o fint.exe

$(SRC)/main.o: $(SRC)/main.c
	$(COMPILER) $(FLAGS) -c $(SRC)/main.c

$(SRC)/interpreter.o: $(SRC)/interpreter.c
	$(COMPILER) $(FLAGS) -c $(SRC)/interpreter.c
