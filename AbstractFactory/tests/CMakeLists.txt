find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(AbstractFactoryTest abstract_factory_test.cc)

target_link_libraries(AbstractFactoryTest gtest AbstractFactory)

add_subdirectory(googletest)
