all: main.c libs.c signals.c
	gcc -o sssh main.c libs.c signals.c

run: all
	./sssh

clean:
	rm sssh
