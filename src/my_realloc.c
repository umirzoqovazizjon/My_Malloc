#include "../include/my_malloc.h"

// Reallocate memory using the memory block
void *my_realloc(void *ptr, size_t size)
{
    // calling to my_malloc if the incoming
    // memory pointer does not exist
    if (ptr == NULL) return my_malloc(size);

    // if the amount of memory to realloc is 0, send it to my_free
    if (size == 0)
    {
        my_free(ptr);
        return NULL;
    }

    // if realloc is requested for small memory,
    // replace a block on the heap by reducing
    // the memory size enough and add the excess
    // to the heap as an empty block
    node *new_node = (node *)((char *)ptr - NODE_SIZE);
    size_t total_size = size + NODE_SIZE;
    if (new_node->size >= total_size)
    {
        void *split_ptr = (char *)new_node + total_size;
        size_t split_size = new_node->size - total_size;
        node *split_node = create_node(split_ptr, split_size, true);
        insert_node(split_node);
        new_node->size = size;
        return ptr;
    }

    // if more size is requested, send the
    // new memory size to my_malloc and sending 
    // to my_free to free the previous block of memory
    void *new_ptr = my_malloc(size);
    if (new_ptr == NULL) return NULL;
    memcpy(new_ptr, ptr, new_node->size);
    my_free(ptr);

    // return a block pointer that
    // fits perfectly the requested size
    return new_ptr;
}
