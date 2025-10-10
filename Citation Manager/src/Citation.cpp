#include "../include/Citation.h"

Citation::Citation()
{
	// TODO: consider using a json parser for this
	// The opening bracket is not included

}

std::string join_vector(const std::vector<std::string>& vec)
{
	std::string to_return = "";

	for (int i = 0; i < vec.size(); ++i)
	{
		to_return += vec[i] + ", ";
	}

	return to_return;
}

void Citation::display_snapshot()
{
	// This displays a small amount of information, enough to tell the user what they are looking at
	// Title
	std::cout << "Title: "; std::cout.write(Title.c_str(), 30);
	
	// Author
	if (Authors.size() >= 3) std::cout << "Authors: " << Authors[0] << " et al." << std::endl;
	else 
	{
		std::string author_string = join_vector(Authors);
		std::cout << "Authors: "; std::cout.write(author_string.c_str(), 30);
	}

	// Journal, year
	std::cout << "Journal: " << Journal << ", Year: " << Year << std::endl;

	// Tags
	std::string tag_string = join_vector(Tags);
	std::cout << "Tags: "; std::cout.write(tag_string.c_str(), 30);
}
