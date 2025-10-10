#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Citation
{
	Citation(const std::string& json);
	void display_snapshot();
	void display_information();

	std::vector<std::string> Authors;
	std::string Title;
	std::string Journal;
	std::string Year;
	std::string Description;
	std::vector<std::string> Tags;

	std::string Bibtex;
	std::string Citation_Name;
};
