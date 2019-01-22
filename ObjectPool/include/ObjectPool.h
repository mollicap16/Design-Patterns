#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/object_pool/cpp/1

#include <iostream>
#include <list>

class Resource {
public:
  Resource();

  void Reset();
  int32_t GetValue();
  void SetValue(int32_t number);

private:
  int32_t value_;
};


// This object pool is implemented as a singleton
class ObjectPool {
public:
  // Static method for accessing class instance part of singleton design pattern
  static ObjectPool* GetInstance();
  Resource* GetResource();
  void ReturnResource(Resource* object);

private:
  std::list<Resource*> resources_;
  static ObjectPool* instance_;
  ObjectPool() {} // Private Constructor
};

#endif //OBJECTPOOL_H
