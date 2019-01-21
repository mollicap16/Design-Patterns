#include <FactoryMethod.h>

Stooge* Stooge::MakeStooge(int32_t choice){
  if(choice == 1){
    return new Larry;
  }
  else if (choice == 2){
    return new Moe;
  }
  else
    return new Curly;
}


void Larry::SlapStick(){
  std::cout << "Larry: poke eyes\n";
}

void Moe::SlapStick(){
  std::cout << "Moe: slap head\n";
}

void Curly::SlapStick(){
  std::cout << "Curly: suffer abuse\n";
}
