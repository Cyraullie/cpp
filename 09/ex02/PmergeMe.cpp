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

void PmergeMeVector::binarySearch(vi &main, vit sbegin, vit send, vit start, vit end)
{
	int range = std::distance(start, end + 1) / this->_order;
	vit middle = end - 1;

	if (range == 3)
		middle -= this->_order;
	if (range <= 1)
		middle = end - (this->_order * range);
	else
		middle = end - ((range / 2) * this->_order);

	while (true)
	{
		if (range <= 2)
		{
			if (range <= 1)
			{
				if (*send <= *end)
					main.insert(start, sbegin, send + 1);
				else
					main.insert(end + 1, sbegin, send + 1);
			}
			else if (range == 2)
			{
				if (*send <= *middle)
					main.insert(start, sbegin, send + 1);
				else
				{
					if (*send <= *end)
						main.insert(middle + 1, sbegin, send + 1);
					else
						main.insert(end + 1, sbegin, send + 1);
				}
			}
			break ;
		}
		
		if (*send <= *middle)
		{
			if (std::distance(start, end + 1) / this->_order > 2)
				end = middle - this->_order;
			else
				end = middle;
		}
		else
			start = middle + 1;
		
		range = std::distance(start, end + 1) / this->_order;
		if (range == 3)
			middle -= this->_order;
		if (range <= 1)
			middle = end - (this->_order * range);
		else
			middle = end - ((range / 2) * this->_order);
	}
}

void PmergeMeVector::standardBinary(vi *main, vi *pend)
{
	vit start = pend->end() - this->_order;
	vit end = pend->end() - 1;

	while (!pend->empty())
	{
		binarySearch(*main, start, end, main->begin(), main->end() - 1);
		if (start != pend->begin())
		{
			start -= this->_order;
			end -= this->_order;
		}
		for (size_t i = this->_order; i > 0; i--)
			pend->pop_back();
	}
}



void PmergeMeVector::jacobsthalBinary(vi *main, vi *pend, vit ite)
{
	while (pend->size() != 0)
	{
		size_t nbrInsert = *ite - (*(ite - 1));
		if (nbrInsert > (pend->size() / this->_order))
		{
			standardBinary(main, pend);
			break ;
		}

		while (nbrInsert > 0)
		{
			while (nbrInsert > 0)
			{
				int jRange = (*ite + (*(ite - 1))) - 1;
				vit sbegin = pend->begin() + (this->_order * nbrInsert) - this->_order;
				vit send = pend->begin() + (this->_order * nbrInsert) - 1;
				vit start = main->begin();
				int range = (main->size() / this->_order) - jRange;
				vit end = main->end() - (range * this->_order) - 1;
				binarySearch(*main, sbegin, send, start, end);
				nbrInsert--;
				pend->erase(sbegin, send + 1);
			}
			ite++;
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
		idxPair++;
		if (idxPair >= nbPair)
		{
			for (idxTrash = idxPair * this->_order; idxTrash < this->_data.size(); idxTrash++)
				trash.push_back(this->_data[idxTrash]);
		}
	}

	if (!insert)
		main = this->_data;
	this->_data.clear();
	
	if (pend.size() != 0)
	{
		jacobSort(&main, &pend, &trash);
	}
	this->_data = main;
	if (this->_order / 2 > 0)
	{
		this->_order /= 2;
		this->insertSort();
	}
}

void PmergeMeVector::exchangePair(int i, int j)
{
	int len = _order - 1;
	int swap = 0;

	while (len >= 0)
	{
		swap = _data[i];
		_data[i] = _data[j];
		_data[j] = swap;

		i--;
		j--;
		len--;
	}
}

//TODO maybe one day simplify that
void PmergeMeVector::pairSort()
{
		int i = _order - 1;
	int j = _order * 2 - 1;
	int size = _data.size();

	while (i < size && j < size)
	{
		if (_data[j] < _data[i])
			exchangePair(i, j);
		i = j + _order;
		j = i + _order;
	}

	if ((this->_order * 2) * 2 < this->_data.size())
	{
		this->_order *= 2;
		this->pairSort();
	}
	else 
	{
		this->insertSort();
	}

}

void PmergeMeVector::sort()
{
	this->printContainer("Before: ");
	this->pairSort();
	this->printContainer("After: ");
	this->printTime();
}

void printNum(const unsigned int it)
{
	std::cout << it << " ";
}

void PmergeMeVector::printContainer(std::string msg)
{
	std::cout << CYAN << std::boolalpha << msg;
	std::for_each(this->_data.begin(), this->_data.end(), printNum);
	std::cout << "\nis sorted : " << isSorted(this->_data.begin(), this->_data.end()) << std::endl;
	std::cout << RESET << std::endl;
}

void PmergeMeVector::printTime()
{
	std::cout << BLUE << "Time to process a range of "<< BOLD << this->_data.size() << RESET << BLUE << " elements with std::vector : " << BOLD << float(clock() - this->_start) / CLOCKS_PER_SEC << RESET << BLUE << " sec" << RESET << std::endl;
}


PmergeMeDeque::PmergeMeDeque() : _order(0)
{
	std::cout << GREEN << "Default PmergeMeDeque constructor called" << RESET << std::endl;
}

PmergeMeDeque::PmergeMeDeque(char **args) : _order(1)
{
	std::cout << GREEN << "PmergeMeDeque constructor with args called" << RESET << std::endl;
	this->_start = clock();
	for (int i = 1; args[i]; i++)
	{
		this->_data.push_back(std::atoi(args[i]));
	}
}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& cpy): _data(cpy._data), _order(cpy._order), _start(cpy._start)
{
	std::cout << LIGHT_GREEN << "PmergeMeDeque copy constructor called" << RESET << std::endl;
}

