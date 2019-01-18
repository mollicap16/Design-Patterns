#ifndef BUILDER_H
#define BUILDER_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/builder/cpp/1
#include <iostream>
//#include <stdio.h>
#include <string.h>

enum PersistenceType {File, Queue, Pathway};

struct PersistenceAttribute {
  PersistenceType type;
  char value[30];
};

class DistributionWorkPackage {
public:
  DistributionWorkPackage(char  const* type);
  ~DistributionWorkPackage(){}

  void SetFile(char const* file, char const* v);
  void SetQueue(char const* queue, char const* v);
  void SetPathway(char const* pathway, char const* v);

  const char* GetState() {return desc_;}
private:
  char desc_[200];
  char temp_[80];
};

// Builder interface
class Builder {
public:
  virtual void ConfigureFile(char*)=0;
  virtual void ConfigureQueue(char*)=0;
  virtual void ConfigurePathway(char*)=0;

  DistributionWorkPackage* GetResult() {return result_;}
protected:
  DistributionWorkPackage* result_;
};

class UnixBuilder: public Builder {
public:
  UnixBuilder();
  ~UnixBuilder(){}

  void ConfigureFile(char* name);
  void ConfigureQueue(char* queue);
  void ConfigurePathway(char* type);
};

class VmsBuilder: public Builder {
public:
  VmsBuilder();
  ~VmsBuilder(){}

  void ConfigureFile(char* name);
  void ConfigureQueue(char* queue);
  void ConfigurePathway(char* type);
};

class Reader {
public:
  Reader(){}
  ~Reader(){}

  void SetBuilder(Builder* build);
  void Construct(PersistenceAttribute list[], int32_t number);
private:
  Builder* builder_;
};

#endif // BUILDER_H
