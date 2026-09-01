#pragma once
#include "AnimeStore.h"

enum class MenuChoice {
	Exit = 0,
	List = 1,
	Rank = 2,
	Add = 3,
	Remove = 4,
	Backup = 5,
	Reset = 6
};

void showMenu();
void handleChoice(AnimeStore& store, MenuChoice choice);
void clearScreen();