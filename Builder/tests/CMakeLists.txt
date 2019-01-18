find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(BuilderTest builder_test.cc)

target_link_libraries(BuilderTest gtest Builder)

add_subdirectory(googletest)
