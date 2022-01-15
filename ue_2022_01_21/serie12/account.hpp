#ifndef INCLUDE_ACCOUNT__
#define INCLUDE_ACCOUNT__

class Account
{
private:
    int account_id;
    double balance;
    double fee;

public:
    // Constructor and destructor
    Account(int account_id = 0, double balance = 0.0, double fee = 1.0);
    ~Account();

    // Getter
    int getAccountId() const;
    double getBalance() const;
    double getFee() const;

    // Setter
    void setBalance(double balance);
    void setFee(double yearlyFee);

    // Methods
    void deposit(double sum);
    void withdraw(double sum);
    void chargeFee();
    void print() const;
};

class SavingsAccount : public Account
{
private:
    double interest_rate;

public:
    // Constructor and destructor
    SavingsAccount(int account_id = 0, double balance = 0.0, double fee = 1.0, double interest_rate = 0.01);
    ~SavingsAccount();

    // Getter
    double getInterestRate() const;

    // Setter
    void setInterestRate(double interest_rate);

    // Methods
    void addInterest();
    void print() const;
};

class CurrentAccount : public Account
{
private:
    double overdraw_limit;

public:
    // Constructor and destructor
    CurrentAccount(int account_id = 0, double balance = 0.0, double fee = 1.0, double overdraw_limit = 0.0);
    ~CurrentAccount();

    // Getter
    double getOverdrawLimit() const;
    
    // Setter
    void setOverdrawLimit(double overdraw_limit);
    
    // Methods
    void withdraw(double sum);
    void print() const;
};

#endif
