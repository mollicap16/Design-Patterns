#include <CompositeRowColumn.h>

Primitive::Primitive(int32_t value) : value_(value) {}

void Primitive::Traverse(){
  std::cout << value_ << " ";
}

Composite::Composite(int32_t value) : value_(value){}

void Composite::Add(Component *element){
  children_.push_back(element);
}

void Composite::Traverse(){
  std::cout << value_ << " ";
  for (const auto& itr : children_){
    itr->Traverse();
  }
}

Row::Row(int32_t value) : Composite(value) {}

void Row::Traverse() {
  std::cout << "Row";
  Composite::Traverse();
}

Column::Column(int32_t value) : Composite(value) {}

void Column::Traverse() {
  std::cout << "Column";
  Composite::Traverse();
}
