#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using Matrix = std::vector<std::vector<double>>;

void display_help()
{
	std::cout << "Help" << std::endl;
}

void load_dataset(Matrix& x_data, std::vector<int> y_labels, const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		std::cerr << "Error opening file.";
	}

	std::string line;
	bool is_first = true;
	while (std::getline(file, line))
	{
		if (is_first)
		{
			is_first = false;
			continue;
		}

		std::vector<double> to_add;
		std::string buffer = "";

		// Convert values to double
		for (size_t i = 0; i < line.size(); ++i)
		{
			if (line[i] == ',')
			{
				// TODO: Add error handling
				to_add.push_back(std::stod(buffer));
				buffer = "";
			}
			else buffer += line[i];

			if (i == line.size() - 1)
			{
				y_labels.push_back(std::stoi(buffer));
			}
		}
		x_data.push_back(to_add);
	}
}

int main(int argc, char* argv[]) 
{
	// State
	Matrix x_data;
	std::vector<int> y_labels;
	bool is_export = true;
	bool is_verbose = false;

	// Manage flags
	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]).length() <= 1) continue;

		switch (argv[i][1])
		{
			case 'h':
				display_help();
				return 0;
		
			case 'i':
				if (argc <= i + 1) 
				{
					std::cout << "Flag -i used but no path provided." << std::endl;
					return 1;
				}

				// FIXME: Naively assumes path length
				{
					std::string path = std::string(argv[++i]);
					std::cout << "Loading dataset..." << std::endl;
					load_dataset(x_data, y_labels, path);
					std::cout << "Dataset loaded!" << std::endl;
				}
				break;
		
			case 'e':
				is_export = false;
				break;

			case 'v':
				is_verbose = true;
				break;
		}
	}
	
	if (!is_export && !is_verbose) std::cout << "Export and verbose are disabled. Consider enabling one." << std::endl;

	return 0;
}
