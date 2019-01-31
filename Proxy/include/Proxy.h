#ifndef PROXY_H
#define PROXY_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/proxy/cpp/3

#include <iostream>

/* This is a protection proxy, which controls access to the original object */

class Person {
public:
  Person();
  std::string GetName() {return name_;}

private:
  std::string name_;

  const static std::string list_[];
  static int32_t next_;
};

class PettyCashProtection {
public:
  PettyCashProtection();
  bool Withdraw(int32_t amount);
  int32_t GetBalance() {return balance_;}

private:
  int32_t balance_;
};

// Proxy to the real cash
class PettyCash {
public:
  PettyCash() {}

  bool Withdraw(Person& person, int32_t amount);
  int32_t GetBalance();

private:
  PettyCashProtection real_cash_;
};

#endif //PROXY_H
