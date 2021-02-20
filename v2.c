#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

int board[4][4] = {0};
int *empty_space[16] = {NULL};
int n_empty_space = 16;

int findPos();
void popPos(int *position);
void pushPos(int *position);

void initializeBoard();

int main()
{
   

   return 0;
}

void popPos(int *position) {
   int i;
   for (i = 0; empty_space[i] != position && i < n_empty_space; ++i) {}

   if (i < n_empty_space) {
      --n_empty_space;
      for (i ; i < n_empty_space; ++i) {
         empty_space[i] = empty_space[i+1];
      }
   }
   empty_space[i+1] = NULL;
}

int findPos() {
   srand(time(NULL));
   if (n_empty_space == 0) { return -1; }

   int position = rand()%n_empty_space;
   return position;
}

void pushPos(int *position) {
   *position = 2;
   popPos(position);
}


void initializeBoard() {
   //* Inizializzazione Puntatori
   int k = -1;
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         empty_space[++k] = &board[i][j];
      }
   }
   n_empty_space = 16;

   //* Inizializzazione primo elemento
   int x = rand()%4;
   int y = rand()%4;
   int *position = &board[x][y];

   popPos(position);
   position = empty_space[findPos()];
   pushPos(position);
}
