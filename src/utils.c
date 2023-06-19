#include "../include/my_malloc.h"

// creating a new block of memory node
node *create_node(void *ptr, size_t size, bool is_free)
{
    node *new_node = (node *)ptr;
    new_node->size = size;
    new_node->is_free = is_free;
    new_node->next = NULL;
    new_node->ptr_for_user = ptr + NODE_SIZE;
    return new_node;
}

// Print information about memory block nodes
void print_nodes()
{
    node *temp = heap;
    printf("▼▼▼▼▼▼ MEMORY METADATA ▼▼▼▼▼▼\n");
    while (temp != NULL)
    {
        printf("ptr_node : %p\n", temp);
        printf("ptr_for_user : %p\n", temp->ptr_for_user);
        printf("is_free : %s\n", (temp->is_free == 1) ? "YES" : "NO");
        printf("size : %ld\n", temp->size);
        printf("next ptr : %p\n", temp->next);
        temp = temp->next;
        if (temp != NULL) printf("\n");
    }
    printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
}

// concatenate consecutive blocks of free memory
void merge_consecutive_free_nodes()
{
    node *prev = NULL;
    node *current = heap;
    while (current != NULL)
    {
        if (current->is_free && prev != NULL && prev->is_free)
        {
            prev->size += current->size + NODE_SIZE;
            prev->next = current->next;
        }
        else prev = current;
        current = current->next;
    }
}

// placing the memory block in its place in ascending order
void insert_node(node *new_node)
{
    if (heap == NULL)
    {
        heap = new_node;
        return;
    }

    if (heap->next == NULL)
    {
        heap->next = new_node;
        return;
    }
    node *current = heap;
    node *prev = NULL;
    while (current != NULL && new_node > current)
    {
        prev = current;
        current = current->next;
    }
    new_node->next = current;
    prev->next = new_node;
}

// find a block that fits the desired size
node *find_free_node(size_t size)
{
    node *current = heap;
    while (current != NULL)
    {
        if (current->is_free && current->size >= size + NODE_SIZE)
            return current;
        current = current->next;
    }
    return NULL;
}

void *my_memset(void *src, int c, size_t n)
{
    unsigned char *p = src;
    for (size_t i = 0; i < n; i++)
        p[i] = (unsigned char) c;
    return src;
}