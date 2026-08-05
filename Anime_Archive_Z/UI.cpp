#include "UI.h"
#include <iostream>

using namespace std;

void showMenu()
{
    cout << "           动漫收藏馆Z" << endl;
    cout << "1.动漫列表               2.动漫排行" << endl;
    cout << "3.动漫添加               4.动漫删除" << endl;
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
    case 3:
        store.add();
        break;
    case 4:
        int index;
        cin >> index;
        store.remove(index - 1);
    default:
        cout << "你吗";
    }
}