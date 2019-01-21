find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(FactoryMethodTest factory_method_test.cc)

target_link_libraries(FactoryMethodTest gtest FactoryMethod)

add_subdirectory(googletest)
