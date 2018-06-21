// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_LINKED_LIST_H
#define CASCADA_MINI_LINKED_LIST_H

#include <cascada/context.h>
#include <stdint.h>

struct _cascada_linked_list;
typedef struct _cascada_linked_list cascada_linked_list_t;

void cascada_linked_list_new(cascada_t *context, uint64_t leaf_size, cascada_linked_list_t **ptr);

int cascada_linked_list_add(cascada_linked_list_t *list, void *data);

void cascada_linked_list_get(cascada_linked_list_t *list, uint64_t index, void **ptr);

void cascada_linked_list_length(cascada_linked_list_t *list, uint64_t *length);

void cascada_linked_list_destroy(cascada_linked_list_t *list);

#endif //CASCADA_MINI_LINKED_LIST_H
