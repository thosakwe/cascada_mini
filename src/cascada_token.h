#ifndef CASCADA_CASCADA_TOKEN_H
#define CASCADA_CASCADA_TOKEN_H
#include <stdbool.h>
#include <stddef.h>

typedef enum {
  // Symbols
  CASCADA_TOKEN_ARROW,
  CASCADA_TOKEN_COLON,
  CASCADA_TOKEN_COMMA,
  CASCADA_TOKEN_LBRACKET,
  CASCADA_TOKEN_RBRACKET,
  CASCADA_TOKEN_LCURLY,
  CASCADA_TOKEN_RCURLY,
  CASCADA_TOKEN_LPAREN,
  CASCADA_TOKEN_RPAREN,

  // Operators
  CASCADA_TOKEN_OP_EQUALS,
  CASCADA_TOKEN_OP_MULT,
  CASCADA_TOKEN_OP_DIV,
  CASCADA_TOKEN_OP_MOD,
  CASCADA_TOKEN_OP_PLUS,
  CASCADA_TOKEN_OP_MINUS,

  // Keywords
  CASCADA_TOKEN_ELSE,
  CASCADA_TOKEN_FINAL,
  CASCADA_TOKEN_FN,
  CASCADA_TOKEN_IF,
  CASCADA_TOKEN_RETURN,
  CASCADA_TOKEN_VAR,

  // Values
  CASCADA_TOKEN_BOOL,
  CASCADA_TOKEN_NUMBER,
  CASCADA_TOKEN_STRING,
  CASCADA_TOKEN_ID,
} cascada_token_type_t;

typedef struct _cascada_token {
  cascada_token_type_t type;
  union {
    bool as_bool;
    long long as_long;
    double as_double;
    struct {
      char *data;
      size_t length;
    } as_string;
  } value;
  struct _cascada_token *prev, *next;
} cascada_token_t;

#endif // CASCADA_CASCADA_TOKEN_H
