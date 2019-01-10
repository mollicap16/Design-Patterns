#include <iostream>
#include <gtest/gtest.h>
#include <AbstractFactory.h>

TEST(AbstractFactoryTest, AbstractFactoryDifferentPlatformTest){
  Factory* factory;
#ifdef LINUX
  factory = new LinuxFactory;
#else
  factory = new WindowsFactory;
#endif

  Client* client = new Client(factory);
  client->draw();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
