#ifndef BRIDGE_H
#define BRIDGE_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/bridge/cpp/1

#include <iostream>
#include <string.h>

// Implementation Interface
class TimeImplementation {
public:
  TimeImplementation(int32_t hour, int32_t min);
  virtual void Tell();

protected:
  int32_t hour_;
  int32_t min_;
};

// Concrete Implementation
class CivilianTimeImplementation : public TimeImplementation {
public:
  CivilianTimeImplementation(int32_t hour, int32_t min, int32_t pm);
  void Tell();

protected:
  char which_m_[4];
};

// Concrete Implementation
class ZuluTimeImplementation : public TimeImplementation {
public:
  ZuluTimeImplementation(int32_t hour, int32_t min, int32_t zone);
  void Tell();

protected:
  char zone_[30];
};

// Abstract Time Class
class Time {
public:
  Time(){}
  Time(int32_t hour, int32_t min);
  virtual void DisplayTime();

protected:
  TimeImplementation* implementation_;
};

// Concreate Time Class Type
class CivilianTime : public Time {
public:
  CivilianTime(int32_t hour, int32_t min, int32_t pm);

};

// Concreate Time Class Type
class ZuluTime : public Time {
public:
  ZuluTime(int32_t hour, int32_t min, int32_t zone);
};

#endif //BRIDGE_H
