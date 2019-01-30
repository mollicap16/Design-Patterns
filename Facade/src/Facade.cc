#include<Facade.h>

void MisDepartment::SubmitNetworkRequest() {
  state_ = 0;
}

bool MisDepartment::CheckOnStatus() {
  if (++state_ == Complete)
    return true;

  return false;
}

void ElectricianUnion::SubmitNetworkRequest(){
  state_ = 0;
}

bool ElectricianUnion::CheckOnStatus(){
  if (++state_ == Complete)
    return true;

  return false;
}

void FacilitiesDepartment::SubmitNetworkRequest(){
  state_ = 0;
}

bool FacilitiesDepartment::CheckOnStatus(){
  if (++state_ == Complete)
    return true;

  return false;
}

FacilitiesFacade::FacilitiesFacade() : count_(0){}

void FacilitiesFacade::SubmitNetworkRequest(){
  state_ = 0;
}

bool FacilitiesFacade::CheckOnStatus() {
  count_++;

  if (state_ == Received){
    state_++;

    // Forward the job request to the engineer
    engineer_.SubmitNetworkRequest();
    std::cout << "Submitted to Facilities - " << count_ << " phone calls so far." << std::endl;
  }
  else if (state_ == SubmitToEngineer) {
    // if the engineer is complete, forward to the electrician.
    if (engineer_.CheckOnStatus()){
      state_++;
      electrician_.SubmitNetworkRequest();
      std::cout << "Submitted to Electrician - " << count_ << " phone calls so far." << std::endl;
    }
  }
  else if( state_ == SubmitToElectrician){
    // if the electrician is complete, forward to the technician.
    if (electrician_.CheckOnStatus()){
      state_++;
      technician_.SubmitNetworkRequest();
      std::cout << "Submitted to MIS - " << count_ << " phone calls so far." << std::endl;
    }
  }
  else if (state_ == SubmitToTechnician){
    // if the technician is complete, the job is done.
    if (technician_.CheckOnStatus())
      return true;
  }

  // The job isnt completed
  return false;
}
