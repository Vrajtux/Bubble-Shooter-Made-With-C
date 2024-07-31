CC=gcc
FLAGS= -lSDL2main -lSDL2 -lSDL2_image 
compile:
	$(CC) -o test main.c $(FLAGS)
run: ./test
