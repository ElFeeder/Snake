#makefile

all: Snake Clean

Play.o:	Play.c Snake.h
	gcc -g -c -I/usr/include/SDL2 -D_REENTRANT -Wall -pedantic -std=c99 -lm Play.c

Main.o:	Main.c Snake.h
	gcc -g -c -I/usr/include/SDL2 -D_REENTRANT -Wall -pedantic -std=c99 -lm Main.c 

Movement.o: Movement.c Snake.h
	gcc -g -c -I/usr/include/SDL2 -D_REENTRANT -Wall -pedantic -std=c99 -lm Movement.c

Comms.o:	Comms.c	Snake.h
	gcc -g -c -I/usr/include/SDL2 -D_REENTRANT -Wall -pedantic -std=c99 -lm Comms.c 

Snake:	Play.o	Main.o	Movement.o	Comms.o
	gcc Play.o Main.o Movement.o Comms.o -lSDL2 -lSDL2_gfx -o Snake

	#In the line above I had to remove -lSDL2_image, before it needed it, now it doesn't
Clean:
	rm Play.o Main.o Movement.o Comms.o
