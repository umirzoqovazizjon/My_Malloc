#include "../include/my_malloc.h"

// Allocate memory and set it to zero using the memory block

void *my_calloc(size_t nitems, size_t size)
{
    // calculate the total number of bytes needed
    // for all the nitems in the size
    size_t total_size = nitems * size;
    // calling my_malloc for total bytes
    void *ptr = my_malloc(total_size);
    // setting all values in the memory block
    // to 0 if my_malloc worked correctly
    if (ptr != NULL) my_memset(ptr, 0, total_size);
    return ptr;
}
