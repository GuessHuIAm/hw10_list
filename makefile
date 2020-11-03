all: pepper.o main.o
	gcc -o peppers main.o pepper.o

main.o: main.c
	gcc -c main.c

pepper.o: pepper.c pepper.h
	gcc -c pepper.c

run:
	./peppers

clean:
	rm main.o
	rm pepper.o
	rm peppers
