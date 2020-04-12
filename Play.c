#include "Snake.h"

int play(void) {
  WINDOWSIZE windowSize;               // Each grid slot is 20p x 20p
  
  QUEUE *new;                         // Pointer used to make a list
  QUEUE *nextToDelete, *ghost, *last; // Pointers used in managing the list

  SDL_Window* window = NULL;          // SDL shits
  SDL_Renderer* render = NULL;        // SDl shits

  SDL_Rect snake;                     // The snake
  SDL_Rect delete;                    // This will delete the tail of the snake

  APPLE apple;                        // This will keep the apple's coordinates (has to be a multiple of 20)
  APPLE newApple;                     // This will save the new apple's coordinates

  char move[6] = "up";                // This will save what move it is (begins up)
  
  windowSize.x = 800;
  windowSize.y = 800;

  srand (time(NULL));                 // Will be used for rand()
  
  // SDL_Init initiates the library, returns a positive value or zero if all went well
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)  {
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize.x, windowSize.y, SDL_WINDOW_SHOWN);

    if(window != NULL)                            // If all went well, render the window
      render = SDL_CreateRenderer(window, -1, 0);
  }
  else  {                                         // If something went wrong, quit
    SDL_Quit();
    return 0;
  }

  // All is fine, let's do the background
  SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // Black
  SDL_RenderClear(render);

  //Let's draw the snake and the apple
  snake = drawSnake(snake, render, windowSize);
  apple = drawApple(render, windowSize, apple, NULL);

  delete.x = snake.x;
  delete.y = snake.y + 40;  // The "tail"
  delete.w = 20;
  delete.h = 20;

  // We'll now put the three generated blocks of the snake on the list to be "deleted" in the future
  new = createMember(delete.x, delete.y);
  nextToDelete = new;
  last = nextToDelete;  // This will help maintain order in the list
  ghost = nextToDelete; // This will help freeing memory

  delete.y = snake.y + 20;  // The middle block
  new = createMember(delete.x, delete.y);
  last->next = new;     
  last = new;

  delete.y = snake.y;   // The head
  new = createMember(delete.x, delete.y);
  last->next = new;     
  last = new;

  // All set, let's play
  while(1)  {
    // Let's see if the user wants to change the direction of the snake
    snake = getMovement(move, snake, windowSize, render);

    SDL_SetRenderDrawColor(render, 0, 255, 0, 255); // Green
    SDL_RenderFillRect(render, &snake);
    SDL_RenderPresent(render);

    // Let's see if the snake ate the apple or itself
    newApple = checkCollision(snake, apple, render, windowSize, nextToDelete);

    if(newApple.x == apple.x && newApple.y == apple.y)  { // The snake didn't eat the apple, it doesn't get bigger
      delete.x = nextToDelete->x;                         // Save the coordinates of the block we're going to delete
      delete.y = nextToDelete->y;

      SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // Black
      SDL_RenderFillRect(render, &delete);          // Let's delete its tail
      SDL_RenderPresent(render);

      nextToDelete = nextToDelete->next;            // Move along the list
      free(ghost);
      ghost = nextToDelete;
    }
    // If it did eat the apple, we don't delete its tail

    //Let's put the new block on the list
    new = createMember(snake.x, snake.y);
    last->next = new;
    last = new;

    apple = newApple;
  }

  SDL_Quit();
  return 0;
}

QUEUE* createMember(int x, int y)  { // This will create another member to add to the list
  QUEUE *new = NULL;

  new = malloc(sizeof(QUEUE));
  new->x = x;
  new->y = y;
  new->next = NULL;

  return new;
}

SDL_Rect drawSnake(SDL_Rect snake, SDL_Renderer *render, WINDOWSIZE windowSize) {
  do  {
    snake.x = rand() % windowSize.x;
  } while(snake.x % 20 != 0); // Has to be a multiple of 20

  do  {
    snake.y = rand() % windowSize.y;
  } while(snake.y % 20 != 0);

  snake.w = 20;
  snake.h = 20;

  // We want to snake to spawn only in the bottom half
  if(snake.y < 400)
    snake.y = snake.y + 300;
  
  SDL_SetRenderDrawColor(render, 0, 255, 0, 255); // Green
  SDL_RenderFillRect(render, &snake);

  snake.y = snake.y - 20;
  SDL_RenderFillRect(render, &snake);

  snake.y = snake.y - 20;
  SDL_RenderFillRect(render, &snake);

  //Drawings made, update screen
  SDL_RenderPresent(render);

  return snake;
}

APPLE drawApple(SDL_Renderer *render, WINDOWSIZE windowSize, APPLE apple, QUEUE *nextToDelete) {
  QUEUE *aux = nextToDelete;
  
  apple = newCoordinates(apple, windowSize);
  
  while(aux != NULL)  {
    if(aux->x == apple.x && aux->y == apple.y)  {  // The apple would spawn inside the snake
        aux = nextToDelete;
        apple = newCoordinates(apple, windowSize);
    }
    else  {
      if(aux->next != NULL)
        aux = aux->next;
      else
        break;
    }
  }

  filledCircleRGBA(render, apple.x + 10, apple.y + 10, 9.5, 255, 0, 0, 255); // Red (+10 is to center the circle)
  
  //Drawing made, update screen
  SDL_RenderPresent(render);

  return apple;
}

APPLE newCoordinates(APPLE apple, WINDOWSIZE windowSize)  {
  do  {
    apple.x = rand() % windowSize.x;
  } while(apple.x % 20 != 0); // Has to be a multiple of 20

  do  {
    apple.y = rand() % windowSize.y;
  } while(apple.y % 20 != 0);

  return apple;
}

APPLE checkCollision(SDL_Rect snake, APPLE apple, SDL_Renderer *render, WINDOWSIZE windowSize, QUEUE *nextToDelete)  {
  QUEUE *aux = nextToDelete;
  
  if(snake.x == apple.x && snake.y == apple.y)  {  // The snake ate the apple
    system("sudo ./Comms.py g");       //  Each time the snake eats an apple, light up an LED (g = green)
    apple = drawApple(render, windowSize, apple, nextToDelete);
  }

  while(aux != NULL)  {
    if(aux->x == snake.x && aux->y == snake.y)  // The snake ate itself, end game
      gameOver(render);

    if(aux->next != NULL)
      aux = aux->next;
    else
      break;
  }
  
  return apple;
}