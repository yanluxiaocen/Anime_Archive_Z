#include "UI.h"
#include <iostream>

using namespace std;

void showMenu()
{
    cout << "           番剧收藏馆Z" << endl;
    cout << "1.番剧列表               2.番剧排行" << endl;
}

void handleChoice(AnimeStore &store, int choice)
{
    switch (choice)
    {
    case 1:
        store.showAll();
        break;
    case 2:
        store.showRank();
        break;
    default:
        cout << "你吗";
    }
}