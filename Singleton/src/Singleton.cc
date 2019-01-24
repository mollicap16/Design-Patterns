#include <Singleton.h>

Number* Number::GetInstance(){
  if (instance_ == nullptr){
    // 3. Do "Lazy initialization" in teh accessor function
    if (type_ ==  "octal")
      instance_ = new Octal();
    else
      instance_ = new Number();
  }

  return instance_;
}

Number::Number() {
  std::cout << ":ctor: ";
}


void Number::SetType(std::string type){
  type_ = type;
  delete instance_;
  instance_ = nullptr;
}

void Number::SetValue(int32_t input){
  value_ = input;
}

// Defining Static Members
std::string Number::type_ = "decimal";
Number* Number::instance_ = nullptr;


void Octal::SetValue(int32_t input){
  char buffer[10];
  // Using the sprintf function to conver the integer input into it's octal value
  sprintf(buffer, "%o", input);
  sscanf(buffer, "%d", &value_);
}
