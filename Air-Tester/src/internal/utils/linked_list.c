#include <stdlib.h>
#include "linked_list.h"
#include "mem_utils.h"

linked_list_t *create_element(void *content) {
	linked_list_t *ret;

	ret = malloc_internal(sizeof(linked_list_t));
	if (!ret)
		return (NULL);
	ret->m_Content = content;
	ret->m_Next = NULL;
	return (ret);
}

linked_list_t *get_last_element(linked_list_t *linkedList) {
	linked_list_t *ret;

	ret = NULL;
	while (linkedList->m_Next)
		linkedList = linkedList->m_Next;
	return (linkedList);
}

linked_list_t *find_first_element(linked_list_t *list, bool_t (*equal)(const void *, const void *), const void *sample) {
	while (list) {
		if (equal(list->m_Content, sample))
			return (list);
		list = list->m_Next;
	}
	return (NULL);
}

void add_element_back(linked_list_t **list, linked_list_t *element) {
	if (!*list) {
		*list = element;
		return;
	}

	linked_list_t *temp;
	temp = (*list);
	while (temp->m_Next)
		temp = temp->m_Next;
	temp->m_Next = element;
}

void remove_elements(linked_list_t **list, bool_t (*equal)(const void *, const void *), const void *sample) {
	linked_list_t *previous;
	linked_list_t *current;

	previous = NULL;
	current = *list;
	while (current) {
		if (!equal(current->m_Content, sample)) {
			previous = current;
			current = current->m_Next;
			continue;
		}
		if (previous) {
			previous->m_Next = current->m_Next;
			free(current);
			current = previous->m_Next;
		} else {
			*list = current->m_Next;
			free(current);
			current = *list;
		}
	}
}

size_t get_size(const linked_list_t *list) {
	size_t size;

	size = 0;
	while (list) {
		size++;
		list = list->m_Next;
	}
	return (size);
}

void clear_list(linked_list_t **list) {
	linked_list_t *tmp;

	while (*list) {
		tmp = (*list)->m_Next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

void clear_list_full(linked_list_t **list, void (*clear)(void *)) {
	linked_list_t *tmp;

	while (*list) {
		tmp = (*list)->m_Next;
		clear((*list)->m_Content);
		free(*list);
		*list = tmp;
	}
}

void for_each_element(linked_list_t *list, void (*func)(const void *)) {
	while (list) {
		func(list->m_Content);
		list = list->m_Next;
	}
}