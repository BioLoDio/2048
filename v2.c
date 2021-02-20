#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

int board[4][4] = {0};
int *empty_space[16] = {NULL};
int n_empty_space = 16;

int findPos(); //^ Cerca all'interno dell'Array "empty_space" una posizione con valore 0 , restituisce l'indice
void popPos(int *position);  //^ Rimuove dall'Array "empty_space" una data posizione 
void pushPos(int *position); //^ Inserisce nell'Array "empty_space" una data posizione
void updatePos(); //^ Aggiorna tutte le posizioni 

void initializeBoard();

/* 
 * TODO:
 * Proceduce Move() -> Andranno collegate all'Array "empty_space" con relative funzioni associate
 * Input Utente
 * CLI 
*/


int main()
{
   return 0;
}



void popPos(int *position) {
   int i;
   for (i = 0; empty_space[i] != position && i < n_empty_space; ++i) {
      /* 
      * Controlla se gli elementi dell'array "empty_space[i]" siano diversi,
      * se la procedura possa essere eseguita 
      * 
      * Se si trova l'elemento, la variabile contatore "i" indica l'indice dell'array
      * in cui l'indirizzo si trova
      * 
      * Se non si trova, la variabile contatore "i" raggiunge il numero di posizioni libere
      * in tal caso, non essendovi corrispondenza, la procedura non viene eseguita
      */
   }

   if (i < n_empty_space) { 
      --n_empty_space;    //^ Decremento il numero di posizioni
      for (i ; i < n_empty_space; ++i) {
         empty_space[i] = empty_space[i+1];  //^ Shifting dell'array eliminando la posizione inserita
      }
   }
   else { return; }
   empty_space[i+1] = NULL;
}

int findPos() {
   srand(time(NULL));
   if (n_empty_space == 0) { return -1; }

   int position = rand()%n_empty_space;
   return position;
}

void pushPos(int *position) {
   if (n_empty_space = 16) { return; }
   empty_space[n_empty_space + 1] = position;
}

void updatePos() {
   //* Azzero l'Array
   int i, j;
   for (i = 0; i < 16; ++i) { empty_space[i] = NULL; }

   //* Aggiorno l'Array
   int k = -1;
   for (i = 0; i < 4; ++i) {
      for (j = 0; j < 4; ++j) {
         if (board[i][j] == 0) {
            empty_space[++k] = &board[i][j];
         }
      }
   }
   n_empty_space = k;
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
