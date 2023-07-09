#ifndef BASE_MEMORY_H
#define BASE_MEMORY_H

#include "base_defines.h"
#include "base_types.h"
#include "base_helper.h"

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void *))
#endif

typedef struct {
	unsigned char *buf;
	usize         buf_len;
	usize         prev_offset; // This will be useful for later on
	usize         curr_offset;
} arena_allocator;

void arena_allocator_init(arena_allocator *a, void *backing_buffer, usize backing_buffer_length);
void *arena_allocator_alloc_align(arena_allocator *a, usize size, usize align);
void arena_allocator_free(arena_allocator *a, void *ptr);
void *arena_allocator_resize_align(arena_allocator *a, void *old_memory, usize old_size, usize new_size, usize align);
void arena_allocator_free_all(arena_allocator *a);

#define arena_allocator_alloc(arena, size) arena_allocator_alloc_align(arena, size, DEFAULT_ALIGNMENT);
#define arena_allocator_resize(arena, old_memory, old_size, new_size) arena_allocator_resize_align(arena, old_memory, old_size, new_size, DEFAULT_ALIGNMENT);

#endif
