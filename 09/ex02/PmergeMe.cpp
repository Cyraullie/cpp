#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector() : _order(0)
{
	std::cout << GREEN << "Default PmergeMeVector constructor called" << RESET << std::endl;
}

PmergeMeVector::PmergeMeVector(char **args) : _order(1)
{
	std::cout << GREEN << "PmergeMeVector constructor with args called" << RESET << std::endl;
	this->_start = clock();
	for (int i = 1; args[i]; i++)
	{
		this->_data.push_back(std::atoi(args[i]));
	}
	this->printContainer("Before: ");
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& cpy): _data(cpy._data), _order(cpy._order), _start(cpy._start)
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
		this->_data = src._data;
		this->_order = src._order;
		this->_start = src._start;
	}
	return *this;
}

template <class T>
bool isSorted(T begin, T end)
{
	begin++;
	while (begin != end)
	{
		if (*(begin - 1) > *begin)
			return false;
		begin++;
	}
	return true;
}

void PmergeMeVector::swap(int i, int j)
{
	int swap = 0;

	swap = this->_data[i];
	this->_data[i] = this->_data[j];
	this->_data[j] = swap;
}

void PmergeMeVector::insertSort()
{
	std::cout << this->_order << std::endl;
	/*this->_data.erase (this->_data.begin(),this->_data.begin()+3);

	std::cout << "this->_data contains:";
	for (unsigned i=0; i<this->_data.size(); ++i)
		std::cout << ' ' << this->_data[i];
	std::cout << '\n';*/
}

void PmergeMeVector::pairSort()
{
	size_t i = 0;
	while (i + this->_order - 1 < this->_data.size())
	{
		int a = this->_data[i + this->_order / 2 - 1];
		int b = this->_data[i + this-> _order - 1];

		if (a > b)
		{
			unsigned int x = 0;
			while (x < this->_order / 2)
			{
				this->swap((i + this->_order / 2 - 1) - x, (i + this->_order - 1) - x);
				x++;
			}
		}
		i += _order;
	}

	this->printContainer("uwu: ");
	if ((size_t)(this->_order * 2 ) * 2 < this->_data.size())
	{
		this->_order *= 2;
		this->pairSort();
	}
	else 
		this->insertSort();

}

void PmergeMeVector::sort()
{
	this->pairSort();
	/*if (this->_data[0] > this->_data[1])
		this->swap(0, 1);*/
	//std::cout << isSorted(this->_data.begin(), this->_data.end()) << std::endl;

}

void printNum(const unsigned int it)
{
	std::cout << it << " ";
}

void PmergeMeVector::printContainer(std::string msg)
{
	std::cout << msg;
	std::for_each(this->_data.begin(), this->_data.end(), printNum);
	std::cout << std::endl;
}

void PmergeMeVector::printTime()
{
	std::cout << "Time to process a range of " << this->_data.size() << " elements with std::vector : " << float(clock() - this->_start) / CLOCKS_PER_SEC << " sec" << std::endl;
}