#include "AnimeStore.h"
#include <iostream>
#include <fstream>
#include <algorithm>

AnimeStore::AnimeStore(const std::string &filename) : m_filename(filename)
{
    loadFromFile();
}

void AnimeStore::add()
{
    using std::cin;
    using std::cout;
    using std::getline;
    std::string name, author, description;
    float rate;
    getchar();
    cout << "名字：\n";
    getline(cin, name);
    cout << "作者：\n";
    getline(cin, author);
    cout << "评分：\n";
    cin >> rate;
    getchar();
    cout << "评论：\n";
    getline(cin, description);

    m_animes.push_back(Anime(name, author, description, rate));
    cout << "成功\n";
}

bool AnimeStore::remove(int index)
{
    if (index < 0 || index > static_cast<int>(m_animes.size()))
        return false;

    m_animes.erase(m_animes.begin() + index);
    return true;
}

void AnimeStore::showAll() const
{
    using std::cout;
    using std::endl;
    for (const auto &anime : m_animes)
    {
        anime.print();
    }
}

void AnimeStore::showRank() const
{
    using std::cout;
    using std::endl;

    auto sorted = m_animes;

    std::sort(sorted.begin(), sorted.end(), [](const Anime &a, const Anime &b)
              { return a.getRate() > b.getRate(); });

    for (const auto &anime : sorted)
        anime.print();
}

void AnimeStore::loadFromFile()
{
    std::ifstream fin(m_filename);
    if (!fin.is_open())
        return;

    std::string name, author, description;
    float rate;
    while (std::getline(fin, name) &&
           std::getline(fin, author) &&
           std::getline(fin, description) &&
           (fin >> rate))
    {
        fin.ignore();
        m_animes.push_back(Anime(name, author, description, rate));
    }
}

void AnimeStore::saveToFile() const
{
    std::ofstream fout(m_filename);
    if (!fout.is_open())
        return;
    for (const auto &anime : m_animes)
    {
        fout << anime.getName() << "\n"
             << anime.getAuthor() << "\n"
             << anime.getDescription() << "\n"
             << anime.getRate() << "\n";
    }
}

AnimeStore::~AnimeStore()
{
    saveToFile();
}