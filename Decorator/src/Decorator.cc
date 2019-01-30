#include <Decorator.h>

namespace DecoratorNamespace {

TextField::TextField(int32_t width, int32_t height)
  : width_(width), height_(height) {}

void TextField::Draw() {
  std::cout << "TextField: " << width_ << ", " << height_ << std::endl;
}

Decorator::Decorator(Widget* widget)
  : widget_(widget) {}

void Decorator::Draw(){
  widget_->Draw(); // 5. Delegation
}

BorderDecorator::BorderDecorator(Widget* widget) : Decorator(widget){}

void BorderDecorator::Draw() {
  // 7. Delegate to base class and add extra stuff.
  Decorator::Draw();
  std::cout << "  BorderDecorator\n";
}

ScrollDecorator::ScrollDecorator(Widget* widget) : Decorator(widget) {}

void ScrollDecorator::Draw(){
  // 7. Delegate to base class and add extra stuff.
  Decorator::Draw();
  std::cout << "  ScrollDecorator\n";
}

}
