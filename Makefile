CC=gcc

ifeq ($(OS),Windows_NT)
    REMOVE=del
else
    REMOVE=rm -f
endif

all: quadrado_magico run

quadrado_magico: quadrado_magico.c quadrado_magico.h
	$(CC) -o quadrado_magico quadrado_magico.c

run:
	./quadrado_magico.exe

clean:
	$(REMOVE) quadrado_magico.exe


.PHONY: clean
