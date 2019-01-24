#include <iostream>
#include <gtest/gtest.h>
#include <Singleton.h>

TEST(SingletonTest, SingletonTest1){
  // Number myInstances; -  error: cannot access protected constructor

  // 5. Clients may only use the accessor function to manipulate the Singleton
  Number::GetInstance()->SetValue(42);
  std::cout << "Value is " << Number::GetInstance()->GetValue() << std::endl;
  ASSERT_EQ(Number::GetInstance()->GetValue(), 42);

  // Setting the Singleton Number class to octal
  Number::SetType("octal");
  Number::GetInstance()->SetValue(64);  // 64 integer (base 10) = 100 octal (base 8)
  std::cout << "Value is " << Number::GetInstance()->GetValue() << std::endl;
  ASSERT_EQ(Number::GetInstance()->GetValue(), 100);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
