find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(ProxyTest proxy_test.cc)

target_link_libraries(ProxyTest gtest Proxy)

add_subdirectory(googletest)
