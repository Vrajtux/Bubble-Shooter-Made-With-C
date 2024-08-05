CC=gcc
FLAGS= -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer 
compile:
	$(CC) -o test main.c $(FLAGS)
run: ./test
