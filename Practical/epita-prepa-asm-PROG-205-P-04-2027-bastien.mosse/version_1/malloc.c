#include <unistd.h>
#include <string.h>
#include <err.h>
#include "malloc.h"

const size_t HSIZE = sizeof(header);
const size_t YES = 1;
const size_t NO = 0;

void* get_data(header* h)
{
    return (void*)(h + 1);
}

header* get_header_from_data(void* data)
{
    return (header*)((char*)data - HSIZE);
}

size_t get_total(header* h)
{
    size_t id_next  = (size_t)h->next - (size_t)get_sentinel();
    size_t id_chunk = (size_t)h - (size_t)get_sentinel();
    
    return id_next - id_chunk - HSIZE;
}

header* get_sentinel()
{
    // TODO:
    // - Define and initialize a static variable to NULL.
    // - If this variable is NULL,
    //   it is the first call to the function.
    //   So, set it to the initial address of the heap
    //   (the initial value of the program break).
    // - If this variable is not NULL,
    //   it contains the initial value of the heap,
    //   which is also the address of the sentinel.
    //   So, just return it.

    static header* sentinel = NULL;
    
    if (sentinel == NULL)
    {
        sentinel = (header*)sbrk(HSIZE);
    }

    return sentinel;

}

void init_heap()
{
    // TODO:
    // - Get the address of the sentinel
    // - Allocate the memory for the sentinel
    //   (obviously do not use malloc).
    // - Initialize the sentinel with the following values:
    //   - prev = NULL
    //   - next = current program break
    //   - size = 0
    //   - free = No

    header* sentinel = get_sentinel();

    sentinel->prev = NULL;
    sentinel->next = (header*)sbrk(0);
    sentinel->size = 0;
    sentinel->free = NO;

}

header* expand_heap(header* last_header, size_t size)
{
    // TODO:
    // - Get the current program break.
    // - Expand the heap
    //   (Allocate the memory for the
    //    new header and the data section.)
    //   If an error occurs, return NULL.
    // - Initialize the next and prev fields of the new header.
    // - Update the previous header.
    // - Return the new header.

    size_t total_size = size + HSIZE;

    if (total_size % 8 != 0)
        total_size += 8 - (total_size % 8);

    void* current_break = sbrk(total_size);

    header* new_header = current_break;
    new_header->prev = last_header;
    last_header->next = new_header;
    new_header->next = (header*)sbrk(0);    

    new_header->free = YES;
    new_header->size = size;
    
    return new_header;
}

header* find_free_chunk(size_t size)
{
    // TODO:
    // - Iterate over the chunks and return
    //   the first chunk (the address of the header)
    //   that is free and large enough to store "size" bytes
    //   (compare the total number of bytes with "size").
    // - If no chunk can be found,
    //   return the address of the last header.

    header* this_header = get_sentinel();
    header* prog_break = (header*)sbrk(0);

    while (this_header->next != prog_break) {
        if (this_header->free == YES && get_total(this_header) >= size) {
            return this_header;
        }
        this_header = this_header->next;
    }

    return this_header;
}

void* my_malloc(size_t size)
{
    // TODO:
    // - If "size" is 0, return NULL.
    // - "size" must be a multiple of eight.
    //   If it is not, work out the next multiple of eight
    //   and use this value to find a free chunk large enough.
    // - Get the first free chunk large enough
    //   (or the last chunk).
    // - If no chunk can be found, expand the heap.
    // - Do not forget to update the "size" and the "free" fields.
    //   Be careful, the "size" field of the header
    //   must be initialized with the "size" parameter
    //   (not with the next multiple of eight).
    // - Return the address of the data section.

    if (size == 0)
        return NULL;

    size_t size8 = size;
    if (size % 8 != 0)
        size8 += 8 - size%8;

    header* chunk = find_free_chunk(size8);

    if (chunk->free == NO || get_total(chunk) < size8)
        chunk = expand_heap(chunk, size8);
        
    chunk->size = size;
    chunk->free = NO;

    return get_data(chunk);
}

void* my_calloc(size_t nmemb, size_t size)
{
    // TODO:
    // - Work out the size in bytes.
    //   To do so, you have to multiply "nmemb" and "size".
    //   Use __builtin_mul_overflow() to detect an overflow.
    //   If an overflow occurs, return NULL.
    // - Call my_malloc() and return NULL if an error occurs.
    // - Fill the memory space with zeros (use memset(3)).
    // - Return the address of the data section.

    size_t total_size;

    if (__builtin_mul_overflow(nmemb, size, &total_size))
        return NULL;

    void* p = my_malloc(total_size);

    if (p == NULL)
        return NULL;

    memset(p, 0, total_size);

    return p;
}

void my_free(void* ptr)
{
    // TODO:
    // - If "ptr" is NULL, no operation is performed.
    // - Get the header.
    // - Mark the chunk as free.

    if (ptr != NULL) {
        header* h = get_header_from_data(ptr);
        h->free = YES;

        /*
        h->next->prev = h->prev;
        h->prev->next = h->next;
        */
    }
}

void* my_realloc(void* ptr, size_t size)
{
    // TODO:
    // - If "ptr" is NULL, realloc() is equivalent to malloc().
    // - If "size" is 0 (and "ptr" is not NULL),
    //   realloc() is equivalent to free() and return NULL.
    // - Get the header.
    // - If this chunk is large enough, just update the size.
    // - Otherwise:
    //   - Allocate a new memory space with my_malloc()
    //     (return NULL if an error occurs).
    //   - Copy the bytes from the previous memory
    //     space to the new one (use memcpy(3)).
    //   - Free the previous memory space.
    //   - Return the address of the new memory space.

    if (ptr == NULL)
        return my_malloc(size);
    
    if (size == 0) {
        my_free(ptr);
        return NULL;
    }
    
    // (p1, 7)
    
    header* h = get_header_from_data(ptr);

    if (get_total(h) >= size) {
        h->size = size;
        return ptr;
    } else {
        void* p = my_malloc(size);

        if (p == NULL)
            return NULL;

        size_t cp_size = (size < h->size) ? size : h->size;
        memcpy(p, ptr, cp_size);

        // Free the previous memory space
        my_free(ptr);

        return p;
    }
}