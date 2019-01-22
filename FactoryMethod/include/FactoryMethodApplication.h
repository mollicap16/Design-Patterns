#ifndef FACTORYMETHODAPPLICATION_H
#define FACTORYMETHODAPPLICATION_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/factory_method/cpp/2

#include <iostream>
#include <string.h>

// Abstract base class declared by framework
class Document {
public:
  Document(char const * fn) {strcpy(name_, fn);}
  virtual void Open() = 0;
  virtual void Close() = 0;
  char const * GetName(){return name_;}
private:
  char name_[20];
};

// Concrete derived class defined by client
class MyDocument: public Document {
public:
  MyDocument(char const * fn): Document(fn){}
  void Open();
  void Close();
};

// Framework declaration
class Application {
public:
  Application();

  // The client will call this "entry point" of the framework
  void NewDocument(const char *name);
  void OpenDocument(){}
  void ReportDocs();

  // Framework declares a "hole" for the client to customize
  virtual Document* CreateDocument(char const*) = 0;
private:
  int index_;

  // Framework uses Document's base class
  Document* docs_[10];
};

// Customization of framework defined by client
class MyApplication: public Application {
public:
  MyApplication();

  // Client defines Framework's "hole"
  Document* CreateDocument(const char * fn);
};

#endif //FACTORYMETHODAPPLICATION_H
