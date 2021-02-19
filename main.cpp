#include <iostream>
#include <time.h>

using namespace std;

int board[4][4] = {0};

void random(); // Assegna il valore alle celle vuote
void startBoard(); // Assegna due celle randomiche 

void userMove();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void printBoard();

int main() {

   puts("\nStartup\n");
   startBoard();
   printBoard();
   
   puts("\nPrimo Rendom\n");
   random();
   printBoard();
   
   puts("\nMoveLeft\n");
   moveLeft();
   random();
   printBoard();
   
   puts("\nMoveDown\n");
   moveDown();
   random();
   printBoard();

   return 0;
}

void random() {
  int i = 0;
  do {
    srand(time(NULL));
    int x = rand() % 4;
    int y = rand() % 4;

    if (board[x][y] == 0) {
      board[x][y] = 2;
      ++i;
    }
  } while (i < 1);
}

void startBoard() {
  int i = 0;
  do {
    srand(time(NULL));
    int x = rand() % 4;
    int y = rand() % 4;

    if (board[x][y] == 0) {
      board[x][y] = 2;
      ++i;
    }
  } while (i < 2);
}

void userMove() {
  char user_move = getchar();
  user_move ^= 32;

  switch (user_move) {
  case 'W': moveUp();
    break;
  case 'A': moveLeft();
    break;
  case 'S': moveDown();
    break;
  case 'D': moveRight();
    break;

  default:
    break;
  }
}


void moveUp() {

   for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 4; ++j) {
         for (int k = j; k > 0; k--) {
            if (board[k - 1][i] == 0) {
               board[k - 1][i] = board[k][i]; //spostamento elemento
               board[k][i] = 0;
            }

            else if ( board[k - 1][i] & board[k][i] ) {
                  board[k - 1][i] *= 2;
                  board[k][i] = 0;
               } 

            else { break; }
         } //* Fine Ciclo
      }
   }
}

void moveDown() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 2; j >= 0; --j) {
         for (int k = j; k < 3; k++) {
            if (board[k + 1][i] == 0) {
               board[k + 1][i] = board[k][i]; //spostamento elemento
               board[k][i] = 0;
            }

            else if ( board[k + 1][i] & board[k][i] ) {
               board[k + 1][i] *= 2;
               board[k][i] = 0;
            } 

            else { break; }
         } //* Fine Ciclo
      }
   }
}

void moveLeft() {

   for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 4; ++j) {
         for (int k = j; k > 0; k--) {
            if (board[i][k-1] == 0) {
               board[i][k-1] = board[i][k]; //spostamento elemento
               board[i][k] = 0;
            }

            else if ( board[i][k - 1] & board[i][k] ) {
               board[i][k-1] *= 2;
               board[i][k] = 0;
            } 

            else { break; }
         } //* Fine Ciclo
      }
   }
}




void moveRight() {
   cout << "Suck ma booal";
}

void printBoard() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         cout << "| " << board[i][j] << " |";
      }
      cout << endl;
   }
}
