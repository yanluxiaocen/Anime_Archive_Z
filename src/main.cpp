#include "UI.h"
#include "AnimeStore.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	AnimeStore store("Anime.txt");

	while (true)
	{
		showMenu();
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);
		int raw;
		if (!(iss >> raw) || !(iss >> std::ws).eof())
		{
			clearScreen();
			continue;
		}
		MenuChoice choice = static_cast<MenuChoice>(raw);
		clearScreen();
		handleChoice(store, choice);
		if (choice == MenuChoice::Exit)
			break;
	}

	store.saveToFile();
	return 0;
}