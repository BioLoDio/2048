#include <iostream>
#include <time.h>
using namespace std;

class Game {
	Game() { // Costruttore che inizializza i valori dei blocchi
		srand(time(NULL));
		for (int i = 0; i < 4; ++i) 
			for (int j = 0; j < 4; ++j)
				board[i][j] = rand()%2;	// I blocchi all'inizio possono valere 1 oppure essere vuoti (valore 0)
	}
	public:
	// Tavola
		int board[4][4];
	
	
	// Struttura delle mosse
	char getMove() { 
		char = getch();
	}
	
	void Move (char move) {
		if ((move | 32) == 'w') { addUp(); }
		if ((move | 32) == 'a') { addDown(); }
		if ((move | 32) == 's') { addLeft(); }
		if ((move | 32) == 'd') { addRight(); }	
	}
	
	// TODO:
	// void addUp
	// void addDown
	// void addLeft
	// void addRight
};

int main()
{
   return 0;
}
