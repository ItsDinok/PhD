#include "../include/userio.h"

void display_menu()
{
	std::cout << "Enter option: \n" << std::endl;
	std::cout << "(1) View all citations" << std::endl;
	std::cout << "(2) Search citations" << std::endl;
	std::cout << "(3) Add citations" << std::endl;
	std::cout << "(4) View help" << std::endl;
	std::cout << "(5) Exit" << std::endl;
	std::cout << "Enter index: ";
}

void letter_head()
{
	std::cout << "Citation Locker v0.0" << std::endl;
	std::cout << "ItsDinok, 2025" << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void clear_screen()
{
	// This didn't need its own function but preprocessor macros are clunky and hard to read
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	
	letter_head();
}

void display_help()
{
	std::cout << "This program is designed to keep track of citations in a searchable and approachable way. The key features and uses are outlined below." << std::endl;

	// View citations
	std::cout << "------------" << std::endl;
	std::cout << "View citations\n" << std::endl;
	std::cout << "This is where citations can be viewed and edited. This will do it as a large list, not as any kind of structured data. Citations are loaded in the order they exist within the json." << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "\n\nPress ENTER to return to main menu." << std::endl;
}
