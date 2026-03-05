
#include "PmergeMe.hpp"





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

	PmergeMeVector t = pv;
	t.printContainer("Before: ");
	pv.printContainer("Before: ");
	pv.sort();
	pv.printContainer("After: ");
	pv.printTime();
	//vector
	//deque
	//uniquement int 
	//print before
	//print after
	//time to process container 1
	//time to process container 2
	return (0);
}