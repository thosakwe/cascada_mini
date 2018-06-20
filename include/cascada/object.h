// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_OBJECT_H
#define CASCADA_MINI_OBJECT_H

#include <stdint.h>

struct _casacada_object;

typedef struct _cascada_object *(*CascadaStreamFunction)(struct _cascada *context, void *state);

typedef enum
{
    CASCADA_OBJECT_BYTES,
    CASCADA_OBJECT_DOUBLE,
    CASCADA_OBJECT_INT,
    CASCADA_OBJECT_LIST,
    CASCADA_OBJECT_STREAM,
    CASCADA_OBJECT_STRING,
} cascada_object_type;

typedef struct _cascada_object
{
    cascada_object_type type;
    union
    {
        double as_double;
        int64_t as_int;
        const char *as_string;
        union
        {
            struct _cascada_object *items;
            int64_t length;
        } as_array;
        union {
            const uint8_t *data;
            int64_t length;
        } as_bytes;
        union
        {
            CascadaStreamFunction function;
            void *state;
        } as_stream;
    };
} cascada_object_t;

#endif //CASCADA_MINI_OBJECT_H
