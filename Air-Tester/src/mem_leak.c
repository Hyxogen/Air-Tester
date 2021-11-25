#include "mem_leak.h"
#include <stdlib.h>
#include <stdio.h>

void function_that_leaks() {
	char* v = malloc(5);
//	free(v);
	(void)v;
}