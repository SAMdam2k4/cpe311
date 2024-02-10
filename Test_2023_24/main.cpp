#include "ludo.h"

int main() {
    Player players[NUM_PLAYERS];
	int numPlayers;

	do {
		cout << "Enter the number of players (2 or 4): ";
		cin >> numPlayers;
	} while (numPlayers != 2 && numPlayers != 4);

    configureGame(players, numPlayers);

    displayResults(players, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 2; j++) {
            players[i].houses[j].members -= (i + 1);
        }
    }

    cout << "\nAfter deducting members:\n";
    displayResults(players, numPlayers);
	
	system("pause");

    return 0;
}