#include <iostream>
#include <fstream>
#include <string>

int	ft_replaceInFile(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		content;
	std::string		line;
	size_t			pos;

	// Open input file
	infile.open(filename.c_str());
	if (infile.fail())
	{
		std::cout << "Error: cannot open file '" << filename << "'" << std::endl;
		return (1);
	}

	// Read entire file
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();

	// Open output file
	outfile.open((filename + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: cannot create output file" << std::endl;
		return (1);
	}

	// Replace all occurrences
	pos = 0;
	while (pos < content.size())
	{
		size_t found = content.find(s1, pos);
		if (found != std::string::npos && found == pos)
		{
			outfile << s2;
			pos += s1.size();
		}
		else
		{
			outfile << content[pos];
			pos++;
		}
	}

	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// Check for empty search string
	if (s1.empty())
	{
		std::cout << "Error: search string (s1) cannot be empty" << std::endl;
		return (1);
	}

	return (ft_replaceInFile(filename, s1, s2));
}
