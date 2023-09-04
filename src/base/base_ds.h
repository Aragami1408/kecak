#ifndef BASE_DS_H
#define BASE_DS_H

#include "base_types.h"
#include <string.h>
#include <stdlib.h>

#define DoubleCapacity(x) ((x) <= 0 ? 8 : x * 2)
#define DoubleCapacityBigInit(x) ((x) <= 0 ? 64 : x * 2)

// NOTE(higanbana): Vector a.k.a Dynamic Array
#define vector(type) type##_vector

#define vector_add(type, vector, data) type##_vector##_add(vector, data)
#define vector_add_at(type, vector, data, idx) type##_vector##_add_at(vector, data, idx)
#define vector_reserve(type, vector, count) type##_vector##_reserve(vector, count)
#define vector_remove(type, vector, idx) type##_vector##_remove(vector, idx)
#define vector_free(type, vector) type##_vector##_free(vector)

#define VECTOR_PROTOTYPE(Data)\
	typedef struct Data##_vector{\
		u32 cap;\
		u32 len;\
		Data *elems;\
	} Data##_vector;\
	void Data##_vector##_add(Data##_vector* vector, Data data);\
	void Data##_vector##_add_at(Data##_vector* vector, Data data, u32 index);\
	void Data##_vector##_reserve(Data##_vector* vector, u32 count);\
	Data Data##_vector##_remove(Data##_vector* vector, int idx);\
	void Data##_vector##_free(Data##_vector *vector);

#define VECTOR_IMPL(Data)\
	void Data##_vector##_add(Data##_vector* vector, Data data) {\
		if(vector->len + 1 > vector->cap) {\
			void *prev = vector->elems;\
			u32 new_cap = DoubleCapacity(vector->cap);\
			vector->elems = calloc(new_cap, sizeof(Data));\
			memmove(vector->elems, prev, vector->len * sizeof(Data));\
			vector->cap = new_cap;\
			free(prev);\
		}\
		vector->elems[vector->len++] = data;\
	}\
	void Data##_vector##_add_at(Data##_vector* vector, Data data, u32 idx) {\
		if(vector->len + 1 > vector->cap) {\
			void *prev = vector->elems;\
			u32 new_cap = DoubleCapacity(vector->cap);\
			vector->elems = calloc(new_cap, sizeof(Data));\
			memmove(vector->elems, prev, vector->len * sizeof(Data));\
			vector->cap = new_cap;\
			free(prev);\
		}\
		memmove(vector->elems + idx + 1, vector->elems + idx, sizeof(Data) * (vector->len - idx));\
		vector->elems[idx] = data;\
		vector->len++;\
	}\
	void Data##_vector##_reserve(Data##_vector* vector, u32 count) {\
		void* prev = vector->elems;\
		u32 new_cap = count;\
		vector->elems = calloc(new_cap, sizeof(Data));\
		memmove(vector->elems, prev, vector->len * sizeof(Data));\
		vector->cap = new_cap;\
		if(prev) free(prev);\
	}\
	Data Data##_vector##_remove(Data##_vector* vector, int idx) {\
		if(idx >= vector->len || idx < 0) return (Data){0};\
		Data value = vector->elems[idx];\
		if(idx == vector->len - 1) {\
			vector->len--;\
			return value;\
		}\
		Data* from = vector->elems + idx + 1;\
		Data* to = vector->elems + idx;\
		memmove(to, from, sizeof(Data) * (vector->len - idx - 1));\
		vector->len--;\
		return value;\
	}\
	void Data##_vector##_free(Data##_vector *vector) {\
		vector->cap = 0;\
		vector->len = 0;\
		free(vector->elems);\
	}\

// NOTE(higanbana): Hashtable
#define HASHTABLE_CAPACITY 

#endif
