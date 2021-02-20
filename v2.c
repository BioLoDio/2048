#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

int board[4][4] = {0};
int *empty_space[16] = {NULL};
int n_empty_space = 16;

//* MANIPULAZIONE POSIZIONI
int findPos(); //^ Cerca all'interno dell'Array "empty_space" una posizione con valore 0 , restituisce l'indice
void popPos(int *position);  //^ Rimuove dall'Array "empty_space" una data posizione 
void pushPos(int *position); //^ Inserisce nell'Array "empty_space" una data posizione
void getPos();
void updatePos(); //^ Aggiorna tutte le posizioni 

//* MOSSE
void moveUp();
void moveDown();
void moveLeft();
void moveRight ();
int getMove();

//* INTERFACCIA
void printBoard();
void printStats();


//* GESTIONE PROGRAMMA
void initializeGame();
int noMove();


int main()
{
   initializeGame();
   while (1) {
      printBoard();
      getMove();
      system("cls");
      getPos();

      if (noMove && !getMove) { break; }
   }
   
   puts("\nGame Over!");
   return 0;
}


//* MANIPULAZIONE POSIZIONI
int findPos() {
   srand(time(NULL));
   if (n_empty_space == 0) { return -1; }

   int position = rand()%n_empty_space;
   return position;
}

void popPos(int *position) {
   int i;
   for (i = 0; empty_space[i] != position && i < n_empty_space; ++i) {}

   if (i < n_empty_space) { 
      --n_empty_space;    //^ Decremento il numero di posizioni
      for (i ; i < n_empty_space; ++i) {
         empty_space[i] = empty_space[i+1];  //^ Shifting dell'array eliminando la posizione inserita
      }
   }
   else { return; }
   empty_space[i+1] = NULL;
}


void pushPos(int *position) {
   if (n_empty_space = 16) { return; }
   empty_space[++n_empty_space] = position;
   *position = 2;
}

void getPos() {
   int *position = empty_space[findPos()];
   *position = 2;
}

void updatePos() {
   //* Azzero l'Array
   int i, j;
   for (i = 0; i < 16; ++i) { empty_space[i] = NULL; }

   //* Aggiorno l'Array
   int k = 0;
   for (i = 0; i < 4; ++i) {
      for (j = 0; j < 4; ++j) {
         if (board[i][j] == 0) {
            empty_space[k++] = &board[i][j];
         }
      }
   }
   //* Azzero gli elementi inesistenti
   for (i = k; i < n_empty_space; ++i) { empty_space[i] = NULL; }
   n_empty_space = k;
}

void initializeGame() {
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
   *position = 2;

   popPos(position);
   getPos();
   pushPos(position);
}


//* MOSSE
void moveUp() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 4; ++j) {
         for (int k = j; k > 0; k--) {
            //* SPAZIO LIBERO
            if (board[k - 1][i] == 0) {
               board[k - 1][i] = board[k][i]; //* Sposta elemento attuale nello posizione soprastante 
               board[k][i] = 0;               //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            }

            //* NUMERI UGUALI
            else if ( board[k - 1][i] & board[k][i] ) {
                  board[k - 1][i] *= 2;       //* Somma all'elemento sovrastante all'elemento di riferiemnto 
                  board[k][i] = 0;            //* Libera la posizione dove l'elemento era contenuto
                  popPos(&board[k][i]);
            }

            //* NUMERI DIVERSI
            else { break; }
         }
      }
   }

   updatePos();
}

void moveDown() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 2; j >= 0; --j) {
         for (int k = j; k < 3; k++) {
            //* SPAZIO LIBERO
            if (board[k + 1][i] == 0) {
               board[k + 1][i] = board[k][i]; //* Sposta elemento attuale nello posizione sottostante 
               board[k][i] = 0;               //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            }

            //* NUMERI UGUALI
            else if ( board[k + 1][i] & board[k][i] ) {
               board[k + 1][i] *= 2;         //* Somma all'elemento sottostante all'elemento di riferiemnto 
               board[k][i] = 0;              //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            } 

            //* NUMERI DIVERSI
            else { break; }
         }
      }
   }
   updatePos();
}

void moveLeft() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 4; ++j) {
         for (int k = j; k > 0; k--) {
            //* SPAZIO LIBERO
            if (board[i][k-1] == 0) {
               board[i][k-1] = board[i][k]; //* Sposta elemento attuale nello posizione sottostante 
               board[i][k] = 0;             //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            }

            //* NUMERI UGUALI
            else if ( board[i][k - 1] & board[i][k] ) {
               board[i][k-1] *= 2;          //* Somma all'elemento sottostante all'elemento di riferiemnto 
               board[i][k] = 0;             //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            } 

            //* NUMERI  DIVERSI
            else { break; }
         } 
      }
   }
   updatePos();
}

void moveRight() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 2; j >= 0; --j) {
         for (int k = j; k < 3; k++) {
            //* SPAZIO LIBERO
            if (board[i][k+1] == 0) {
               board[i][k+1] = board[i][k];  //* Sposta elemento attuale nello posizione sottostante
               board[i][k] = 0;              //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            }

            //* NUMERI UGUALI
            else if ( board[i][k + 1] & board[i][k] ) {
               board[i][k + 1] *= 2;         //* Somma all'elemento sottostante all'elemento di riferiemnto 
               board[i][k] = 0;              //* Libera la posizione dove l'elemento era contenuto
               popPos(&board[k][i]);
            } 

            //* NUMERI  DIVERSI
            else { break; }
         }
      }
   }
   updatePos();
}


//* INTERAZIONE UTENTE
int getMove() {
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


//* INTERFACCIA
void printBoard() {
   puts("\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         printf("|\t%d\t|", board[i][j]);
      }
      puts("\n");
   }
}


//* GESTIONE PROGRAMMA
int noMove() {
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++i) {
         if (board[i][j] == board[i][j+1]) { return 0; }
         if (board[j][i] == board[j+1][i]) { return 0; }
      }
   }
   return 1;
}
