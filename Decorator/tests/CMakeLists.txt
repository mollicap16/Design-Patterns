find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(DecoratorTest decorator_test.cc)

target_link_libraries(DecoratorTest gtest Decorator)

add_subdirectory(googletest)
