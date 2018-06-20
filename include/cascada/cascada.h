// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_CASCADA_H
#define CASCADA_MINI_CASCADA_H

#include <stddef.h>
#include <stdint.h>
#include "ast.h"
#include "context.h"
#include "error.h"
#include "linked_list.h"
#include "object.h"
#include "parse.h"
#include "scan.h"

typedef void *(*CascadaAllocator)(size_t size);

typedef void (*CascadaDeallocator)(void *ptr);

cascada_t *cascada_new(CascadaAllocator allocator, CascadaDeallocator deallocator);

int cascada_allocate(cascada_t *context, size_t size, void **ptr);

int cascada_deallocate(cascada_t *context, void *ptr);

void cascada_destroy(cascada_t *context);

void cascada_enter_scope(cascada_t *context);

void cascada_exit_scope(cascada_t *context);

int cascada_execute(cascada_t *context, cascada_compilation_unit_t *unit, cascada_object_t *result,
                     cascada_linked_list_t *errors);

#endif //CASCADA_MINI_CASCADA_H
