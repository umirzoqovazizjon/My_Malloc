# Welcome to My Malloc
***

## Task
In this project, i'm implemented own version of memory management functions `my_malloc`, `my_calloc`, `my_realloc`, and `my_free` using a linked list data structure to manage the heap memory. Here's a high-level overview of each function and some tips for implementing them:

## Description
- `data structure`:
    - the stack is always added in the form of a linked list from the end of the memory block to the beginning.
    - stack nodes are always sorted in descending order of size
    - memory blocks are always added from beginning to end in the form of a linked list

- `my_malloc(size_t size)`:
    - If it is being calling for the first time, 2KB of memory space will be allocated with mmap and placed in the linked list as first node, and from the very beginning the size part will be divided into a separate node with size, and the remaining excess part will be made into a separate node to the linked list.
    - Otherwise, search the linked list for a free node that can accommodate the requested size.
    - If a suitable node is found, split it if necessary, create a new node from the remaining size and place it in the next node of the this linked list.
    - If no suitable node is found, return NULL.
    - Finally return a pointer to the allocated memory.

- `my_calloc(size_t nmemb, size_t size)`:
    - Calculate the total size by multiplying `nitems` and `size`.
    - Call `my_malloc` with the total size.
    - Zero out the allocated memory.
    - Return a pointer to the allocated memory.

- `my_realloc(void *ptr, size_t size)`:
    - If `ptr` is NULL, call `my_malloc` with the requested size.
    - If `size` is 0 and `ptr` is not NULL, call `my_free` for the `ptr` and return NULL.
    - If the node associated with `ptr` can be resized in-place, do so and return the same `ptr` with resized size and add the heap reamining block memory as free.
    - If the node cannot be resized, allocate a new node with `my_malloc`, copy the data from the old node to the new node, and free the old node using `my_free`. Return a pointer to the new node.

- `my_free(void *ptr)`:
    - Free the memory node pointed to by `ptr`.
    - If `ptr` is NULL, do nothing.
    - Locate the node's metadata in the linked list.
    - Mark the node as free and try to merge it with its neighbors if they are also free.
    - Update the linked list accordingly.

## Installation
If you can compile on your PC, you can certainly download the project and try it yourself

## Usage
As always, compile with using a `Makefile`. and run the `my_malloc`
```
make
./my_malloc
```

### The Core Team
`umirzoqo_a`

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
