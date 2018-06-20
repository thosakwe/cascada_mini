// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_AST_H
#define CASCADA_MINI_AST_H

#include <stdint.h>
#include "linked_list.h"
#include "scan.h"

struct _cascada_expr;
struct _cascada_parameter_list;

typedef struct
{
    cascada_linked_list_t *imports;
    cascada_linked_list_t *functions;
} cascada_compilation_unit_t;

typedef struct
{
    const char *name;
    cascada_linked_list_t *parameter_list;
    struct _cascada_expr *expr;
} cascada_function_t;

typedef enum {
    CASCADA_EXPR_COMMA,
    CASCADA_EXPR_ID,
    CASCADA_EXPR_DOUBLE,
    CASCADA_EXPR_INVOCATION,
    CASCADA_EXPR_INT,
    CASCADA_EXPR_LAMBDA,
    CASCADA_EXPR_LET,
    CASCADA_EXPR_NAMESPACED,
    CASCADA_EXPR_SUBSCRIPT,
    CASCADA_EXPR_TERNARY,
} cascada_expr_type;

typedef struct _cascada_expr {
    cascada_expr_type type;
    int64_t line;
    int64_t pos;
    int64_t text_length;
    const char *text;

    union {
        cascada_token_t *as_id;
        cascada_token_t *as_double;
        cascada_token_t *as_int;
        union {
            int64_t length;
            struct _cascada_expr *items;
        } as_comma;
        union {
            struct _cascada_expr *target;
            cascada_linked_list_t *arguments;
        } as_invocation;
        union {
            cascada_linked_list_t *parameter_list;
            struct _cascada_expr *expr;
        } as_lambda;
        union {
            cascada_token_t *id;
            struct _cascada_expr *value;
        } as_let;
        union {
            cascada_linked_list_t *namespaces;
            cascada_token_t *id;
        } as_namespaced;
        union {
            struct _cascada_expr *target;
            struct _cascada_expr *index;
        } as_subscript;
        union {
            struct _cascada_expr *condition;
            struct _cascada_expr *if_true;
            struct _cascada_expr *if_false;
        } as_ternary;
    };
} cascada_expr_t;

#endif //CASCADA_MINI_AST_H
