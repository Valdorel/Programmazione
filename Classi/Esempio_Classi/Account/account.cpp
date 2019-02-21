#include "account.h"
#include <iostream>

account::account(int c, double b) : accountNumber(c), balance(b) {}

int account::getAccountNumber() {
  return accountNumber;
}

int account::getBalance() {
  return balance;
}

void account::setBalance(double b) {
  balance = b;
}

void account::credit(double a) {
  balance = balance + a;
}

void account::debit(double a) {

  if (a > balance) {
    std::cout << "amount withdrawn exceeds the current balance!" << '\n';
    return;
  }
  balance = balance - a;
}


void account::stampa() {
  std::cout << "A/C no: "<<accountNumber<<", Balance=$ "<<balance << '\n';
}
