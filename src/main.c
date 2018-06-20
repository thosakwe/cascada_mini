// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cascada/cascada.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    cascada_object_t result;
    const char *text = "foo";
    cascada_t *ctx = cascada_new(malloc, free);
    cascada_linked_list_t *errors = cascada_linked_list_new(ctx);
    cascada_linked_list_t *tokens = cascada_linked_list_new(ctx);
    cascada_compilation_unit_t *unit;
    cascada_allocate(ctx, sizeof(cascada_compilation_unit_t), (void **) &unit);
    cascada_scan(ctx, text, tokens, errors);
    cascada_parse(ctx, unit, tokens, errors);
    return cascada_execute(ctx, unit, &result, errors);
}