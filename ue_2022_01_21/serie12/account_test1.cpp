/**
 * UE 12.2
 */

#include <cassert>
#include <iostream>

#include "account.hpp"

int main() {
    Account account1(1, 100.0, 1.0);
    SavingsAccount account2(2, 200.0, 1.0, 0.02);
    CurrentAccount account3(3, 10000.0, 2.0, -1000.0);

    // Test print()
    account1.print();
    account2.print();
    account3.print();

    // Test deposit()
    std::cout << "Deposit" << std::endl;
    account1.deposit(100);
    account1.print();

    // Test withdraw()
    std::cout << "Withdraw" << std::endl;
    account1.withdraw(140);
    account1.print();
    // account3.withdraw(100000); // Canceled because -90000 < -1000

    // Test addInterest()
    std::cout << "Add interest" << std::endl;
    account2.addInterest();
    account2.print();

    // Test chargeFee()
    std::cout << "Charge fee" << std::endl;
    account2.chargeFee();
    account2.print();

    // Test getters and setters
    assert(account1.getAccountId() == 1);

    account1.setBalance(1);
    assert(account1.getBalance() == 1);

    account1.setFee(2);
    assert(account1.getFee() == 2);

    account2.setInterestRate(4);
    assert(account2.getInterestRate() == 4);

    account3.setOverdrawLimit(-100);
    assert(account3.getOverdrawLimit() == -100);

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}