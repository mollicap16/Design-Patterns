#ifndef FACADE_H
#define FACADE_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/facade/cpp/1

#include <iostream>

class MisDepartment {
public:
  void SubmitNetworkRequest();
  bool CheckOnStatus();

private:
  enum States{Received, DenyAllKnowledge, ReferClientToFacilities,
              FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
              ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
              FixElectriciansWiring, Complete};

  int32_t state_;
};

class ElectricianUnion {
public:
  void SubmitNetworkRequest();
  bool CheckOnStatus();

private:
  enum States{Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
              WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
              DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
              TurnInThePaperwork, Complete};

  int32_t state_;

};

class FacilitiesDepartment {
public:
  void SubmitNetworkRequest();
  bool CheckOnStatus();

private:
  enum States{Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
              EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
              ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
              EngineerFillsOutPaperWork, Complete};

  int32_t state_;
};

// Facade
class FacilitiesFacade {
public:
  FacilitiesFacade();

  void SubmitNetworkRequest();
  bool CheckOnStatus();
  int32_t GetNumberOfCalls() {return count_;}

private:
  enum States{Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician};

  int32_t state_;
  int32_t count_;
  FacilitiesDepartment engineer_;
  ElectricianUnion electrician_;
  MisDepartment technician_;
};

#endif //FACADE_H
