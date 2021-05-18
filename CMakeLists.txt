cmake_minimum_required(VERSION 3.17)
project(Queues)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queues main.cpp)

add_executable(Circular_Array circular/array.cpp)
add_executable(Circular_LL circular/linkedList.cpp)

add_executable(Deque_Array deque/array.cpp)
add_executable(Deque_LL deque/linkedList.cpp)

add_executable(Priority_Array priority/array.cpp)
add_executable(Priority_LL priority/linkedList.cpp)

add_executable(Project project/telephoneLine.cpp project/Queue.h)

