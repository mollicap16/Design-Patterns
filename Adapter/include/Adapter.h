#ifndef ADAPTER_H
#define ADAPTER_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/adapter/cpp/1

#include <iostream>

typedef int32_t Coordinate;
typedef int32_t Dimension;

// Desired Interface
class Rectangle {
public:
  virtual void Draw()=0;
};

// Legacy Component
class LegacyRectangle {
public:
  LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2);
  void OldDraw();

private:
  Coordinate x1_;
  Coordinate y1_;
  Coordinate x2_;
  Coordinate y2_;
};


// Adapter Wrapper
class RectangleAdapter: public Rectangle, private LegacyRectangle {
public:
  RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h);
  virtual void Draw();
};

#endif //ADAPTER_H
