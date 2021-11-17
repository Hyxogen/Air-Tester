#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "bool.h"

typedef struct linked_list_s {
	void *m_Content;
	struct linked_list_s *m_Next;
} linked_list_t;

linked_list_t *create_element(void *content);

linked_list_t *get_last_element(linked_list_t *linkedList);

linked_list_t *find_first_element(linked_list_t *list, bool_t (*equal)(const void *, const void *), const void *sample);

void add_back_element(linked_list_t **list, linked_list_t *element);

void remove_elements(linked_list_t **list, bool_t (*equal)(const void *, const void *), const void *sample);

size_t get_size(const linked_list_t *list);

void clear_list(linked_list_t **list);

void clear_list_full(linked_list_t **list, void (*clear)(void *));

void for_each_element(linked_list_t *list, void (*func)(const void *));

#endif //LINKED_LIST_H
