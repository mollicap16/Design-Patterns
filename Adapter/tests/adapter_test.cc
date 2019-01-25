#include <iostream>
#include <gtest/gtest.h>
#include <Adapter.h>

TEST(AdapterTest, AdapterTest1){
  Rectangle *rect = new RectangleAdapter(120, 200, 60, 40);
  rect->Draw();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
