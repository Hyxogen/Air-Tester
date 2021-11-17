#ifndef MEM_UTILS_H
#define MEM_UTILS_H

#include <wchar.h>

#ifdef AIR_TRACK_MEMORY
void *malloc(size_t size);
void free(void* ptr);
#endif
void *malloc_internal(size_t size);
void free_internal(void* ptr);

size_t get_unfreed_count();

#endif //MEM_UTILS_H
