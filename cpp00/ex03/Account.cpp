#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _nbAccounts += 1;
    _accountIndex = _nbAccounts - 1;

    _amount = initial_deposit;
    _totalAmount += _amount;

    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              <<"amount:" << _amount << ";"
              << "created" << std::endl;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              <<"amount:" << _amount << ";"
              << "closed" << std::endl;
}

// para çekme
bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              <<"p_amount:" << _amount << ";";
    if (withdrawal > checkAmount())
    {
        std::cout << "withdrawal:refuse" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";"
              << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
    return (true);
}

int Account::checkAmount() const{
    return (_amount);
}

// para yatırma
void Account::makeDeposit(int deposit){
    _displayTimestamp();
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits += 1;
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "deposits:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << ";"
              << std::endl;
}

// objelerimiz için özel olan verileri yazdırıyoruz
void Account::displayStatus() const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << ";"
              << std::endl;
}

// ortak verileri bilgisini gösteriyoruz
void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << ";"
              << std::endl;
}

// zaman hesaplaması
void Account::_displayTimestamp(){
    std::time_t result = std::time(NULL);
    std::tm *tm_local = std::localtime(&result);
    int year = 1900 + tm_local->tm_year;
    int month = tm_local->tm_mon + 1;
    int day = tm_local->tm_mday;
    int hour = tm_local->tm_hour;
    int min = tm_local->tm_min;
    int sec = tm_local->tm_sec;
    std::cout << "[";
    std::cout << std::setfill('0') << year << std::setw(2) << month << std::setw(2) << day << "_";
    std::cout << std::setfill('0') << std::setw(2) << hour << std::setw(2) << min << std::setw(2) << sec;
    std::cout << "]";
}

// GET FUNCS for static veriable tüm objelerimiz için ortak değerlerdir.
int	Account::getNbAccounts( void ) {return _nbAccounts;}
int	Account::getTotalAmount( void ) {return _totalAmount;}
int	Account::getNbDeposits( void ) {return _totalNbDeposits;}
int	Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

