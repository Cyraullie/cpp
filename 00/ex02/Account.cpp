/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:30:22 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/13 16:42:42 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ostream>
#include <ctime>
#include <iomanip>
#include <sstream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}


int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int add_zero(int nb)
{
	if (nb < 10)
	{
		std::cout << "0";
	}
	return (nb);
}



void	displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(&time);
	std::tm *local = std::localtime(&time);

	std::cout << "[";
	std::cout << local->tm_year + 1900;
	std::cout << add_zero(local->tm_mon + 1);
	std::cout << add_zero(local->tm_mday);
	std::cout << "_";
	std::cout << add_zero(local->tm_hour);
	std::cout << add_zero(local->tm_min);
	std::cout << add_zero(local->tm_sec);
	std::cout << "] ";
}

void	makeDeposit( int deposit )
{

}

bool	makeWithdrawal( int withdrawal )
{

}


int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	displayStatus( void )
{

}
