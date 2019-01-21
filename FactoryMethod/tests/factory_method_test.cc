#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <FactoryMethod.h>

TEST(AbstractFactoryTest, AbstractFactoryDifferentPlatformTest){
  std::vector<Stooge*> roles;

  roles.push_back(Stooge::MakeStooge(1));
  roles.push_back(Stooge::MakeStooge(2));
  roles.push_back(Stooge::MakeStooge(3));
  roles.push_back(Stooge::MakeStooge(4));

  for(auto const& itr : roles){
    itr->SlapStick();
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
