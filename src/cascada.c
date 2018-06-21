// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cascada/cascada.h>

struct _cascada
{
    CascadaAllocator allocator;
    CascadaDeallocator deallocator;
};

void cascada_new(CascadaAllocator allocator, CascadaDeallocator deallocator, cascada_t **ptr) {
    *ptr = (cascada_t *) allocator(sizeof(cascada_t));
    if (*ptr == NULL) return;
    (*ptr)->allocator = allocator;
    (*ptr)->deallocator = deallocator;
}

// TODO: Reference tracking
int cascada_allocate(cascada_t *context, size_t size, void **ptr) {
    if (context == NULL) return 1;
    *ptr = context->allocator(size);
    if (*ptr == NULL) return 1;
    return 0;
}

int cascada_deallocate(cascada_t *context, void *ptr) {
    if (context == NULL) return 1;
    context->deallocator(ptr);
    return 0;
}