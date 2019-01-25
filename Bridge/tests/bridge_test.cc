#include <gtest/gtest.h>
#include <Bridge.h>
#include <vector>

TEST(BridgeTest, BridgeTimeTest){
  std::vector<Time*> time;

  time.push_back(new Time(14,30));
  time.push_back(new CivilianTime(2, 30, 1));
  time.push_back(new ZuluTime(14, 30, 6));

  for (const auto& itr : time){
    itr->DisplayTime();
  }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
