#ifndef INCLUDE_KUNDE__
#define INCLUDE_KUNDE__

#include <string>

class Kunde
{
private:
    std::string name;
    double balance;
    int pin;

public:
    std::string getName();
    double getBalance();
    int getPin();

    void setName(std::string name);
    void setBalance(double balance);
    void setPin(double pin);

    void printBalance();
    bool checkPIN();
    void drawMoney();
};

#endif
