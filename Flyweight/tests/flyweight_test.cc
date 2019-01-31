#include <iostream>
#include <gtest/gtest.h>
#include <Flyweight.h>

int32_t FlyweightFactory::num_icons_=0;
Icon* FlyweightFactory::icons_[];

TEST(FlyweightTest, FlyweightTest1){
 DialogBox* dialogs[2];
 dialogs[0] = new FileSelection(FlyweightFactory::GetIcon("go"),
                                FlyweightFactory::GetIcon("stop"),
                                FlyweightFactory::GetIcon("select"));

 FlyweightFactory::ReportTheIcons();

 dialogs[1] = new CommitTransation(FlyweightFactory::GetIcon("select"),
                                   FlyweightFactory::GetIcon("stop"),
                                   FlyweightFactory::GetIcon("undo"));

 for (int32_t i = 0; i < 2; ++i)
   dialogs[i]->Draw();


 FlyweightFactory::ReportTheIcons();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
