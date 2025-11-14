#include "RPN.hpp"

// Default constructor
RPN::RPN()
{
	std::cout << GREEN << "Default RPN constructor called" << RESET << std::endl;
}

// Copy constructor
RPN::RPN(const RPN& cpy)
{
	(void)cpy;
	//std::cout << LIGHT_GREEN << "RPN copy constructor called for "<< RESET << std::endl;
}

// Destructor
RPN::~RPN()
{
	std::cout << RED << "RPN destructor called for " << RESET << std::endl;
};

// Copy assignment
RPN& RPN::operator=(const RPN& src)
{
	std::cout << LIGHT_GREEN << "RPN assignment operator called" << RESET << std::endl;
	if (this != &src) {
		//this->_name = src._name;
	}
	return *this;
}

void RPN::pushData(float n)
{
	this->_lst.push_back(n);
}

void RPN::listData()
{
	std::list<float>::iterator it;

	for (it = this->_lst.begin(); it != this->_lst.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

void RPN::clearList(int len)
{
	for (int i = 0; i < len; i++)
		this->_lst.pop_back();
}

void RPN::addition()
{
	float res = 0;
	float n1, n2;
	std::list<float>::iterator it = --this->_lst.end();

	n2 = *it;
	--it;

	n1 = *it;
	res = n1 + n2;

	this->clearList(2);
	this->pushData(res);
}

void RPN::substraction()
{
	float res = 0;
	float n1, n2;
	std::list<float>::iterator it = --this->_lst.end();

	n2 = *it;
	--it;
	
	n1 = *it;
	res = n1 - n2;
	
	this->clearList(2);
	this->pushData(res);
}

void RPN::division()
{
	float res = 0;
	float n1, n2;
	std::list<float>::iterator it = --this->_lst.end();

	n2 = *it;
	--it;
	
	n1 = *it;
	res = n1 / n2;

	this->clearList(2);
	this->pushData(res);
}

void RPN::multiple()
{
	float res = 0;
	float n1, n2;
	std::list<float>::iterator it = --this->_lst.end();

	n2 = *it;
	--it;
	
	n1 = *it;
	res = n1 * n2;

	this->clearList(2);
	this->pushData(res);
}

int RPN::countListContent()
{
	return (this->_lst.size());
}