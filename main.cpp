#include <iostream>
#include <time.h>
using namespace std;

int board[4][4] = {0};

void random(int *board[]); 		// Assegna il valore alle celle vuote
void startBoard(int *board[]);	// Assegna due celle randomiche 

// Comandi
int somma(int first_element, int second_element);
void userMove();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void endGame();

int main()
{
   

   return 0;
}

void random(int *board[]) {
   int i = 0;
   do {
         srand(time(NULL));
         int x = rand()%4;
         int y = rand()%4;

         if (board[x][y] == 0) {
            board[x][y] = 2;
            ++i;
         }
      }  while (i < 1);
}

void startBoard(int *board[]) {
   int i = 0;
   do {
         srand(time(NULL));
         int x = rand()%4;
         int y = rand()%4;

         if (board[x][y] == 0) {
            board[x][y] = 2;
            ++i;
         }
   }  while (i < 2);
}

void userMove() {
   char user_move = getchar();
   user_move |= 32;
   
   switch(user_move) {
      case 'W': 
      break; 
      case 'A': 
      break;
      case 'S': 
      break;
      case 'D': 
      break;

      default:
      break;
   }
}

void moveUp() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 4; ++j) {
         
      }  
   }
}
