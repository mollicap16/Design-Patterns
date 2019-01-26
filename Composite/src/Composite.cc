#include <Composite.h>

namespace CompositeNamespace {

Leaf::Leaf(int32_t value) : value_(value) {}

void Leaf::Traverse(){
  std::cout << value_ << " ";
}


void Composite::Add(Component *element){
  children_.push_back(element);
}

void Composite::Traverse(){
  for (const auto& itr : children_){
    itr->Traverse();
  }
}

}
