#include <ObjectPool.h>

Resource::Resource() : value_(0) {}

void Resource::Reset() {
  value_=0;
}

int32_t Resource::GetValue(){
  return value_;
}

void Resource::SetValue(int32_t number){
  value_ = number;
}


ObjectPool* ObjectPool::GetInstance(){
  if (instance_ == nullptr){
    instance_ = new ObjectPool;
  }

  return instance_;
}


Resource* ObjectPool::GetResource(){
  if (resources_.empty()){
    std::cout << "Creating New resource." << std::endl;
    return new Resource;
  }
  else {
    std::cout << "Reusing Existing." << std::endl;
    Resource* resource = resources_.front();
    resources_.pop_front();
    return resource;
  }
}

void ObjectPool::ReturnResource(Resource* object){
  object->Reset();
  resources_.push_back(object);
}
