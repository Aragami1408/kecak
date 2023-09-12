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

#define HASHTABLE_MAXLOAD 0.75

#define hash_table_key(key, value) key##_##value##_hash_table_key
#define hash_table_value(key, value) key##_##value##_hash_table_value
#define hash_table_entry(key, value) key##_##value##_hash_table_entry
#define hash_table(key, value) key##_##value##_hash_table

#define hash_table_init(key_t, value_t, table) key_t##_##value_t##_hash_table_init(table)
#define hash_table_set(key_t, value_t, table, key, val) key_t##_##value_t##_hash_table_set(table, key, val)
#define hash_table_get(key_t, value_t, table, key, val) key_t##_##value_t##_hash_table_get(table, key, val)
#define hash_table_get_ptr(key_t, value_t, table, key, val) key_t##_##value_t##_hash_table_get_ptr(table, key, val)
#define hash_table_get_ptr_guarantee(key_t, value_t, table, key, val)\
key_t##_##value_t##_hash_table_get_ptr_guarantee(table, key, val)
#define hash_table_del(key_t, value_t, table, key) key_t##_##value_t##_hash_table_del(table, key)
#define hash_table_add_all(key_t, value_t, to, from) key_t##_##value_t##_hash_table_del(to, from)
#define hash_table_free(key_t, value_t, table) key_t##_##value_t##_hash_table_free(table)

#define HASHTABLE_PROTOTYPE(Key, Value)\
typedef Key Key##_##Value##_hash_table_key;\
typedef Value Key##_##Value##_hash_table_value;\
typedef struct Key##_##Value##_hash_table_entry {\
Key##_##Value##_hash_table_key key;\
Key##_##Value##_hash_table_value value;\
} Key##_##Value##_hash_table_entry;\
typedef struct Key##_##Value##_hash_table {\
u64 cap;\
u64 len;\
Key##_##Value##_hash_table_entry* elems;\
} Key##_##Value##_hash_table;\
void Key##_##Value##_hash_table_init(Key##_##Value##_hash_table* table);\
void Key##_##Value##_hash_table_free(Key##_##Value##_hash_table* table);\
b8 Key##_##Value##_hash_table_get(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value* val);\
b8 Key##_##Value##_hash_table_get_ptr(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value** val);\
void Key##_##Value##_hash_table_get_ptr_guarantee(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value** val);\
b8 Key##_##Value##_hash_table_set(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value  val);\
b8 Key##_##Value##_hash_table_del(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key);\
void Key##_##Value##_hash_table_add_all(Key##_##Value##_hash_table* to, Key##_##Value##_hash_table* from);

#define HASHTABLE_IMPL(Key, Value, KeyIsNull, KeyIsEqual, HashKey, Tombstone, ValIsNull, ValIsTombstone)\
static const Key##_##Value##_hash_table_value Key##_##Value##_hash_table_tombstone = Tombstone;\
void Key##_##Value##_hash_table_init(Key##_##Value##_hash_table* table) {\
	table->cap = 0;\
	table->len = 0;\
	table->elems = nullptr;\
}\
void Key##_##Value##_hash_table_free(Key##_##Value##_hash_table* table) {\
	free(table->elems);\
	table->cap = 0;\
	table->len = 0;\
	table->elems = nullptr;\
}\
static Key##_##Value##_hash_table_entry* Key##_##Value##_hash_table_find_entry(Key##_##Value##_hash_table_entry* entries, u64 cap,  Key##_##Value##_hash_table_key key) {\
u64 index = HashKey(key) % cap;\
Key##_##Value##_hash_table_entry* tombstone = nullptr;\
while (true) {\
Key##_##Value##_hash_table_entry* entry = &entries[index];\
if (KeyIsNull(entry->key)) {\
	if (ValIsNull(entry->value))\
		return tombstone != nullptr ? tombstone : entry;\
	else {\
		if (tombstone == nullptr) tombstone = entry;\
	}\
} else if (KeyIsEqual(entry->key, key))\
	return entry;\
index = (index + 1) % cap;\
}\
}\
static void Key##_##Value##_hash_table_adjust_cap(Key##_##Value##_hash_table* table, u64 cap) {\
Key##_##Value##_hash_table_entry* entries = calloc(cap, sizeof(Key##_##Value##_hash_table_entry));\
table->len = 0;\
for (u64 i = 0; i < table->cap; i++) {\
	 Key##_##Value##_hash_table_entry* curr = &table->elems[i];\
	 if (KeyIsNull(curr->key)) continue;\
	 Key##_##Value##_hash_table_entry* dest = Key##_##Value##_hash_table_find_entry(entries, cap, curr->key);\
	 dest->key = curr->key;\
	 dest->value = curr->value;\
	 table->len++;\
 }\
	 free(table->elems);\
	 table->cap = cap;\
	 table->elems = entries;\
 }\
	 b8 Key##_##Value##_hash_table_set(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value  val) {\
	 if (table->len + 1 > table->cap * HASHTABLE_MAXLOAD) {\
	 u32 cap = DoubleCapacity(table->cap);\
	 Key##_##Value##_hash_table_adjust_cap(table, cap);\
 }\
	 Key##_##Value##_hash_table_entry* entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
	 b8 is_new_key = KeyIsNull(entry->key);\
	 if (is_new_key && ValIsNull(entry->value)) table->len++;\
	 entry->key = key;\
	 entry->value = val;\
	 return is_new_key;\
 }\
	 void Key##_##Value##_hash_table_add_all(Key##_##Value##_hash_table* to, Key##_##Value##_hash_table* from) {\
	 for (u32 i = 0; i < from->cap; i++) {\
	   Key##_##Value##_hash_table_entry* e = &from->elems[i];\
	   if (KeyIsNull(e->key)) continue;\
	   Key##_##Value##_hash_table_set(to, e->key, e->value);\
   }\
   }\
	   b8 Key##_##Value##_hash_table_get(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value* val) {\
	   if (table->len == 0) return false;\
	   Key##_##Value##_hash_table_entry* entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
	   if (KeyIsNull(entry->key)) return false;\
	   if (val != nullptr) *val = entry->value;\
	   return true;\
   }\
	   b8 Key##_##Value##_hash_table_get_ptr(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value** val) {\
	   if (table->len == 0) return false;\
	   Key##_##Value##_hash_table_entry* entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
	   if (KeyIsNull(entry->key)) return false;\
	   if (val != nullptr) *val = &entry->value;\
	   return true;\
   }\
	   void Key##_##Value##_hash_table_get_ptr_guarantee(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key, Key##_##Value##_hash_table_value** val) {\
	   if (table->len == 0) {\
	   Key##_##Value##_hash_table_set(table, key, (Key##_##Value##_hash_table_value){0});\
   }\
	   Key##_##Value##_hash_table_entry* entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
	   if (KeyIsNull(entry->key)) {\
	   Key##_##Value##_hash_table_set(table, key, (Key##_##Value##_hash_table_value){0});\
	   entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
   }\
	   if (val != nullptr) *val = &entry->value;\
   }\
	   b8 Key##_##Value##_hash_table_del(Key##_##Value##_hash_table* table, Key##_##Value##_hash_table_key key) {\
	   if (table->len == 0) return false;\
	   Key##_##Value##_hash_table_entry* entry = Key##_##Value##_hash_table_find_entry(table->elems, table->cap, key);\
	   if (KeyIsNull(entry->key)) return false;\
	   entry->key = (Key##_##Value##_hash_table_key) {0};\
	   entry->value = Key##_##Value##_hash_table_tombstone;\
	   return true;\
   }
#endif
