#include "account.hpp"

#include <cassert>
#include <iostream>

/*
 * Account implementation.
 */ 

Account::Account(int account_id, double balance, double fee) {
    assert(fee >= 0);

    this->account_id = account_id;
    this->balance = balance;
    this->fee = fee;
}

Account::~Account() {}

int Account::getAccountId() const {
    return account_id;
}

double Account::getBalance() const {
    return balance;
}

double Account::getFee() const {
    return fee;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

void Account::setFee(double fee) {
    assert(fee >= 0);
    this->fee = fee;
}

void Account::deposit(double sum) {
    assert(sum >= 0);
    this->balance += sum;
}

void Account::withdraw(double sum) {
    assert(sum >= 0);
    this->balance -= sum;
}

void Account::chargeFee() {
    this->balance -= fee;
}

void Account::print() const {
    std::cout << std::endl << "Account " << account_id << std::endl;
    std::cout << "    Balance: € " << balance << std::endl;
    std::cout << "    fee: € " << fee << std::endl;
}

/*
 * SavingsAccount implementation.
 */ 

SavingsAccount::SavingsAccount(int account_id, double balance, double fee, double interest_rate) : Account(account_id, balance, fee) {
    this->interest_rate = interest_rate;
}

SavingsAccount::~SavingsAccount() {}

double SavingsAccount::getInterestRate() const {
    return interest_rate;
}

void SavingsAccount::setInterestRate(double interest_rate) {
    this->interest_rate = interest_rate;
}

void SavingsAccount::addInterest() {
    deposit(interest_rate * getBalance());
}

void SavingsAccount::print() const {
    Account::print(); // Call print() of parent class Account.
    std::cout << "    interest_rate: " << (interest_rate * 100) << "%" << std::endl;
}

/*
 * CurrentAccount implementation.
 */ 

CurrentAccount::CurrentAccount(int account_id, double balance, double fee, double overdraw_limit) : Account(account_id, balance, fee) {
    this->overdraw_limit = overdraw_limit;
}

CurrentAccount::~CurrentAccount() {}

// Getter
double CurrentAccount::getOverdrawLimit() const {
    return overdraw_limit;
}

// Setter
void CurrentAccount::setOverdrawLimit(double overdraw_limit) {
    this->overdraw_limit = overdraw_limit;
}

// Methods
void CurrentAccount::withdraw(double sum) {
    assert(getBalance() - sum >= overdraw_limit);

    Account::withdraw(sum); // Call withdraw() of parent class Account.
}

void CurrentAccount::print() const {
    Account::print(); // Call print() of parent class Account.
    std::cout << "    overdraw_limit: € " << overdraw_limit << std::endl;
}