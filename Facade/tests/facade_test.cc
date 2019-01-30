#include <iostream>
#include <gtest/gtest.h>
#include <Facade.h>

TEST(FacadeTest, FacadeTest1){
  FacilitiesFacade facilities;

  facilities.SubmitNetworkRequest();

  // Keep checking until the job is complete.
  while(!facilities.CheckOnStatus()){
  }

  std::cout << "Job completed after only " << facilities.GetNumberOfCalls() << " phone calls" << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
