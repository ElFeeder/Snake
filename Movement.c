#include "Snake.h"

SDL_Rect getMovement(char move[6], SDL_Rect snake, WINDOWSIZE windowSize, SDL_Renderer *render) {
  SDL_Event event;
  
  SDL_Delay(GAMESPEED);
    while(SDL_PollEvent(&event)) {
      switch(event.type)  {
        case(SDL_QUIT):
          SDL_Quit();
          exit(0);
        
        case(SDL_KEYDOWN):  // If so, in which direction
          switch(event.key.keysym.sym)  {
            case(SDLK_UP):
              if(strcmp(move, "down") != 0) // If we're going down, we can't go up directly (the same logic applies for every direction)
                strcpy(move, "up");
              break;
            
            case(SDLK_DOWN):
              if(strcmp(move, "up") != 0)
                strcpy(move, "down");
              break;

            case(SDLK_LEFT):
              if(strcmp(move, "right") != 0)
                strcpy(move, "left");
              break;

            case(SDLK_RIGHT):
              if(strcmp(move, "left") != 0)
                strcpy(move, "right");
              break;  

            case(SDLK_ESCAPE):
              SDL_Quit();
              exit(0);  
          }
          break;

        default:
          break;  
      }
    }
    
    if(strcmp(move, "up") == 0)
      snake.y = snake.y - 20;
    else if(strcmp(move, "down") == 0)
      snake.y = snake.y + 20;
    else if(strcmp(move, "left") == 0)
      snake.x = snake.x - 20;
    else if(strcmp(move, "right") == 0)
      snake.x = snake.x + 20;

    // Check if the snake has collided with a wall
    if(snake.x < 0 || snake.x > windowSize.x - 20 || snake.y < 0 || snake.y > windowSize.y - 20)
      gameOver(render);

    return snake;
}