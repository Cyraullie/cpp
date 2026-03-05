#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector()
{

}

PmergeMeVector::PmergeMeVector(char **args)
{
	this->_start = clock();
	for (int i = 1; args[i]; i++)
	{
		this->_vec.push_back(std::atoi(args[i]));
	}
	this->printContainer("Before: ");
}
/*
PmergeMeVector::PmergeMeVector(const PmergeMeVector& cpy)
{

}*/

PmergeMeVector::~PmergeMeVector()
{

}
/*
PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& src)
{

}*/

void PmergeMeVector::sort()
{

}

void printNum(const unsigned int it)
{
	std::cout << it << " ";
}

void PmergeMeVector::printContainer(std::string msg)
{
	std::cout << msg;
	std::for_each(this->_vec.begin(), this->_vec.end(), printNum);
	std::cout << std::endl;
	std::cout << clock() - this->_start << std::endl;
}

void PmergeMeVector::printTime()
{
	std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector : " << clock() - this->_start << std::endl;
}