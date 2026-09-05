#include "AnimeStore.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

AnimeStore::AnimeStore(const std::string& filename) : m_filename(filename)
{
	loadFromFile();
}

int AnimeStore::getCount() const
{
	return m_animes.size();
}

const Anime& AnimeStore::getAt(int index) const {
	return m_animes.at(static_cast<size_t>(index));
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
	while (true)
	{
		cout << "评分：";
		std::string line;
		std::getline(cin, line);
		std::istringstream iss(line);
		if (!(iss >> rate) || !(iss >> std::ws).eof())
		{
			cout << "无效，重来" << std::endl;
			continue;
		}
		if (rate >= 0.0f && rate <= 10.0f)
			break;
		cout << "范围错误，重来" << std::endl;
	}
	cout << "评论：";
	getline(cin, description);

	m_animes.push_back(Anime(name, author, description, rate));
	cout << "成功\n";
}

void AnimeStore::remove(int index)
{
	m_animes.erase(m_animes.begin() + index);
}

void AnimeStore::reset()
{
	m_animes.clear();
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
		for (const auto& anime : m_animes)
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
		for (const auto& anime : m_animes)
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

		std::sort(sorted.begin(), sorted.end(), [](const Anime& a, const Anime& b)
			{ return a.getRate() > b.getRate(); });

		int index = 1;
		for (const auto& anime : sorted)
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

bool AnimeStore::saveToFile() const
{
	std::ofstream fout(m_filename);
	if (!fout.is_open())
		return false;

	for (const auto& anime : m_animes)
	{
		fout << anime.getName() << "\n"
			<< anime.getAuthor() << "\n"
			<< anime.getDescription() << "\n"
			<< anime.getRate() << "\n";
	}
	return fout.good();
}

bool AnimeStore::backup() const
{
	std::ifstream src(m_filename, std::ios::binary); // 以二进制模式打开
	if (!src.is_open())
		return false;

	std::ofstream dst(m_filename + ".bak", std::ios::binary);
	if (!dst.is_open())
		return false;

	dst << src.rdbuf();
	return dst.good();
}