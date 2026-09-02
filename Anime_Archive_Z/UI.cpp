#include "UI.h"
#include <iostream>
#include <sstream>
#include<string>

using namespace std;

void showMenu()
{
	cout << "           动漫收藏馆Z" << endl;
	cout << "1.动漫列表               2.动漫排行" << endl;
	cout << "3.动漫添加               4.动漫删除" << endl;
	cout << "5.手动备份               6.重置馆藏" << endl;
	cout << "———————————————————————————————————" << endl;
}

void handleChoice(AnimeStore& store, MenuChoice choice)
{
	switch (choice)
	{
	case MenuChoice::Exit:
		break;
	case MenuChoice::List:
		store.showAll();
		cin.get();
		clearScreen();
		break;
	case MenuChoice::Rank:
		store.showRank();
		cin.get();
		clearScreen();
		break;
	case MenuChoice::Add:
		store.add();
		cin.get();
		clearScreen();
		store.showAll();
		cin.get();
		clearScreen();
		break;
	case MenuChoice::Remove:
	{
		int index;
		while (true)
		{
			store.showSimple();
			cout << "------------------------" << endl;
			cout << "抹去：";
			string line;
			getline(cin, line);
			istringstream iss(line);
			if (!(iss >> index) || !(iss >> std::ws).eof())
			{
				cout << "无效输入，请重新输入" << endl;
				cin.get();
				clearScreen();
				continue;
			}

			if (index == 0)
			{
				clearScreen();
				return;
			}

			if (index >= 1 && index <= store.getCount())
			{
				store.remove(index - 1);
				cout << "已删除" << endl;

				cin.get();
				clearScreen();
			}
			else
			{
				cout << "编号无效，请重新输入" << endl;
				cin.get();
				clearScreen();
			}
		}
	}

	case MenuChoice::Backup:
		store.backup();
		clearScreen();
		break;
	case MenuChoice::Reset:
		cout << "重置仪式启动，备份模块运行（y/n）：";
		char confirm;
		cin >> confirm;
		cin.ignore();
		if (confirm == 'y' || confirm == 'Y')
		{
			store.backup();
			store.reset();
			cout << "馆藏已重置" << endl;
		}
		else
		{
			cout << "已取消" << endl;
		}
		cin.get();
		clearScreen();
		break;
	default:
		cout << "无效，重来" << endl;
		cin.get();
		clearScreen();
		break;
	}
}

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}