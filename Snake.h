#ifndef SNAKE_H
#define SNAKE_H

// Usual Stuff
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// SDL
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

// Comms
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>


#define GAMESPEED 75
#define BAUDRATE B9600


typedef struct queue  {
  int x;
  int y;
  struct queue *next; 
}QUEUE;

typedef struct apple  {
  int x;
  int y;
}APPLE;

typedef struct windowSize {
  int x;
  int y;
}WINDOWSIZE;

int play(void);

QUEUE* createMember(int x, int y);

SDL_Rect drawSnake(SDL_Rect snake, SDL_Renderer *render, WINDOWSIZE windowSize);
SDL_Rect getMovement(char move[6], SDL_Rect snake, WINDOWSIZE windowSize, SDL_Renderer *render);

APPLE drawApple(SDL_Renderer *render, WINDOWSIZE windowSize, APPLE apple, QUEUE *nextToDelete);
APPLE checkCollision(SDL_Rect snake, APPLE apple, SDL_Renderer *render, WINDOWSIZE windowSize, QUEUE *nextToDelete);
APPLE newCoordinates(APPLE apple, WINDOWSIZE windowSize);

void paint(int startingX, int startingY, int endingX, int endingY, SDL_Renderer *render);
void gameOver(SDL_Renderer *render);
void blinkLED(void);

#endif