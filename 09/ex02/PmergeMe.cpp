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

void PmergeMeVector::jacobSort(vi *main, vi *pend, vi *trash)
{
	std::cout << "main : ";
	for(size_t i = 0; i < main->size(); i++)
		std::cout << (*main)[i] << " ";
	std::cout << std::endl;
	std::cout << "pend : ";
	for(size_t i = 0; i < pend->size(); i++)
		std::cout << (*pend)[i] << " ";
	std::cout << std::endl;
	std::cout << "trash : ";
	for(size_t i = 0; i < trash->size(); i++)
		std::cout << (*trash)[i] << " ";

	std::cout << std::endl;


	size_t mid = main->size() / this->_order / 2;
	size_t mainPos = mid * this->_order + this->_order - 1;


	for(size_t j = pend->size() / this->_order; j > 0; j--)
	{

		vit it = main->begin();
		for (size_t i = 0; i < mainPos; i++)
			it++;
		size_t pendPos = (j - 1) * this->_order + this->_order - 1;
		std::cout << mid << " " << (j - 1)  << std::endl;
		std::cout << mainPos << " " << *it << " " << (*pend)[pendPos]<< std::endl;
		if (*it < (*pend)[pendPos])
		{
			std::cout << mainPos << " " << *it << " " << (*pend)[pendPos]<< std::endl;
			it++;

			std::cout << "pend : ";
			for(size_t i = 0; i < pend->size(); i++)
				std::cout << (*pend)[i] << " ";
			std::cout << std::endl;
			vit pit = pend->end();
			pit--;
			std::cout << "test " << pendPos << " " << pendPos - this->_order << std::endl;
			//TODO le dernier le la liste marche pas parce que size_t est pas negatrif
			for(size_t x = pendPos; x > pendPos - this->_order || x > 0; x--)
			{
				std::cout << "caca : "<< x << " " << pendPos << " " << pendPos - this->_order << " " << std::endl;
				main->insert(it, (*pend)[x]);
			}
			pend->erase(pend->end() - this->_order, pend->end());
			std::cout << "pend : ";
			for(size_t i = 0; i < pend->size(); i++)
				std::cout << (*pend)[i] << " ";
			std::cout << std::endl;
		}
		// size_t pendPos = j * this->_order;
		// for(size_t i = 0; i < main->size() / this->_order; i++)
		// {
		// 	size_t mainPos = i * this->_order;
		// 	std::cout << mainPos + this->_order << " "  ;
		// 	std::cout << (*main)[mainPos + this->_order - 1] << " " << std::endl;
		// 	if ((*main)[mainPos + this->_order - 1] > (*pend)[pendPos + this->_order - 1])
		// 	{

		// 		std::cout << "main : ";
		// 		for(size_t i = 0; i < main->size(); i++)
		// 			std::cout << (*main)[i] << " ";
		// 		std::cout << std::endl;
		// 		for(size_t x = pendPos + this->_order - 1; x > pendPos - 1; x--)
		// 		{
		// 			std::cout << "caca : "<< x << " " << pendPos << " " << pendPos + this->_order << " " << i * this->_order << std::endl;
		// 			main->insert(it, (*pend)[x]);
		// 		}
		// 		std::cout << "main : ";
		// 		for(size_t i = 0; i < main->size(); i++)
		// 			std::cout << (*main)[i] << " ";
		// 		std::cout << std::endl;
		// 		break;
		// 	}
		// 	it++;
		// }
	}
}

void PmergeMeVector::insertSort()
{
	this->_order = 4;
	std::cout << " ---- " << this->_order << std::endl;
	//main
	//pend
	//trash

	vi main;
	vi pend;
	vi trash;

	for (size_t i = 0; i < this->_order; i++)
		main.push_back(this->_data[i]);
	for (size_t i = this->_order; i < this->_order * 2; i++)
		main.push_back(this->_data[i]);

	size_t nbPair = this->_data.size() / this->_order;
	size_t idxPair = 2;
	size_t idxTrash = 0;
	int insert = 0;

	while (idxPair < nbPair)
	{
		insert = 1;
		if ((idxPair + 1) % 2 == 0)
		{
			for (size_t i = idxPair * this->_order; i < (idxPair + 1) * this->_order; i++)
				main.push_back(this->_data[i]);
		}
		else
		{
			for (size_t i = idxPair * this->_order; i < (idxPair + 1) * this->_order; i++)
				pend.push_back(this->_data[i]);
		}
		//std::cout << idxPair * this->_order << std::endl;
		idxPair++;
		if (idxPair >= nbPair)
		{
			for (idxTrash = idxPair * this->_order; idxTrash < this->_data.size(); idxTrash++)
				trash.push_back(this->_data[idxTrash]);
		}
	}

	//std::cout << this->_data.size() << " " << main.size() << " " << (this->_data.size() - main.size()) / this->_order << std::endl;
	// while ((this->_data.size() - main.size()) / this->_order)
	// {
		//if ((this->_data.size() - main.size()) / this->_order % 1)
			//std::cout << "caca" << std::endl;
	// }
	


	/*this->_data.erase (this->_data.begin(),this->_data.begin()+3);

	std::cout << "this->_data contains:";
	for (unsigned i=0; i<this->_data.size(); ++i)
		std::cout << ' ' << this->_data[i];
	std::cout << '\n';*/
	/*vit t = this->_data.begin();
	this->_data.insert(t, this->_order);*/
	if (!insert)
		main = this->_data;
	this->_data.clear();
	//TODO insert and sort
	if (pend.size() != 0)
	{
		jacobSort(&main, &pend, &trash);
	}
	// for(size_t i = 0; i < pend.size(); i++)
	// 	main.push_back(pend[i]);
	for(size_t i = 0; i < trash.size(); i++)
		main.push_back(trash[i]);

	this->_data = main;
	this->printContainer("result : ");
	/*if (this->_order / 2 > 0)
	{
		this->_order /= 2;
		this->insertSort();
	}*/
}

//TODO maybe one day simplify that
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