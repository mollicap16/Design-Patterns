#include <Proxy.h>

const std::string Person::list_[] = {"Tom", "Dick", "Harry", "Bubba"};
int32_t Person::next_=0;

Person::Person() {
  name_ = list_[next_++];
}

PettyCashProtection::PettyCashProtection(){
  balance_ = 500;
}

bool PettyCashProtection::Withdraw(int32_t amount){
  if (amount > balance_)
    return false;

  balance_ -= amount;
  return true;
}

bool PettyCash::Withdraw(Person &person, int32_t amount){
  std::string person_name = person.GetName();
  if (person_name == "Tom" || person_name == "Dick" || person_name == "Harry" || person_name == "Bubba")
    return real_cash_.Withdraw(amount);
  else
    return false;
}

int32_t PettyCash::GetBalance(){
  return real_cash_.GetBalance();
}
