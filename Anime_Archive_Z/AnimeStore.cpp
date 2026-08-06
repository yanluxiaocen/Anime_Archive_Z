#include "AnimeStore.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>

AnimeStore::AnimeStore(const std::string &filename) : m_filename(filename)
{
    loadFromFile();
}

int AnimeStore::getCount() const
{
    return m_animes.size();
}

void AnimeStore::add()
{
    using std::cin;
    using std::cout;
    using std::getline;
    std::string name, author, description;
    float rate;
    cout << "名字：";
    getline(cin, name);
    cout << "作者：";
    getline(cin, author);
    cout << "评分：";
    cin >> rate;
    std::cin.ignore();
    cout << "评论：";
    getline(cin, description);

    m_animes.push_back(Anime(name, author, description, rate));
    cout << "成功\n";
}

void AnimeStore::remove(int index)
{
    m_animes.erase(m_animes.begin() + index);
}

void AnimeStore::showAll() const
{
    using std::cout;
    using std::endl;
    cout << "动漫列表" << endl
         << "------------------------" << endl;
    if (getCount())
    {
        int index = 1;
        for (const auto &anime : m_animes)
        {
            cout << index << ". ";
            index++;
            anime.print();
        }
    }
    else
        cout << "空" << endl
             << "------------------------" << endl;
}
void AnimeStore::showSimple() const
{
    using std::cout;
    using std::endl;
    if (getCount())
    {
        int index = 1;
        for (const auto &anime : m_animes)
        {
            cout << index << ". ";
            index++;
            anime.printSimple();
        }
    }
    else
        cout << "空" << endl;
}

void AnimeStore::showRank() const
{
    using std::cout;
    using std::endl;

    cout << "动漫排行" << endl
         << "------------------------" << endl;
    if (getCount())
    {
        auto sorted = m_animes;

        std::sort(sorted.begin(), sorted.end(), [](const Anime &a, const Anime &b)
                  { return a.getRate() > b.getRate(); });

        int index = 1;
        for (const auto &anime : sorted)
        {
            cout << index << ". ";
            index++;
            anime.print();
        }
    }
    else
        cout << "空" << endl
             << "------------------------" << endl;
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
    std::ifstream check(m_filename);
    if (check.is_open())
    {
        check.close();
        std::rename(m_filename.c_str(), (m_filename + ".bak").c_str());
    }

    std::ofstream fout(m_filename);
    if (!fout.is_open())
    {
        std::cerr << "错误：无法打开文件 " << m_filename << " 进行保存！" << std::endl;
        getchar();
        return;
    }

    for (const auto &anime : m_animes)
    {
        fout << anime.getName() << "\n"
             << anime.getAuthor() << "\n"
             << anime.getDescription() << "\n"
             << anime.getRate() << "\n";
    }
    std::cout << "保存成功";
    std::cin.ignore();
}

AnimeStore::~AnimeStore()
{
    saveToFile();
}