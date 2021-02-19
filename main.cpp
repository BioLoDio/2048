#include <iostream>
#include "2048.h"
#include <time.h>
#include <conio.h>

using namespace std;

int board[4][4] = {0};

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
