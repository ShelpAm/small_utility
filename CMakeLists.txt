cmake_minimum_required(VERSION 3.18.0)

project(small_utility)

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++20)

set (include_native ${PROJECT_SOURCE_DIR}/include)
set (includes ${include_native})

include_directories (${includes})

add_subdirectory (src)
add_subdirectory (test)
#add_subdirectory (thirdparty)

