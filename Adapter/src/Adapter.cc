#include <Adapter.h>

LegacyRectangle::LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
  : x1_(x1), y1_(y1), x2_(x2), y2_(y2)
{

  std::cout << " LegacyRectangle: create. (" << x1_ << "," << y1_ << ") => (" <<
               x2_ << "," << y2_ << ")" << std::endl;
}

void LegacyRectangle::OldDraw(){
  std::cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ <<
            ") => (" << x2_ << "," << y2_ << ")" << std::endl;
}


RectangleAdapter::RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h)
  : LegacyRectangle(x, y, x + w, y + h)
{
  std::cout << "RectangleAdapter: create.  (" << x << "," << y <<
               "), width = " << w << ", height = " << h << std::endl;
}

void RectangleAdapter::Draw() {
  std::cout << "RectangleAdapter: draw." << std::endl;
  OldDraw();
}
