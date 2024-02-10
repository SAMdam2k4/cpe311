#ifndef _LUDO_H_
#define _LUDO_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define NUM_PLAYERS 4
#define NUM_HOUSES 4


enum Color {
	RED, YELLOW, GREEN, BLUE, NOCOLOR
};

struct House {
    Color color;
    int members;
    bool status;

    House(Color c = Color::RED, int m = 4, bool s = false) {
		color = c;
		members = m;
		status = s;
	}
};

struct Player {
    string name;
    House houses[2];
};

void configureGame(Player players[], int numPlayers);
void displayResults(Player players[], int numPlayers);

#endif /* _LUDO_H_ */