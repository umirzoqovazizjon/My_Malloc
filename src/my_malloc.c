#include "../include/my_malloc.h"

node *heap = NULL;

// Allocate memory using the memory block
void *my_malloc(size_t size)
{
    // return NULL if a non-negative block of memory was requested
    if (size <= 0) return NULL;
    // calculate how many bytes are needed for a block of memory
    size_t total_size = size + NODE_SIZE;
    // search the heap for a block of memory that fits the requested size
    node *new_node = find_free_node(size);
    // if the heap exists and not enough memory is found, then we are out of memory
    if (new_node == NULL && heap != NULL) return NULL;
    // if heap is NULL, mmap for BIG chunk
    if (new_node == NULL)
    {
        void *ptr = mmap(NULL, MAX_SIZE, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ptr == MAP_FAILED) return NULL;
        // request for a new BIG block of memory
        new_node = create_node(ptr, MAX_SIZE, true);
        // inserting a BIG block to the heap
        insert_node(new_node);
    }
    // if the requested size is smaller than the block found,
    // then allocate enough of it separately and put the rest
    // back on the heap as an empty block
    if (new_node->size > total_size + NODE_SIZE)
    {
        void *split_ptr = (char *)new_node + total_size;
        size_t split_size = new_node->size - total_size;
        node *split_node = create_node(split_ptr, split_size, true);
        insert_node(split_node);
    }
    new_node->size = size;
    new_node->is_free = false;
    return (char *)new_node->ptr_for_user;
}