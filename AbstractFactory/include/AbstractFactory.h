#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/abstract_factory/cpp/before-after

#include <iostream>

/*******************************************************
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 ******************************************************/
class Widget {
 public:
  virtual void draw() = 0;
};

//Concrete product family 1.
class LinuxButton : public Widget {
 public:
  void draw() { std::cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget {
 public:
  void draw() { std::cout << "LinuxMenu\n"; }
};

// Concrete product family 2.
class WindowsButton : public Widget {
 public:
  void draw() { std::cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget {
 public:
  void draw() { std::cout << "WindowsMenu\n"; }
};

/*******************************************************
 * Abstract factory defines methods to create all
 * related products.
 ******************************************************/
class Factory {
 public:
  virtual Widget *create_button() = 0;
  virtual Widget *create_menu() = 0;
};

/*******************************************************
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 ******************************************************/
class LinuxFactory : public Factory {
 public:
  Widget *create_button() {return new LinuxButton;}
  Widget *create_menu() {return new LinuxMenu;}
};

/*******************************************************
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 ******************************************************/
class WindowsFactory : public Factory {
 public:
  Widget *create_button() {return new WindowsButton;}
  Widget *create_menu() {return new WindowsMenu;}
};

/*******************************************************
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 ******************************************************/
class Client {
 public:
  Client(Factory *f);
  ~Client(){}

  void draw();
  void display_window_one();
  void display_window_two();

private:
 Factory *factory;
};

#endif //ABSTRACTFACTORY_H
