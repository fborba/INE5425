add_library(parserManager
            parser_changes_information.cpp)

target_include_directories(parserManager
                           PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_compile_features(parserManager
                        PUBLIC cxx_std_17)
