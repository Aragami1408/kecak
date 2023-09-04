#ifndef BASE_STRING_H
#define BASE_STRING_H

#include "base_types.h"
#include "base_defines.h"

typedef struct string8 string8;
typedef struct string8_node string8_node;
typedef struct string8_list string8_list;

struct string8 {
	u8 *str;
	u64 size;
};

struct string8_node {
	string8_node *next;
	string8 string;
};

struct string8list {
	string8_node *first;
	string8_node *last;
	u64 node_count;
	u64 total_size;
};




#endif
