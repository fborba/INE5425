find_package(Git REQUIRED)

message(STATUS "Updating doctest")
execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unitTest
               unit_test.cpp)

target_include_directories(unitTest
                           PRIVATE $<TARGET_PROPERTY:parserManager,INCLUDE_DIRECTORIES>)

target_link_libraries(unitTest
                      PRIVATE doctest
                      PRIVATE parserManager)

target_compile_features(unitTest
                        PRIVATE cxx_std_17)

add_custom_target(test unitTest)
