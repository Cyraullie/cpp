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

vi PmergeMeVector::jacobsthal(size_t size)
{
	std::cout << size << std::endl;
	vi j;
	size_t range = 0;

	j.push_back(0);
	j.push_back(1);
	while (true)
	{
		size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
		if (range >= size)
			break ;
		range += (size_t)(j[j.size() - 1] - j[j.size() - 2]); 

		j.push_back(next);
	}
	return (j);
}

void PmergeMeVector::insert(vi *main, vi *pend, vit it, size_t pendPos)
{
	for(size_t k = 0; k < this->_order; ++k)
	{
		size_t x = pendPos - k;
		it = main->insert(it, (*pend)[x]);
	}
}

void PmergeMeVector::standardBinary(vi *main, vi *pend)
{
	std::cout << "STANDARD" << std::endl;
	(void)main;
	(void)pend;
}



void PmergeMeVector::jacobsthalBinary(vi *main, vi *pend, vit ite)
{
	std::cout << "JACOB DE EMRDE" << std::endl;
	// (void)main;
	// (void)pend;
	// (void)ite;
	while (pend->size() != 0)
	{
		size_t nbrInsert = *ite - (*(ite - 1));
		if (nbrInsert > (pend->size() / _order))
		{
			standardBinary(main, pend);
			break ;
		}

		while (nbrInsert > 0)
		{
			std::cout << "ite : " << *ite << std::endl;
			std::cout << "ite : " << nbrInsert << std::endl;
			std::cout << "size : " << main->size() << " order : " << this->_order << " r " << main->size() / this->_order / 2 << std::endl;
			size_t mid = main->size() / this->_order / 2;
			size_t mainPos = mid * this->_order + this->_order - 1;

			std::cout << "position in main : " << mainPos << " mid: " << mid << std::endl;
			std::cout << "main: " ;
			for (size_t p = 0; p < main->size(); p++)
				std::cout << (*main)[p] << " ";
			std::cout << std::endl;
			std::cout << "pend: " ;
			for (size_t p = 0; p < pend->size(); p++)
				std::cout << (*pend)[p] << " ";
			std::cout << std::endl;

			for(size_t j = 0; j <= pend->size() / this->_order; j++)
			{

				vit it = main->begin();
				for (size_t i = 0; i < mainPos; i++)
					it++;

				size_t pendPos = j * this->_order + this->_order - 1;
				std::cout << pendPos << std::endl;
				std::cout << *it << " " << (*pend)[pendPos] << std::endl;
				if (*it < (*pend)[pendPos])
				{
					it++;

					this->insert(main, pend, it, pendPos);
					if (pend->size() >= this->_order)
						pend->erase(pend->end() - this->_order, pend->end());
					
				}
				else if (*it > (*pend)[pendPos])
				{
					it--;

					this->insert(main, pend, it, pendPos);
					if (pend->size() >= this->_order)
						pend->erase(pend->end() - this->_order, pend->end());
					
				}
			}
			nbrInsert--;
		}
	}
	
	
	
}



void PmergeMeVector::jacobSort(vi *main, vi *pend, vi *trash)
{

	vi j = jacobsthal(pend->size() / this->_order);
	vit ite = std::find(j.begin(), j.end(), 3);
	if (ite == j.end())
		standardBinary(main, pend);
	else
		jacobsthalBinary(main, pend, ite);

	if (!trash->empty())
	{
		for (vit ite = trash->begin(); ite != trash->end(); ite++)
			main->push_back(*ite);
		trash->clear();
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

	this->_data = main;
	this->printContainer("result : ");
	// if (this->_order / 2 > 0)
	// {
	// 	this->_order /= 2;
	// 	this->insertSort();
	// }
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

	if ((size_t)(this->_order * 2 ) * 2 < this->_data.size())
	{
		this->_order *= 2;
		this->pairSort();
	}
	else 
	{
		this->printContainer("uwu: ");
		this->insertSort();
	}

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