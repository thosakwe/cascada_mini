// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_PARSE_H
#define CASCADA_MINI_PARSE_H

#include "ast.h"
#include "linked_list.h"

void cascada_parse(cascada_t *context, cascada_compilation_unit_t *unit, cascada_linked_list_t *tokens,
                   cascada_linked_list_t *errors);

#endif //CASCADA_MINI_PARSE_H
