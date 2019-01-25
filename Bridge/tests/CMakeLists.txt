find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(BridgeTest bridge_test.cc)

target_link_libraries(BridgeTest gtest Bridge)

add_subdirectory(googletest)
