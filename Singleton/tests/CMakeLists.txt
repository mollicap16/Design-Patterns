find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(SingletonTest singleton_test.cc)

target_link_libraries(SingletonTest gtest Singleton)

add_subdirectory(googletest)
