#include "Account.hpp"
#include <sys/time.h>
#include <iostream>

int Account::_nbAccounts=0;
int Account::_totalAmount=0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals=0;

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	(this->_nbAccounts)++;
	(this->_totalAmount) += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void Account::_displayTimestamp( void )
{
	timeval	time;

	gettimeofday(&time, NULL);
	std::cout << "[" << time.tv_sec << "_" << time.tv_usec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	(this->_nbDeposits)++;
	std::cout << "deposits:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal ( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= this->_amount)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		(this->_nbWithdrawals)++;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		(this->_totalNbWithdrawals)++;
		this->_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:" << "refused";
		std::cout << std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}
