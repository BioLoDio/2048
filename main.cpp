#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int board[4][4] = {0};

void random(); // Assegna il valore alle celle vuote
void startBoard(); // Assegna due celle randomiche 

int userMove();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void printBoard();
int gameOver();

int main() {

   //Inizializza la matrice
   startBoard();
   
   do { 
      printBoard();
      puts("\nInserire le azioni: W -> Up\tS -> Down\tA -> Left\tD -> Right\n(Premi P per uscire)\n\n");
      userMove();
      random();
   } while (!gameOver() && !userMove());

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
         cout << "| " << board[i][j] << " |";
      }
      cout << endl;
   }
}

int gameOver() {

   // Diagonali
   if (board[0][0] == board[1][0] || board[0][0] == board[0][1]) { return 0; }
   if (board[0][3] == board[0][2] || board[0][3] == board[1][3]) { return 0; }
   if (board[3][0] == board[2][0] || board[3][0] == board[3][1]) { return 0; }
   if (board[3][3] == board[2][3] || board[3][3] == board[3][2]) { return 0; }

   if (board[0][1] == board[0][2]) { return 0; }
   if (board[1][0] == board[2][0]) { return 0; }
   if (board[3][1] == board[3][2]) { return 0; }
   if (board[1][3] == board[2][3]) { return 0; }

   for (int i = 1; i < 3; ++i) {
      for (int j = 1; j < 3; ++j) {
         if (board[i][j] == board[i-1][j] ||
             board[i][j] == board[i+1][j] ||
             board[i][j] == board[i][j-1] ||
             board[i][j] == board[i][j+1]
             ) { return 0; }
      }
   }

   return 1;
}
