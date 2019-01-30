#include <gtest/gtest.h>
#include <Decorator.h>
#include <EncodingDecodingDecorator.h>

TEST(DecoratorTest, DecoratorTest1){
  // 8. Client has the responsibility to compose desired configurations
  DecoratorNamespace::Widget* widget = new DecoratorNamespace::BorderDecorator
                                        (new DecoratorNamespace::BorderDecorator
                                        (new DecoratorNamespace::ScrollDecorator
                                        (new DecoratorNamespace::TextField(80, 24))));

  widget->Draw();

}

TEST(DecoratorTest, DecoratorEncodingDecodingTest){
  Interface* object = new Wrapper(new Wrapper(new Wrapper(new Core(), "123"), "abc"), "987");

  std::string buffer;
  object->Write(buffer);
  std::cout << "main: " << buffer << std::endl;
  object->Read(buffer);
  delete object;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
