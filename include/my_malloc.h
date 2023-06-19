#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_SIZE 2048

typedef struct node_struct
{
    struct node_struct *next;
    size_t size;
    bool is_free;
    void *ptr_for_user;
} node;

#define NODE_SIZE sizeof(node)

extern node *heap;

#endif /* STRUCTURES_H */

#ifndef UTILS_H
#define UTILS_H

node *create_node(void *, size_t, bool);
void print_nodes();
void merge_consecutive_free_nodes();
void insert_node(node *);
node *find_free_node(size_t);
void *my_memset(void *, int, size_t);

#endif /* UTILS_H */

#ifndef MY_CALLOC_H
#define MY_CALLOC_H

void *my_calloc(size_t, size_t);

#endif /* MY_CALLOC_H */

#ifndef MY_FREE_H
#define MY_FREE_H

void my_free(void *);

#endif /* MY_FREE_H */

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

void *my_malloc(size_t);

#endif /* MY_MALLOC_H */

#ifndef MY_REALLOC_H
#define MY_REALLOC_H

void *my_realloc(void *, size_t);

#endif /* MY_REALLOC_H */
