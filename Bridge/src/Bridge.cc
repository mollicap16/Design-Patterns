#include <Bridge.h>

// Implementation Interface
TimeImplementation::TimeImplementation(int32_t hour, int32_t min) : hour_(hour), min_(min) {}

void TimeImplementation::Tell() {
  std::cout << "Time is " << hour_ << min_ << std::endl;
}

// Concrete Implemenation
CivilianTimeImplementation::CivilianTimeImplementation(int32_t hour, int32_t min, int32_t pm) : TimeImplementation(hour, min) {
  if (pm)
    strcpy(which_m_, "PM");
  else
    strcpy(which_m_, "AM");
}

void CivilianTimeImplementation::Tell(){
  std::cout << "Time is " << hour_ << ":" << min_ << " " << which_m_ << std::endl;
}

// Concrete Implemenation
ZuluTimeImplementation::ZuluTimeImplementation(int32_t hour, int32_t min, int32_t zone) : TimeImplementation(hour, min) {
  if (zone == 5)
    strcpy(zone_, "Easter Standard Time");
  else if (zone == 6)
    strcpy(zone_, "Central Standard Time");
}

void ZuluTimeImplementation::Tell(){
  std::cout << "Time is " << hour_ << " " << min_ << " " << zone_ << std::endl;
}

// Abstract Time Class uses Implementation Interface
Time::Time(int32_t hour, int32_t min){
  implementation_ = new TimeImplementation(hour, min);
}

void Time::DisplayTime(){
  implementation_->Tell();
}

// Concreate Time Class
CivilianTime::CivilianTime(int32_t hour, int32_t min, int32_t pm){
  implementation_ = new CivilianTimeImplementation(hour, min, pm);
}

// Concreate Time Class
ZuluTime::ZuluTime(int32_t hour, int32_t min, int32_t zone) {
  implementation_ = new ZuluTimeImplementation(hour, min, zone);
}
