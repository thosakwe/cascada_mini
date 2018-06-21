// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <stddef.h>
#include <cascada/cascada.h>

struct _cascada_linked_list_leaf
{
    uint64_t length;
    void **items;
    struct _cascada_linked_list_leaf *next;
};

struct _cascada_linked_list
{
    cascada_t *context;
    uint64_t length;
    uint64_t leaf_size;
    struct _cascada_linked_list_leaf *leaves;
};

void cascada_linked_list_new(cascada_t *context, uint64_t leaf_size, cascada_linked_list_t **ptr) {
    if (context == NULL) return;
    cascada_allocate(context, sizeof(cascada_linked_list_t), (void **) ptr);
    (*ptr)->context = context;
    (*ptr)->length = 0;
    (*ptr)->leaf_size = leaf_size;
    (*ptr)->leaves = NULL;
}

int cascada_linked_list_add(cascada_linked_list_t *list, void *data) {
    if (list == NULL) return 1;
    struct _cascada_linked_list_leaf *leaf = list->leaves;
    uint64_t total = 0, leaf_index = 0;

    while (leaf != NULL && leaf->next != NULL) {
        total += leaf->length;
        leaf = leaf->next;
        leaf_index++;
    }

    if (leaf == NULL) {
        // Create the first leaf for the list.
        struct _cascada_linked_list_leaf *new_leaf;

        if (cascada_allocate(list->context, sizeof(leaf), (void **) &new_leaf) == 0) {
            if (cascada_allocate(list->context, sizeof(void *) * list->leaf_size, (void **) &new_leaf->items) == 0) {
                new_leaf->length = 1;
                new_leaf->next = NULL;
                new_leaf->items[0] = data;
                list->leaves = new_leaf;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    } else if (total == list->length) {
        // Create a new leaf.
        struct _cascada_linked_list_leaf *new_leaf;

        if (cascada_allocate(list->context, sizeof(leaf), (void **) &new_leaf) == 0) {
            if (cascada_allocate(list->context, sizeof(void *) * list->leaf_size, (void **) &new_leaf->items) == 0) {
                new_leaf->length = 1;
                new_leaf->next = NULL;
                new_leaf->items[0] = data;
                leaf->next = new_leaf;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    } else {
        // Append to an existing leaf.
        uint64_t local_index = (leaf_index * list->leaf_size) - list->length++;
        leaf->items[local_index] = data;
        return 0;
    }
}

void cascada_linked_list_get(cascada_linked_list_t *list, uint64_t index, void **ptr) {
    if (list == NULL || index >= list->length) return;

    // Find the corresponding leaf...
    uint64_t total = 0, leaf_index = 0;
    struct _cascada_linked_list_leaf *leaf = list->leaves;

    while (total < index) {
        total += leaf->length;
        leaf = leaf->next;
        leaf_index++;
    }

    uint64_t local_index = index - (leaf_index * list->leaf_size);
    *ptr = leaf->items[local_index];
}

void cascada_linked_list_length(cascada_linked_list_t *list, uint64_t *length) {
    if (list != NULL) *length = list->length;
}

void cascada_linked_list_destroy(cascada_linked_list_t *list) {
    if (list != NULL) cascada_deallocate(list->context, list);
}
