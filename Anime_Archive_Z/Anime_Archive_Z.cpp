#include "UI.h"
#include "AnimeStore.h"
#include <windows.h>
#include <iostream>
#include <string>

int main()
{
    system("chcp 65001 > nul");

    AnimeStore store("Anime.txt");

    int choice;
    do
    {
        showMenu();
        std::cin >> choice;
        handleChoice(store, choice);
        getchar();
    } while (choice < 6 || choice > 0);

    getchar();
}
