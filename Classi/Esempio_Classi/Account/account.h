#ifndef ACCOUNT_H
#define ACCOUNT_H

class account {
  private:
    int accountNumber;
    double balance;

  public:
    account(int accountNumber, double balance = 0.0);

    int getAccountNumber();

    int getBalance();

    void setBalance(double balance);

    void credit(double amount);

    void debit(double amount);

    void stampa();


};
#endif
