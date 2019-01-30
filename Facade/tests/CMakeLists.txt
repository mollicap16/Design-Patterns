find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(FacadeTest facade_test.cc)

target_link_libraries(FacadeTest gtest Facade)

add_subdirectory(googletest)
