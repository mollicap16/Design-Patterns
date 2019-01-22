#include <iostream>
#include <gtest/gtest.h>
#include <ObjectPool.h>

ObjectPool* ObjectPool::instance_ = nullptr;

TEST(ObjectPoolTest, ObjectPoolTest1){
  ObjectPool* pool = ObjectPool::GetInstance();

  Resource* resource_one;
  Resource* resource_two;
  resource_one = pool->GetResource();
  resource_one->SetValue(10);
  resource_two = pool->GetResource();
  resource_two->SetValue(20);

  ASSERT_EQ(resource_one->GetValue(), 10);
  ASSERT_EQ(resource_two->GetValue(), 20);
  ASSERT_NE(resource_one, resource_two);

  // Return Resources
  pool->ReturnResource(resource_one);
  pool->ReturnResource(resource_two);

  resource_one = pool->GetResource();
  resource_two = pool->GetResource();

  ASSERT_EQ(resource_one->GetValue(), 0);
  ASSERT_EQ(resource_two->GetValue(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