PmergeMeDeque::~PmergeMeDeque()
{
	std::cout << RED << "PmergeMeDeque destructor called" << RESET << std::endl;

}

PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& src)
{
	std::cout << LIGHT_GREEN << "PmergeMeDeque assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_data = src._data;
		this->_order = src._order;
		this->_start = src._start;
	}
	return *this;
}

void PmergeMeDeque::swap(int i, int j)
{
	int swap = 0;

	swap = this->_data[i];
	this->_data[i] = this->_data[j];
	this->_data[j] = swap;
}

di PmergeMeDeque::jacobsthal(size_t size)
{
	di j;
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

void PmergeMeDeque::insert(di *main, di *pend, dit it, size_t pendPos)
{
	for(size_t k = 0; k < this->_order; ++k)
	{
		size_t x = pendPos - k;
		it = main->insert(it, (*pend)[x]);
	}
}

void PmergeMeDeque::binarySearch(di &main, dit sbegin, dit send, dit start, dit end)
{
	int range = std::distance(start, end + 1) / this->_order;
	dit middle = end - 1;

	if (range == 3)
		middle -= this->_order;
	if (range <= 1)
		middle = end - (this->_order * range);
	else
		middle = end - ((range / 2) * this->_order);

	while (true)
	{
		if (range <= 2)
		{
			if (range <= 1)
			{
				if (*send <= *end)
					main.insert(start, sbegin, send + 1);
				else
					main.insert(end + 1, sbegin, send + 1);
			}
			else if (range == 2)
			{
				if (*send <= *middle)
					main.insert(start, sbegin, send + 1);
				else
				{
					if (*send <= *end)
						main.insert(middle + 1, sbegin, send + 1);
					else
						main.insert(end + 1, sbegin, send + 1);
				}
			}
			break ;
		}
		
		if (*send <= *middle)
		{
			if (std::distance(start, end + 1) / this->_order > 2)
				end = middle - this->_order;
			else
				end = middle;
		}
		else
			start = middle + 1;
		
		range = std::distance(start, end + 1) / this->_order;
		if (range == 3)
			middle -= this->_order;
		if (range <= 1)
			middle = end - (this->_order * range);
		else
			middle = end - ((range / 2) * this->_order);
	}
}

void PmergeMeDeque::exchangePair(int i, int j)
{
	int len = _order - 1;
	int swap = 0;

	while (len >= 0)
	{
		swap = _data[i];
		_data[i] = _data[j];
		_data[j] = swap;

		i--;
		j--;
		len--;
	}
}

void PmergeMeDeque::standardBinary(di *main, di *pend)
{
	dit start = pend->end() - this->_order;
	dit end = pend->end() - 1;

	while (!pend->empty())
	{
		binarySearch(*main, start, end, main->begin(), main->end() - 1);
		if (start != pend->begin())
		{
			start -= this->_order;
			end -= this->_order;
		}
		for (size_t i = this->_order; i > 0; i--)
			pend->pop_back();
	}
}



void PmergeMeDeque::jacobsthalBinary(di *main, di *pend, dit ite)
{
	while (pend->size() != 0)
	{
		size_t nbrInsert = *ite - (*(ite - 1));
		if (nbrInsert > (pend->size() / this->_order))
		{
			standardBinary(main, pend);
			break ;
		}

		while (nbrInsert > 0)
		{
			while (nbrInsert > 0)
			{
				int jRange = (*ite + (*(ite - 1))) - 1;
				dit sbegin = pend->begin() + (this->_order * nbrInsert) - this->_order;
				dit send = pend->begin() + (this->_order * nbrInsert) - 1;
				dit start = main->begin();
				int range = (main->size() / this->_order) - jRange;
				dit end = main->end() - (range * this->_order) - 1;
				binarySearch(*main, sbegin, send, start, end);
				nbrInsert--;
				pend->erase(sbegin, send + 1);
			}
			ite++;
		}
	}
}

void PmergeMeDeque::jacobSort(di *main, di *pend, di *trash)
{

	di j = jacobsthal(pend->size() / this->_order);
	dit ite = std::find(j.begin(), j.end(), 3);
	if (ite == j.end())
		standardBinary(main, pend);
	else
		jacobsthalBinary(main, pend, ite);

	if (!trash->empty())
	{
		for (dit ite = trash->begin(); ite != trash->end(); ite++)
			main->push_back(*ite);
		trash->clear();
	}
	
}

void PmergeMeDeque::insertSort()
{
	di main;
	di pend;
	di trash;

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
		idxPair++;
		if (idxPair >= nbPair)
		{
			for (idxTrash = idxPair * this->_order; idxTrash < this->_data.size(); idxTrash++)
				trash.push_back(this->_data[idxTrash]);
		}
	}

	if (!insert)
		main = this->_data;
	this->_data.clear();
	
	if (pend.size() != 0)
	{
		jacobSort(&main, &pend, &trash);
	}
	this->_data = main;
	if (this->_order / 2 > 0)
	{
		this->_order /= 2;
		this->insertSort();
	}
}

