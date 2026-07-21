#pragma once
#include<iostream>
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
	std::string getName() const;
	std::string getAuthor() const;
	std::string getDescription() const;
	float getRate() const;
	void setRate(float rate);
	void print() const;
};

