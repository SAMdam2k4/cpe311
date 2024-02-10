#include "ludo.h"

void configureGame(Player players[], int numPlayers) {
    string colorString;
    Color chosenColor = Color::NOCOLOR;
    int assignedHouses[NUM_HOUSES], assignedHousesCount = 0;
	bool exists = false;

    cout << "Configuring the game...\n";

    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter name for Player " << i+1 << ": ";
        cin >> players[i].name;
		
		for (int j = 0; j < (numPlayers == 4 ? 1 : 2); j++) {
			do {
				chosenColor = Color::NOCOLOR;
				exists = false;
				cout << "Choose a color (Red, Yellow, Green, Blue) for " << players[i].name << ": ";
				cin >> colorString;

				if (colorString == "Red") {
					chosenColor = Color::RED;
					exists = true;
				} else if (colorString == "Yellow") {
					chosenColor = Color::YELLOW;
					exists = true;
				} else if (colorString == "Green") {
					chosenColor = Color::GREEN;
					exists = true;
				} else if (colorString == "Blue") {
					chosenColor = Color::BLUE;
					exists = true;
				} else {
					cout << "Invalid color. Please choose again.\n";
				}

				if (chosenColor != Color::NOCOLOR)
				{
					for (int k = 0; k < assignedHousesCount; k++)
					{
						if (assignedHouses[k] == chosenColor)
						{
							exists = false;
							cout << "House already chosen. Please choose again.\n";
						}
					}
				}

			} while ((chosenColor < Color::RED || chosenColor > Color::BLUE ) || !exists);

            players[i].houses[j] = House(chosenColor, 4, true);
			assignedHouses[assignedHousesCount] = chosenColor;
            assignedHousesCount++;
        }
    }

    cout << "Game configuration complete.\n";
}

void displayResults(Player players[], int numPlayers) {
	string HouseNames[] = {"Red", "Yellow", "Green", "Blue"};

    cout << "\nResults:\n";
    cout << "--------------------------------------------------\n";
    cout << "| " << setw(10) << "Name" << " | " << setw(10) << "House" << " | " << setw(10) << "Member" << " |\n";
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 2; j++) {
			if (players[i].houses[j].status) {
				cout << "| " << setw(10) << players[i].name << " | " << setw(10) << HouseNames[(int)players[i].houses[j].color] << " | " << setw(10) << players[i].houses[j].members << " |\n";
			}
        }
    }

    cout << "--------------------------------------------------\n";
}