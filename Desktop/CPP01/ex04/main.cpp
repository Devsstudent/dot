# include <iostream>
# include <string>
# include <fstream>

void	write_to_file(std::ofstream &outfile, std::string line, std::string s2, std::string s1)
{
	std::size_t	pos;
	int			index;
	pos = 0;
	index = 0;

	while (pos != std::string::npos)
	{
		pos = line.find(s1, index);
		if (pos < std::string::npos)
		{
			outfile << line.substr(index, pos - index).append(s2);
			index = pos + s1.size();
		}
	}
	if ((size_t) index < line.size())
		outfile << line.substr(index, line.size() - index);
	outfile << std::endl;
}

int	main(int ac, char **av)
{
	std::string	s1;
	std::string	s2;
	std::string	buff_line;
	std::string	filename;

	if (ac < 4 || ac > 4)
	{
		std::cerr << "Please enter as follow : <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	filename = av[1];
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open(av[1]);
	if (infile.bad())
	{
		std::cerr << "Failed opening " << filename << std::endl;
		return (2);
	}
	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Empty file" << std::endl;
		return (3);
	}
// check empty
	filename.append(".replace");
	outfile.open(filename);
	if (outfile.bad())
	{
		std::cerr << "Failed opening " << filename << std::endl;
		return (3);
	}
	while (getline(infile, buff_line))
	{
		write_to_file(outfile, buff_line, s2, s1);
	}
	infile.close();
	outfile.close();
}
