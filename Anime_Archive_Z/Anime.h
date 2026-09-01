#pragma once
#include<string>

class Anime
{
private:
	std::string m_name;
	std::string m_author;
	std::string m_description;
	float m_rate;
public:
	Anime(const std::string& name, const std::string& author, const std::string& description, float rate);
	const std::string& getName() const;
	const std::string& getAuthor() const;
	const std::string& getDescription() const;
	float getRate() const;
	void setRate(float rate);
	void print() const;
	void printSimple() const;
};
