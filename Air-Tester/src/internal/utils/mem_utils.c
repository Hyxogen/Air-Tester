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

	ret = malloc_internal(size);
	ASSERT(ret);
	link = create_element(ret);
	ASSERT(link);
	add_element_back(&g_linked_list, link);
	return (ret);
}
void free(void* ptr) {
	free_internal(ptr);
}
#endif

void *malloc_internal(size_t size) {

	static void* (*libc_malloc)(size_t) = NULL;
	if (!libc_malloc)
		libc_malloc = dlsym(RTLD_NEXT, "malloc");
	return libc_malloc(size);
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

void clear_tracked_memory() {
	clear_list(&g_linked_list);
}