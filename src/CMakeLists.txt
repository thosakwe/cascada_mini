find_package(FLEX REQUIRED)
set(CMAKE_CXX_STANDARD 11)

flex_target(CascadaLexer cascada_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/cascada_lexer.cpp
  DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/cascada_lexer.h)

add_library(cascada
  ${FLEX_CascadaLexer_OUTPUTS}
)
target_compile_options(cascada PUBLIC -Wno-deprecated-register)
