COMPILER = gcc
SRC = src

main: $(SRC)/interpreter.o $(SRC)/main.o
	$(COMPILER) interpreter.o main.o -o fint.exe

$(SRC)/main.o: $(SRC)/main.c
	$(COMPILER) -c $(SRC)/main.c

$(SRC)/interpreter.o: $(SRC)/interpreter.c
	$(COMPILER) -c $(SRC)/interpreter.c
