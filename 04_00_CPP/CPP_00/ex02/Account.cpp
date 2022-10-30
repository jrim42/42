/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:04 by jrim              #+#    #+#             */
/*   Updated: 2022/10/30 17:20:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

//-------------- constructor/destructor ----------------//
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;
	_totalNbDeposits = _totalNbDeposits - _nbWithdrawals;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

//----------------------- getters -----------------------//
int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//-------------------- display/utils ---------------------//
void	Account::_displayTimestamp( void )
{
	time_t	timestamp;
	char	buf[16];

	time(&timestamp);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << buf << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawls" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool	result;

	_amount = _amount - withdrawal;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount + withdrawal;
	if (checkAmount())
	{
		result = true;
		_totalAmount = _totalAmount - withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout	<< ";withdrawal:" << _nbWithdrawals
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals;
	}
	else
	{
		result = false;
		_amount = _amount + withdrawal;
		std::cout	<< ";withdrawal:refused";
	}
	std::cout << std::endl;
	return (result);
}

int		Account::checkAmount( void ) const
{
	if (_amount < 0)
		return (0);
	return (1);
}

