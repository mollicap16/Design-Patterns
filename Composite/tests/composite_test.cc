#include <gtest/gtest.h>
#include <Composite.h>
#include <CompositeRowColumn.h>

TEST(CompositeTest, CompositeTest1){
  CompositeNamespace::Composite containers[4];

  for (int32_t i = 0; i < 4; ++i)
    for (int32_t j = 0; j < 3; ++j)
      containers[i].Add(new CompositeNamespace::Leaf(i*3+j));

  for (int32_t i = 1; i < 4; ++i)
    containers[0].Add(&(containers[i]));

  for (int32_t i = 0; i < 4; ++i){
    containers[i].Traverse();
    std::cout << std::endl;
  }
}

TEST(CompositeTest, CompositeRowColumnTest) {
  Row first(1);
  Column second(2);
  Column third(3);
  Row fourth(4);
  Row fifth(5);

  Primitive sixth(6);
  Primitive seventh(7);
  Primitive eighth(8);
  Primitive ninth(9);
  Primitive tenth(10);

  first.Add(&second);
  first.Add(&third);
  third.Add(&fourth);
  third.Add(&fifth);
  first.Add(&sixth);
  second.Add(&seventh);
  third.Add(&eighth);
  fourth.Add(&ninth);
  fifth.Add(&tenth);

  first.Traverse();
  std::cout << "\n";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
