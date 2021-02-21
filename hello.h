
#ifndef HELLO_H_
#define HELLO_H_
#include <iostream>
#include <time.h>
#include <conio.h>

int board[4][4] = {0};

void random();
void startBoard();

void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void random() {
	int *posizioniZero[16] = {0};
	int index = 0;
	int random;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j< 4; j++){
			if(board[i][j] == 0){
			
			posizioniZero[index] = &board[i][j];
			index++;
			}
		}
	}
	random = rand()%index;
	*posizioniZero[random] = 2;
	
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

int userMove() {
   char user_move = getch();
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
      case 'P': return 1;
   default:
   break;
   }
   return 0;
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

   for (int i = 0; i < 4; ++i) {
      for (int j = 2; j >= 0; --j) {
         for (int k = j; k < 3; k++) {
            if (board[i][k+1] == 0) {
               board[i][k+1] = board[i][k]; //spostamento elemento
               board[i][k] = 0;
            }

            else if ( board[i][k + 1] & board[i][k] ) {
               board[i][k + 1] *= 2;
               board[i][k] = 0;
            } 

            else { break; }
         } //* Fine Ciclo
      }
   }

}

void printBoard() {
   system("cls");
   puts("\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         printf("| %d |", board[i][j]);
      }
      puts("\n");
   }
}

int gameOver() {

   // Diagonali
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++i) {
         if (board[i][j] == board[i][j+1]) { return 0; }
         if (board[j][i] == board[j+1][i]) { return 0; }
      }
   }
   return 1;
}

#endif
