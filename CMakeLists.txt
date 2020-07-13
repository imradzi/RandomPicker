cmake_minimum_required(VERSION 3.17)
project(randomPicker)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
add_executable(${PROJECT_NAME} example.cpp)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
target_compile_features(randomPicker PUBLIC cxx_std_17)
