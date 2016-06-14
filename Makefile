
CC=gcc
CFLAGS=-w -wall - pedantic -std=c11
LFLAGS=-lm

SRC=$(wildcard *.c)
BIN=$(SRC:.c)

.PHONY: all clear help

help:
	@echo "Sintaxe make <opções>"
	@echo " Opções:"
	@echo "     help : você tem 2 opções"
	@echo " 	all : compila todo codigo que estiver na pasta"
	@echo "		clear = apaga todas as compilações feitas"
	@echo ""

all: $(BIN)

clear:
	@rm -f $(BIN)

%:%.c
	@echo -n "Compilando $@"
	@S(CC) $< -o $(CFLAGS) $(LFLAGS) && echo "COMPILADO"