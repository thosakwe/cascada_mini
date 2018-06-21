// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cascada/cascada.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    cascada_t *ctx = NULL;
    cascada_linked_list_t *list = NULL;
    cascada_new(malloc, free, &ctx);
    cascada_linked_list_new(ctx, 255, &list);
    if (ctx == NULL || list == NULL) return 1;

    uint64_t len = 12345;
    cascada_linked_list_length(list, &len);
    int result = cascada_linked_list_add(list, "Hello");
    printf("Hey: %d\n", result);
    cascada_linked_list_add(list, "world");
    printf("Length: %llu\n", len);
    return 0;
}