#include "kunde.hpp"

#include <iostream>

std::string Kunde::getName() {
    return name;
}

double Kunde::getBalance() {
    return balance;
}

int Kunde::getPin() {
    return pin;
}


void Kunde::setName(std::string name) {
    this->name = name;
}

void Kunde::setBalance(double balance) {
    this->balance = balance;
}

void Kunde::setPin(double pin) {
    this->pin = pin;
}


void Kunde::printBalance() {
    std::cout << "Kontostand: € " << balance << std::endl;
}

bool Kunde::checkPIN() {
    std::cout << "Please enter your pin: ";
    double scannedPin;
    std::cin >> scannedPin;

    return scannedPin == pin;
}

void Kunde::drawMoney() {
    if (!checkPIN()) {
        std::cout << "ERROR: Wrong Pin" << std::endl;
        return;
    }

    std::cout << "How much money do you want to withdraw?: ";
    double amount;
    std::cin >> amount;

    if (amount > balance) {
        std::cout << "ERROR: You don't have enough money!" << std::endl;
        return;
    }

    balance -= amount;
}
