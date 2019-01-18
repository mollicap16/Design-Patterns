#include <iostream>
#include <gtest/gtest.h>
#include <Builder.h>

const int32_t kNumberOfEntries = 6;

TEST(BuilderTest, BuilderTest1){
  PersistenceAttribute input[kNumberOfEntries] = {
    {File, "state.dat"},
    {File, "config.sys"},
    {Queue, "compute"},
    {Queue, "log"},
    {Pathway, "authentication"},
    {Pathway, "error processing"}
  };

  UnixBuilder unix_builder;
  VmsBuilder vms_builder;
  Reader reader;

  reader.SetBuilder(&unix_builder);
  reader.Construct(input, kNumberOfEntries);
  std::cout << unix_builder.GetResult()->GetState() << std::endl << std::endl;

  reader.SetBuilder(&vms_builder);
  reader.Construct(input, kNumberOfEntries);
  std::cout << vms_builder.GetResult()->GetState() << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
