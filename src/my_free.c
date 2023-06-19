#include "../include/my_malloc.h"

// Free memory in the memory block
void my_free(void *ptr)
{
    if (ptr == NULL) return;
    // determine the node by the incoming pointer
    node *new_node = (node *)((char *)ptr - NODE_SIZE);
    // declaring the node empty
    new_node->is_free = true;
    ptr = NULL;
    // concatenating consecutive empty blocks in the heap
    merge_consecutive_free_nodes();
}
