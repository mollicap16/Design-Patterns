#include <EncodingDecodingDecorator.h>

Core::~Core() {
  std::cout << "dtor-Core\n";
}

void Core::Write(std::string &bytes) {
  bytes +="MESSAGE|";
}

Decorator::Decorator(Interface *c) : inner_(c) {}

Decorator::~Decorator() {
  delete inner_;
}

void Decorator::Write(std::string& byte){
  inner_->Write(byte);
}

void Decorator::Read(std::string& byte){
  inner_->Read(byte);
}

Wrapper::Wrapper(Interface *c, std::string str)
  : Decorator(c), forward_(str)
{
  std::string::reverse_iterator itr;
  for (itr = str.rbegin(); itr != str.rend(); ++itr){
    backward_ += *itr;
  }
}

Wrapper::~Wrapper() {
  std::cout << "dtor-" << forward_ << " ";
}
