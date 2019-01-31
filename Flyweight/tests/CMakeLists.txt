find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(FlyweightTest flyweight_test.cc)

target_link_libraries(FlyweightTest gtest Flyweight)

add_subdirectory(googletest)
