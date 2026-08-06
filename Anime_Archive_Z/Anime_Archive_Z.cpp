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

    int choice;
    do
    {
        showMenu();
        std::cin >> choice;
        clearScreen();
        handleChoice(store, choice);
    } while (choice != 0);

    return 0;
}
