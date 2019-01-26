find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(CompositeTest composite_test.cc)

target_link_libraries(CompositeTest gtest Composite)

add_subdirectory(googletest)
