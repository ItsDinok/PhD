#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/json.hpp"

using json = nlohmann::json;

struct Citation
{
	Citation(const std::string& source);
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
