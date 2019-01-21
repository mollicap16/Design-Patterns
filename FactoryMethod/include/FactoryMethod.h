#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/factory_method/cpp/1

#include <iostream>

class Stooge {
public:
  //Factory Method
  static Stooge* MakeStooge(int32_t choice);
  virtual void SlapStick()=0;

};

class Larry : public Stooge {
public:
  void SlapStick();
};

class Moe : public Stooge {
public:
  void SlapStick();
};

class Curly: public Stooge {
public:
  void SlapStick();
};

#endif //FACTORYMETHOD_H
