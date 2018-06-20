cmake_minimum_required(VERSION 3.0)
project(cascada_mini C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CASCADA_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include CACHE STRING "The path to Cascada includes.")
set(CASCADA_EXECUTABLE cascada_interpreter CACHE STRING "The Cascada executable target's name.")
set(CASCADA_LIBRARY cascada CACHE STRING "The Cascada library")

add_library(${CASCADA_LIBRARY} STATIC
        include/cascada/cascada.h
        include/cascada/linked_list.h
        include/cascada/ast.h
        include/cascada/scan.h src/scan.c
        src/linked_list.c include/cascada/context.h include/cascada/error.h include/cascada/parse.h)
target_include_directories(${CASCADA_LIBRARY} PUBLIC ${CASCADA_INCLUDE_DIR})
install(TARGETS ${CASCADA_LIBRARY} DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(${CASCADA_EXECUTABLE} src/main.c)
target_include_directories(${CASCADA_EXECUTABLE} PUBLIC ${CASCADA_INCLUDE_DIR})
target_link_libraries(${CASCADA_EXECUTABLE} ${CASCADA_LIBRARY})
set_target_properties(${CASCADA_EXECUTABLE} PROPERTIES RUNTIME_OUTPUT_NAME ${CASCADA_LIBRARY})
install(TARGETS ${CASCADA_EXECUTABLE} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})