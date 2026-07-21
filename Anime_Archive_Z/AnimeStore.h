#pragma once
#include<vector>
#include<string>
#include"Anime.h"

class AnimeStore
{
private:
	std::vector<Anime> m_animes;
	std::string m_filename;
public:
	AnimeStore(const std::string& filename);

	void add(const Anime& anime);
	bool remove(int index);
	void showAll() const;
	void showRank() const;

	void saveToFile() const;
	void loadFromFile();
};
