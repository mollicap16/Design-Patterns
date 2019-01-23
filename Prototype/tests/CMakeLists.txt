find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(PrototypeTest prototype_test.cc)

target_link_libraries(PrototypeTest gtest Prototype)

add_subdirectory(googletest)
