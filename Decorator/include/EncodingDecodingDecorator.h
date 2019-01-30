#ifndef ENCODINGDECODINGDECORATOR_H
#define ENCODINGDECODINGDECORATOR_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/decorator/cpp/3

#include <iostream>
#include <string>

class Interface {
public:
  virtual ~Interface(){}
  virtual void Write(std::string&)=0;
  virtual void Read(std::string&)=0;
};

class Core: public Interface {
public:
  ~Core();
  void Write(std::string& bytes);
  void Read(std::string& ){}
};

class Decorator: public Interface {
public:
  Decorator(Interface* c);
  ~Decorator();

  void Write(std::string& bytes);
  void Read(std::string& bytes);

private:
  Interface* inner_;
};

class Wrapper: public Decorator {
public:
  Wrapper(Interface* c, std::string str);
  ~Wrapper();

  void Write(std::string& bytes) {Decorator::Write(bytes);}
  void Read(std::string& bytes) {Decorator::Read(bytes);}

private:
  std::string backward_;
  std::string forward_;
};

#endif //ENCODINGDECODINGDECORATOR_H
