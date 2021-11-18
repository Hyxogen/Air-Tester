#include <dlfcn.h>
#include "mem_utils.h"
#include "linked_list.h"
#include "assert.h"
#include <stdio.h>

static linked_list_t *g_linked_list = NULL;

#ifdef AIR_TRACK_MEMORY
void *malloc(size_t size) {
	void *ret;
	linked_list_t *link;
	malloc_info_t *malloc_info;

	ret = malloc_internal(size);
	ASSERT(ret);
	malloc_info = create_malloc_info(__builtin_return_address(0), ret, size);
	link = create_element(malloc_info);
	ASSERT(link);
	add_element_back(&g_linked_list, link);
	return (ret);
}
void free(void* ptr) {
	remove_elements(&g_linked_list, is_equal, ptr);
	free_internal(ptr);
}
#endif

void *malloc_internal(size_t size) {
	static void* (*libc_malloc)(size_t) = NULL;
	if (!libc_malloc)
		libc_malloc = dlsym(RTLD_NEXT, "malloc");
	return (libc_malloc(size));
}

void free_internal(void* ptr) {
	static void (*libc_free)(void*) = NULL;
	if (!libc_free)
		libc_free = dlsym(RTLD_NEXT, "free");
	libc_free(ptr);
}

size_t get_unfreed_count() {
	return get_size(g_linked_list);
}

size_t get_unfreed_bytes() {
	int bytes;

	bytes = 0;
	for_each_element_data(g_linked_list, get_unfreed_bytes_internal, &bytes);
	return (bytes);
}

bool_t get_unfreed_bytes_internal(const void *malloc_info, void *int_pointer) {
	int *bytes;

	bytes = int_pointer;
	*bytes += ((malloc_info_t*) malloc_info)->m_Size;
	return (FALSE);
}



void clear_tracked_memory() {
	clear_list(&g_linked_list);
}

malloc_info_t *create_malloc_info(void *caller, void *pointer, size_t size) {
	malloc_info_t *ret;

	ret = malloc_internal(sizeof(malloc_info_t));
	ASSERT(ret);
	ret->m_Caller = caller;
	ret->m_Pointer = pointer;
	ret->m_Size = size;
	return (ret);
}

void delete_malloc_info(void *malloc_info) {
	free_internal(malloc_info);
}

bool_t is_equal(const void *malloc_info, const void *malloc_pointer) {
	const malloc_info_t *info;

	info = malloc_info;
	return (info->m_Pointer == malloc_pointer);
}