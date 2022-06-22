cmake_minimum_required(VERSION 3.10)

# set the project name
project(leetcode)

set(CMAKE_CXX_STANDARD 17)


# add the executable
file(GLOB project_SRCS substring_concatenation_of_all_words.cpp utils.cpp)

add_executable(substring ${project_SRCS})
#target_link_libraries(substring PUBLIC utils)

# target_include_directories(substring PUBLIC 
#                             "${PROJECT_SOURCE_DIR}/Utils")   