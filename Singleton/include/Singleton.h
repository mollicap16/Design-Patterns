#ifndef SINGLETON_H
#define SINGLETON_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/singleton/cpp/2

#include <iostream>
#include <stdio.h>
/**************************************************************************************
 * Properties of Singleton Design Pattern:
 *    1. Define a private static attribute in the "single instance" class.
 *    2. Define a public static accessor function in the class.
 *    3. Do "Lazy Initialization" (creation on demand) in the accessor function.
 *    4. Define all constructors to be protected or private.
 *    5. Clients may only use the accessor function to manipulate the Singleton.
 *    6. Inheritance can be supported, but static functions may not be overridden. The
 *       base class must be declared a friend of the derived class (in order to access
 *       the protected constructor).
 *
 **************************************************************************************/

// Example of a Singleton base class that can be inherited
class Number {
public:
  virtual ~Number(){}

  // 2. Define a public static accessor function
  static Number* GetInstance();
  static void SetType(std::string t);

  virtual void SetValue(int32_t input);
  virtual int32_t GetValue(){return value_;}

protected:
  int32_t value_;

  // 4. Define all constructors to be protected (or private)
  Number();

// 1. Define a private static attribute
private:
  static std::string type_;
  static Number* instance_;
};

class Octal: public Number {
public:
  // 6. Inheritance can be supported but a friend class needs to be defined.
  friend class Number;  // Needed to access the value member of Number

  void SetValue(int32_t input);

protected:
  Octal(){}
};

#endif //SINGLETON_H
