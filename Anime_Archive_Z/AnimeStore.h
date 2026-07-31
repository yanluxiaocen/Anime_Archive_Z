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
	AnimeStore(const std::string &filename);
	~AnimeStore();

	void add(const Anime &anime);
	bool remove(int index);
	void showAll() const;
	void showRank() const;

	void saveToFile() const;
	void loadFromFile();
};
