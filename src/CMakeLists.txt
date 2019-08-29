find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
set(CMAKE_CXX_STANDARD 11)

bison_target(CascadaParser cascada_parser.y ${CMAKE_CURRENT_BINARY_DIR}/cascada_parser.cpp)
flex_target(CascadaLexer cascada_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/cascada_lexer.cpp
  DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/cascada_lexer.h)
add_flex_bison_dependency(CascadaLexer CascadaParser)

add_library(cascada
  ${BISON_CascadaParser_OUTPUTS}
  ${FLEX_CascadaLexer_OUTPUTS}
)
target_compile_options(cascada PUBLIC -Wno-deprecated-register)
