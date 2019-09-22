cmake_minimum_required(VERSION 3.2)

project(INE5425
        LANGUAGES CXX)

add_subdirectory(source)
add_subdirectory(dependencies)
add_subdirectory(test EXCLUDE_FROM_ALL)
