#include "Anime.h"
#include<iostream>

Anime::Anime(const std::string& name, const std::string& author, const std::string& description, float rate)
	: m_name(name), m_author(author), m_rate(rate), m_description(description) {
	if (m_rate < 0.0f || m_rate>10.0f)
		m_rate = 0.0f;
}

std::string Anime::getName() const {
	return m_name;
}

std::string Anime::getAuthor() const {
	return m_author;
}

std::string Anime::getDescription() const {
	return m_description;
}

float Anime::getRate() const {
	return m_rate;
}

void Anime::setRate(float rate) {
	if (rate >= 0.0f && rate <= 10.0f)
		m_rate = rate;
	else {
		std::cout << "啥杯，看不懂人话么？" << std::endl;
		m_rate = 0.0f;
	}
}

void Anime::print()const {
	std::cout << "作品：" << m_name
		<< " | 作者：" << m_author
		<< " | 评价：" << m_rate
		<< " | 介绍：" << m_description << std::endl;
}