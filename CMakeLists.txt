cmake_minimum_required(VERSION 3.15)
project(repartizare)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14")

set(INCL ${CMAKE_SOURCE_DIR}/include/Institute.hpp
        ${CMAKE_SOURCE_DIR}/include/GroupOfStudentsForInstitute.hpp
        ${CMAKE_SOURCE_DIR}/include/Student.hpp)

set(SRC ${CMAKE_SOURCE_DIR}/src/Institute.cpp
        ${CMAKE_SOURCE_DIR}/src/GroupOfStudentsForInstitute.cpp
        ${CMAKE_SOURCE_DIR}/src/Student.cpp)

add_library(repartizator SHARED ${SRC})
target_include_directories (repartizator PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(repartizare ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(repartizare repartizator)
