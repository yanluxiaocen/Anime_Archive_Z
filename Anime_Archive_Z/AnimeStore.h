#pragma once
#include "Anime.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

class AnimeStore
{
private:
	std::vector<Anime> m_animes;
	std::string m_filename;

public:
	AnimeStore(const std::string& filename);
	int getCount() const;

	void add();
	void remove(int index);
	void showAll() const;
	void showSimple() const;
	void showRank() const;

	bool saveToFile() const;
	bool backup() const;
	void loadFromFile();
};
