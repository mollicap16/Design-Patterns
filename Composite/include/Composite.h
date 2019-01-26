#ifndef COMPOSITE_H
#define COMPOSITE_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/composite/cpp/1

#include <iostream>
#include <vector>
namespace CompositeNamespace {
/***************************************************************************************
 * Composite Design Pattern Properties:
 *    1. Identify the scalar/primitive classes and vector/container classes
 *    2. Create an "interface" (lowest common denominator) that can make all concrete
 *       classes "interchangeable"
 *    3. All concrete classes declare an "is a" relationship to the interface
 *    4. All "container" classes couple themselves to the interface (recursive
 *       composition, Composite "has a" set of children up the "is a" hierarchy)
 *    5. "Container" classes use polymorphism as they delegate to their childre.
 *
 **************************************************************************************/

// 2. Create an "interface" (lowest common denominator"
class Component {
public:
  virtual void Traverse()=0;
};


// 1. Scalar/Primitive class
// 3. "Is a" relationship
class Leaf : public Component {
public:
  Leaf(int32_t value);
  void Traverse();

private:
  int32_t value_;
};

// 1. Scalar/Primitive class
// 3. "Is a" relationship
class Composite : public Component {
public:
  void Add(Component* element);
  void Traverse();

private:
  // 4. "Container" class coupled to the interface
  std::vector<Component*> children_;
};

}
#endif //COMPOSITE_H
