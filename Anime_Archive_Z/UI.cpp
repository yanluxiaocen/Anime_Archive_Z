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
    cin.ignore();
    switch (choice)
    {
    case 0:
        break;
    case 1:
        store.showAll();
        cin.get();
        clearScreen();
        break;
    case 2:
        store.showRank();
        cin.get();
        clearScreen();
        break;
    case 3:
        store.add();
        cin.get();
        clearScreen();
        store.showAll();
        cin.get();
        clearScreen();
        break;
    case 4:
    {
        int index;
        while (true)
        {
            store.showSimple();
            cout << "------------------------" << endl;
            cout << "抹去：";
            cin >> index;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "无效输入，请重新输入" << endl;
                cin.get();
                clearScreen();
                continue;
            }

            if (index == 0){
                clearScreen();
                return;
            }
                
            cin.ignore();
            if (index >= 1 && index <= store.getCount())
            {
                store.remove(index - 1);
                clearScreen();
            }
            else
            {
                cout << "编号无效，请重新输入" << endl;
                cin.get();
                clearScreen();
            }
        }
        clearScreen();
        break;
    }

    default:
        cout << "啥杯";
        clearScreen();
        break;
        std::cin.ignore();
    }
}

void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}
