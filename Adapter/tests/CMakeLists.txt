find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(AdapterTest adapter_test.cc)

target_link_libraries(AdapterTest gtest Adapter)

add_subdirectory(googletest)
