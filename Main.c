#include "Snake.h"

int main(void)  {
  play();
  return 0;
}

void gameOver(SDL_Renderer *render) {
  // The player has lost the game, write "Game Over" on the screen
  SDL_Event event;

  int startingX = 7, startingY = 12, endingX = 10, endingY = 12;
  
  SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // Black
  SDL_RenderClear(render);  // All in black

  SDL_SetRenderDrawColor(render, 255, 255, 255, 255); // White
  paint(startingX, startingY, endingX, endingY, render);  // Let's start to paint the letters

  startingX = 7;
  startingY = 13;
  endingX = 7;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 8;
  startingY = 16;
  endingX = 10;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);
  
  startingX = 10;
  startingY = 14;
  endingX = 10;
  endingY = 15;
  paint(startingX, startingY, endingX, endingY, render);
  
  startingX = 9;
  startingY = 14;
  endingX = 9;
  endingY = 14;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 13;
  startingY = 12;
  endingX = 16;
  endingY = 12;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 13;
  startingY = 13;
  endingX = 13;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 16;
  startingY = 13;
  endingX = 16;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 14;
  startingY = 15;
  endingX = 15;
  endingY = 15;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 19;
  startingY = 12;
  endingX = 19;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 23;
  startingY = 12;
  endingX = 23;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 20;
  startingY = 13;
  endingX = 20;
  endingY = 13;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 21;
  startingY = 14;
  endingX = 21;
  endingY = 14;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 22;
  startingY = 13;
  endingX = 22;
  endingY = 13;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 26;
  startingY = 12;
  endingX = 26;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 27;
  startingY = 12;
  endingX = 29;
  endingY = 12;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 27;
  startingY = 16;
  endingX = 29;
  endingY = 16;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 27;
  startingY = 14;
  endingX = 28;
  endingY = 14;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 7;
  startingY = 24;
  endingX = 7;
  endingY = 26;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 8;
  startingY = 23;
  endingX = 9;
  endingY = 23;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 10;
  startingY = 24;
  endingX = 10;
  endingY = 26;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 8;
  startingY = 27;
  endingX = 9;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 13;
  startingY = 23;
  endingX = 13;
  endingY = 26;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 16;
  startingY = 23;
  endingX = 16;
  endingY = 26;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 14;
  startingY = 27;
  endingX = 15;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 19;
  startingY = 23;
  endingX = 19;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 20;
  startingY = 23;
  endingX = 22;
  endingY = 23;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 20;
  startingY = 27;
  endingX = 22;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 20;
  startingY = 25;
  endingX = 21;
  endingY = 25;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 25;
  startingY = 23;
  endingX = 25;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 26;
  startingY = 23;
  endingX = 28;
  endingY = 23;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 28;
  startingY = 24;
  endingX = 28;
  endingY = 24;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 26;
  startingY = 25;
  endingX = 27;
  endingY = 25;
  paint(startingX, startingY, endingX, endingY, render);

  startingX = 28;
  startingY = 26;
  endingX = 28;
  endingY = 27;
  paint(startingX, startingY, endingX, endingY, render);

  do  {
    SDL_WaitEvent(&event);
  }while(event.key.keysym.sym != SDLK_ESCAPE && event.type != SDL_QUIT);

  SDL_Quit();
  exit(0);
}

void paint(int startingX, int startingY, int endingX, int endingY, SDL_Renderer *render)  {
  SDL_Rect r1;

  int horizontal = 0, vertical = 0;
  
  r1.w = 20;
  r1.h = 20;
  for(horizontal = startingX; horizontal <= endingX; horizontal++)  {
    r1.x = horizontal * 20;
    for(vertical = startingY; vertical <= endingY; vertical++)  {
      r1.y = vertical * 20;
      SDL_RenderFillRect(render, &r1);
    }
  }
  // Drawing made, let's render
  SDL_RenderPresent(render);
}