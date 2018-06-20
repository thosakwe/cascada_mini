// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_SCAN_H
#define CASCADA_MINI_SCAN_H

#include <stdint.h>
#include "linked_list.h"

typedef enum
{
    CASCADA_TOKEN_ARROW,
    CASCADA_TOKEN_BRACE_L,
    CASCADA_TOKEN_BRACE_R,
    CASCADA_TOKEN_BRACKET_L,
    CASCADA_TOKEN_BRACKET_R,
    CASCADA_TOKEN_COMMA,
    CASCADA_TOKEN_DOUBLE_COLON,
    CASCADA_TOKEN_EQUALS,
    CASCADA_TOKEN_DEF,
    CASCADA_TOKEN_IMPORT,
    CASCADA_TOKEN_LET,
    CASCADA_TOKEN_ID,
    CASCADA_TOKEN_NUMBER,
} cascada_token_type;

typedef struct
{
    cascada_token_type type;
    const char *text;
    int64_t line;
    int64_t pos;
    int64_t text_length;
} cascada_token_t;

void cascada_scan(cascada_t *context, const char *text, cascada_linked_list_t *tokens, cascada_linked_list_t *errors);

#endif //CASCADA_MINI_SCAN_H
