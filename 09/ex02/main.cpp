#include "PmergeMe.hpp"

//TODO ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

int checkArgs(char **args)
{
	for (int i = 1; args[i]; i++)
	{
		if (std::atoi(args[i]) == 0)
		{
			if (args[i][0] != '0')
				return 0;
		}
		if (std::atoi(args[i]) < 0)
			return 0;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Error: not enough arguments" << RESET << std::endl; 
		return (1);
	}
	if (!checkArgs(av))
	{
		std::cout << RED << "Error" << RESET << std::endl;
		return (1);
	}
	PmergeMeVector pv(av);
	PmergeMeDeque pdq(av);

	pv.sort();
	pdq.sort();
	return (0);
}