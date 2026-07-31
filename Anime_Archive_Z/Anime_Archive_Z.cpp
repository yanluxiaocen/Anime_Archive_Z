#include "UI.h"
#include"AnimeStore.h"
#include <windows.h>
#include <iostream>
#include <string>

int main()
{
    system("chcp 65001 > nul");
    AnimeStore store("Anime.txt");
    Anime test("undertale", "tobyfox", "very good", 9.9);
    store.add(test);
    int choice;
    do
    {
        showMenu();
        std::cin >> choice;
        handleChoice(store, choice);
    } while (choice < 6 || choice > 0);

    getchar();
}
