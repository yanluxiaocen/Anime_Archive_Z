#include "AnimeStore.h"
#include <string>
#include<iostream>
#include<fstream>
#include<algorithm>

AnimeStore::AnimeStore(const std::string& filename) {

}

void AnimeStore::loadFromFile() {
    std::ifstream fin("anime.txt");
    if (!fin.is_open()) return;

    std::string name, author, description;
    float rate;
    while (std::getline(fin, name) &&
        std::getline(fin, author) &&
        std::getline(fin, description) &&
        (fin >> rate)) {
        fin.ignore();
        m_animes.push_back(Anime(name, author, description, rate));
    }
}

void AnimeStore::saveToFile() const {
    std::ofstream fout("anime.txt");
    if (!fout.is_open()) return;
    for (const auto& anime : m_animes) {
        fout << anime.getName() << "\n"
            << anime.getAuthor() << "\n"
            << anime.getDescription() << "\n"
            << anime.getRate() << "\n";
    }
}
