#include "Anime.h"
#include <iostream>

Anime::Anime(const std::string& name, const std::string& author, const std::string& description, float rate)
	: m_name(name), m_author(author), m_description(description), m_rate(rate)
{
	if (m_rate < 0.0f || m_rate > 10.0f)
		m_rate = 0.0f;
}

const std::string& Anime::getName() const
{
	return m_name;
}

const std::string& Anime::getAuthor() const
{
	return m_author;
}

const std::string& Anime::getDescription() const
{
	return m_description;
}

float Anime::getRate() const
{
	return m_rate;
}

void Anime::print() const
{
	using std::cout;
	using std::endl;
	cout << "【" << m_name << "】"
		<< " 作者：" << m_author
		<< " 评分：" << m_rate << endl;
	cout << "评论：" << m_description << endl;
	cout << "------------------------" << endl;
}

void Anime::printSimple() const
{
	std::cout << "【" << m_name << "】"
		<< " 作者：" << m_author
		<< " 评分：" << m_rate << std::endl;
}