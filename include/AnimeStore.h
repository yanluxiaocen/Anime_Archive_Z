#pragma once
#include "Anime.h"
#include <string>
#include<vector>

class AnimeStore
{
private:
	std::vector<Anime> m_animes;
	std::string m_filename;

public:
	AnimeStore(const std::string& filename);
	int getCount() const;
	const Anime& getAt(int index) const;

	void add();
	void remove(int index);
	void reset();
	void showAll() const;
	void showSimple() const;
	void showRank() const;

	bool saveToFile() const;
	bool backup() const;
	void loadFromFile();
};
