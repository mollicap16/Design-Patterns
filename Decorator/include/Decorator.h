#ifndef DECORATOR_H
#define DECORATOR_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/decorator/cpp/2

#include <iostream>

namespace DecoratorNamespace {
/***************************************************************************************
 * Decorator Design Pattern Properties:
 *    1. Create a "lowest common denominator" that makes classes interchangeable.
 *    2. Create a second level base class for optional functionality.
 *    3. "Core" class and "Decorator" class declare an "isa" relationship.
 *    4. Decorator class "has a" instance of the "lowest common denominator".
 *    5. Decorator class delegates to the "has a" object.
 *    6. Create a Decorator derived class for each optional embellishment
 *    7. Decorator derived classes delegate to base class AND add extra stuff.
 *    8. Client has a responsibility to compose desired configurations.
 *
 **************************************************************************************/

// 1. "Lowest Common Denominator"
class Widget {
public:
  virtual void Draw()=0;
};

class TextField: public Widget {
public:
  // 3. "Core" class and "is a"
  TextField(int32_t width, int32_t height);
  void Draw();

private:
  int32_t width_;
  int32_t height_;
};

// 2. 2nd level base class
class Decorator: public Widget {
public:
  Decorator(Widget* widget);
  void Draw();
private:
Widget* widget_;  // 4. "has a" relationship
};

class BorderDecorator: public Decorator {
public:
  // 6. Optional Embellishment
  BorderDecorator(Widget* widget);
  void Draw();
};

class ScrollDecorator: public Decorator {
public:
  // 6. Optional Embellishment
  ScrollDecorator(Widget* widget);
  void Draw();
};

} // Decorator Namespace
#endif //DECORATOR_H
