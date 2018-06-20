// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef CASCADA_MINI_ERROR_H
#define CASCADA_MINI_ERROR_H

#include <stdint.h>

typedef enum {
    CASCADA_SEVERITY_ERROR,
    CASCADA_SEVERITY_WARNING,
    CASCADA_SEVERITY_INFO,
    CASCADA_SEVERITY_HINT,
} cascada_error_severity;

typedef struct {
    cascada_error_severity severity;
    const char *message;
    int64_t line;
    int64_t pos;
} cascada_error_t;

#endif //CASCADA_MINI_ERROR_H
