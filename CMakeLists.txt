cmake_minimum_required(VERSION 3.0)
project(cascada)

set(CMAKE_CXX_STANDARD 11)
set(CASCADA_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include CACHE STRING "The path to Cascada includes.")
set(CASCADA_EXECUTABLE cascada_bin CACHE STRING "The Cascada executable target's name.")
set(CASCADA_LIBRARY cascada CACHE STRING "The Cascada library")

add_library(${CASCADA_LIBRARY} STATIC)
target_include_directories(${CASCADA_LIBRARY} PUBLIC ${CASCADA_INCLUDE_DIR})
install(TARGETS ${CASCADA_LIBRARY} DESTINATION lib)

add_executable(${CASCADA_EXECUTABLE} src/main.c)
target_include_directories(${CASCADA_EXECUTABLE} PUBLIC ${CASCADA_INCLUDE_DIR})
target_link_libraries(${CASCADA_EXECUTABLE} ${CASCADA_LIBRARY})
set_target_properties(${CASCADA_EXECUTABLE} PROPERTIES RUNTIME_OUTPUT_NAME ${CASCADA_LIBRARY})
install(TARGETS ${CASCADA_EXECUTABLE} bin)
