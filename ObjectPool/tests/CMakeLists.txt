find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(ObjectPoolTest object_pool_test.cc)

target_link_libraries(ObjectPoolTest gtest ObjectPool)

add_subdirectory(googletest)
