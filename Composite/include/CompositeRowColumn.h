#ifndef COMPOSITEROWCOLUMN_H
#define COMPOSITEROWCOLUMN_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/composite/cpp/1

#include <iostream>
#include <vector>

class Component {
public:
  virtual void Traverse()=0;
};

class Primitive : public Component {
public:
  Primitive(int32_t value);
  void Traverse();

private:
  int32_t value_;
};

class Composite : public Component {
public:
  Composite(int32_t value);
  void Add(Component* element);
  void Traverse();

private:
  std::vector<Component*> children_;
  int32_t value_;
};

class Row : public Composite {
public:
  Row(int32_t value);
  void Traverse();
};

class Column : public Composite {
public:
  Column(int32_t value);
  void Traverse();
};

#endif //COMPOSITEROWCOLUMN_H
