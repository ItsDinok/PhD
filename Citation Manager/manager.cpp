#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <algorithm>
#include "include/userio.h"
#include "include/Citation.h"

void load_data(std::vector<Citation>& list)
{

}

bool is_json_real()
{
	return std::filesystem::exists("citation_data.json");
}

int main(int argc, char* argv[])
{
	std::vector<Citation> citation_list;

	// Handle loading or creating the data
	if (!is_json_real) std::ofstream("citation_data.json"); 
	load_data(citation_list);

	std::string input;
	while (true)
	{
		clear_screen();
		display_menu();
		std::getline(std::cin, input);

		switch(input[0])
		{
			case '1':
				// View all citations
				break;
			case '2':
				// Search citations
				break;
			case '3':
				// Add citations
				break;
			// Help
			case '4':
				clear_screen();
				display_help();
				std::getline(std::cin, input);
				break;
			// Exit
			case '5':
				clear_screen();
				std::cout << "Are you sure you want to exit: ";
				std::getline(std::cin, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input == "y" || input == "yes") return 0;
				break;
			default:
				clear_screen();
				std::cout << "Valid index not provided! Press ENTER to try again.";
				std::getline(std::cin, input);
				break;
		}
	}

	return 0;
}
