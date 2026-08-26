#include "UI.h"
#include "AnimeStore.h"
#include <windows.h>
#include <iostream>
#include <string>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	AnimeStore store("Anime.txt");

	int choice = 0;
	while (true)
	{
		showMenu();
		if (!(std::cin >> choice))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			clearScreen();
			continue;
		}
		clearScreen();
		handleChoice(store, choice);
		if (choice == 0)
			break;
	}

	store.saveToFile();
	return 0;
}