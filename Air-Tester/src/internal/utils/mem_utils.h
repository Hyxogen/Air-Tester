#ifndef MEM_UTILS_H
#define MEM_UTILS_H

#include <wchar.h>
#include "bool.h"

typedef struct malloc_info_s {
	void *m_Pointer;
	void *m_Caller;
	size_t m_Size;
}	malloc_info_t;

#ifdef AIR_TRACK_MEMORY
void *malloc(size_t size);
void free(void* ptr);
#endif
void *malloc_internal(size_t size);
void free_internal(void* ptr);

size_t get_unfreed_count();
size_t get_unfreed_bytes();
bool_t get_unfreed_bytes_internal(const void *malloc_info, void *int_pointer);

void clear_tracked_memory();

malloc_info_t *create_malloc_info(void *caller, void *pointer, size_t size);
void delete_malloc_info(void *malloc_info);
bool_t is_equal(const void *malloc_info, const void *malloc_pointer);

#endif //MEM_UTILS_H
