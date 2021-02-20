#include "hello.h"

using namespace std;

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
