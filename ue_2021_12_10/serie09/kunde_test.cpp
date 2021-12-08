/**
 * Aufgabe 9.5
 */

#include "kunde.hpp"

#include <assert.h>
#include <iostream>

int main() {
    Kunde kunde;

    kunde.setName("Max Mustermann");
    kunde.setPin(1234);
    kunde.setBalance(1000.5);

    assert(kunde.getName() == "Max Mustermann");
    assert(kunde.getPin() == 1234);
    assert(kunde.getBalance() == 1000.5);

    kunde.printBalance();
    kunde.drawMoney();
    kunde.printBalance();

    return 0;
}