//TODO maybe one day simplify that
void PmergeMeDeque::pairSort()
{
	int i = _order - 1;
	int j = _order * 2 - 1;
	int size = _data.size();

	while (i < size && j < size)
	{
		if (_data[j] < _data[i])
			exchangePair(i, j);
		i = j + _order;
		j = i + _order;
	}

	if ((this->_order * 2) * 2 < this->_data.size())
	{
		this->_order *= 2;
		this->pairSort();
	}
	else 
	{
		this->insertSort();
	}

}

void PmergeMeDeque::sort()
{
	this->printContainer("Before: ");
	this->pairSort();
	this->printContainer("After: ");
	this->printTime();
}

void PmergeMeDeque::printContainer(std::string msg)
{
	std::cout << MAGENTA << std::boolalpha << msg;
	std::for_each(this->_data.begin(), this->_data.end(), printNum);
	std::cout << "\nis sorted : " << isSorted(this->_data.begin(), this->_data.end()) << std::endl;
	std::cout << RESET << std::endl;
}

void PmergeMeDeque::printTime()
{
	std::cout << BLUE << "Time to process a range of "<< BOLD << this->_data.size() << RESET << BLUE << " elements with std::deque : " << BOLD << float(clock() - this->_start) / CLOCKS_PER_SEC << RESET << BLUE << " sec" << RESET << std::endl;
}