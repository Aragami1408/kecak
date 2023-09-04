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

b32 is_power_of_two(u64 x) {
	return (x & (x-1)) == 0;
}

u64 align_forward(u64 ptr, usize align) {
	u64 p, a, modulo;

	Assert(is_power_of_two(align));

	p = ptr;
	a = (u64)align;
	// Same as (p % a) but faster as 'a' is a power of two
	modulo = p & (a-1);

	if (modulo != 0) {
		// If 'p' address is not aligned, push the address to the
		// next value which is aligned
		p += a - modulo;
	}
	return p;
}

void arena_allocator_init(arena_allocator *a, void *backing_buffer, usize backing_buffer_length) {
	a->buf = (unsigned char *)backing_buffer;
	a->buf_len = backing_buffer_length;
	a->curr_offset = 0;
	a->prev_offset = 0;
}


void *arena_allocator_alloc_align(arena_allocator *a, usize size, usize align) {
	// Align 'curr_offset' forward to the specified alignment
	u64 curr_ptr = (u64)a->buf + (u64)a->curr_offset;
	u64 offset = align_forward(curr_ptr, align);
	offset -= (u64)a->buf; // Change to relative offset

	// Check to see if the backing memory has space left
	if (offset+size <= a->buf_len) {
		void *ptr = &a->buf[offset];
		a->prev_offset = offset;
		a->curr_offset = offset+size;

		// Zero new memory by default
		memset(ptr, 0, size);
		return ptr;
	}
	// Return NULL if the arena_allocator is out of memory (or handle differently)
	return NULL;
}

void arena_allocator_free(arena_allocator *a, void *ptr) {
	// Do nothing
}

void *arena_allocator_resize_align(arena_allocator *a, void *old_memory, usize old_size, usize new_size, usize align) {
	unsigned char *old_mem = (unsigned char *)old_memory;

	Assert(is_power_of_two(align));

	if (old_mem == NULL || old_size == 0) {
		return arena_allocator_alloc_align(a, new_size, align);
	} else if (a->buf <= old_mem && old_mem < a->buf+a->buf_len) {
		if (a->buf+a->prev_offset == old_mem) {
			a->curr_offset = a->prev_offset + new_size;
			if (new_size > old_size) {
				// Zero the new memory by default
				memset(&a->buf[a->curr_offset], 0, new_size-old_size);
			}
			return old_memory;
		} else {
			void *new_memory = arena_allocator_alloc_align(a, new_size, align);
			usize copy_size = old_size < new_size ? old_size : new_size;
			// Copy across old memory to the new memory
			memmove(new_memory, old_memory, copy_size);
			return new_memory;
		}

	} else {
		Assert(0 && "Memory is out of bounds of the buffer in this arena_allocator");
		return NULL;
	}

}

void arena_allocator_free_all(arena_allocator *a) {
	a->curr_offset = 0;
	a->prev_offset = 0;
}

#define arena_allocator_alloc(arena, size) arena_allocator_alloc_align(arena, size, DEFAULT_ALIGNMENT);
#define arena_allocator_resize(arena, old_memory, old_size, new_size) arena_allocator_resize_align(arena, old_memory, old_size, new_size, DEFAULT_ALIGNMENT);

#endif
