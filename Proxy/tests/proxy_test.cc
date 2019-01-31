#include <gtest/gtest.h>
#include <Proxy.h>
#include <ImageProxy.h>

TEST(ProxyTest, PettyCashProxyTest){
  PettyCash cash;
  Person workers[4];
  int32_t amount  = 100;

  for (int32_t i = 0; i < 4; ++i, amount += 100){
    if (!cash.Withdraw(workers[i], amount))
      std::cout << "No money for " << workers[i].GetName() << std::endl;
    else
      std::cout << amount << " dollars for " << workers[i].GetName() << std::endl;
  }

  std::cout << "Remaining Cash Balance = " << cash.GetBalance() << std::endl;
}

TEST(ProxyTest, ImageProxyTest) {
  Image images[5];

  images[0].Draw();
  images[1].Draw();
  images[4].Draw();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
