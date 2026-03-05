#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector()
{
	std::cout << GREEN << "Default PmergeMeVector constructor called" << RESET << std::endl;
}

PmergeMeVector::PmergeMeVector(char **args)
{
	std::cout << GREEN << "PmergeMeVector constructor with args called" << RESET << std::endl;
	this->_start = clock();
	for (int i = 1; args[i]; i++)
	{
		this->_vec.push_back(std::atoi(args[i]));
	}
	this->printContainer("Before: ");
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& cpy): _vec(cpy._vec), _start(cpy._start)
{
	std::cout << LIGHT_GREEN << "PmergeMeVector copy constructor called" << RESET << std::endl;
	
}

PmergeMeVector::~PmergeMeVector()
{
	std::cout << RED << "PmergeMeVector destructor called" << RESET << std::endl;

}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& src)
{
	std::cout << LIGHT_GREEN << "PmergeMeVector assignment operator called" << RESET << std::endl;
	if (this != &src) {
		//this->_name = src._name;
		for (std::vector<unsigned int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
		{
			std::cout << *it << " ";
		}
	}
	return *this;
}

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