#ifndef BASE_STR_H
#define BASE_STR_H

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "base_memory.h"

typedef struct str_const str_const;

struct str_const {
	u8 *str;
	u64 size;
};

#define str_const_lit(s) (str_const) { .str = (u8 *)(s), .size = sizeof(s) - 1 }
#define str_const_make(s) (str_const) { .str = (u8 *)(s), .size = strlen(s) }
#define str_const_expand(s) (i32)(s).size, (s).str

str_const str_const_alloc(arena_allocator *arena, u64 size) {
	str_const s = {0};
	s.str = (u8 *)arena_allocator_alloc(arena, size + 1);
	s.str[size] = '\0';
	s.size = size;
	return s;
}

str_const str_const_copy(arena_allocator *arena, str_const other) {
	str_const s = {0};
	s.str = (u8 *)arena_allocator_alloc(arena, other.size + 1);
	s.size = other.size;
	memcpy(s.str, other.str, other.size);
	s.str[s.size] = '\0';
	return s;
}

str_const str_const_cat(arena_allocator *arena, str_const a, str_const b) {
	str_const final = {0};
	final.size = a.size + b.size;
	final.str = (u8 *)arena_allocator_alloc(arena, final.size + 1);
	memcpy(final.str, a.str, a.size);
	memcpy(final.str + a.size, b.str, b.size);
	final.str[final.size] = '\0';
	return final;

}

str_const str_const_from_format(arena_allocator* arena, const char* format, ...) {
    va_list args;
    va_start(args, format);
    const char buf[8092];
    vsnprintf(buf, 8092, format, args);
    va_end(args);
    u64 size = strlen(buf);
    str_const s = str_const_alloc(arena, size);
    memmove(s.str, buf, size);
    return s;
}

b8 str_const_eq(str_const a, str_const b) {
    if (a.size != b.size) return false;
    return memcmp(a.str, b.str, b.size) == 0;
}

b8 str_const_is_null(str_const k) {
	return k.str == 0 && k.size == 0;
}

u64 str_const_find_first(str_const str, str_const needle, u32 offset) {
    u64 i = 0;
    if (needle.size > 0) {
        i = str.size;
        if (str.size >= needle.size) {
            i = offset;
            i8 c = needle.str[0];
            u64 one_past_last = str.size - needle.size + 1;
            for (; i < one_past_last; i++) {
                if (str.str[i] == c) {
                    if ((str.size - i) >= needle.size) {
                        str_const sub = { .str = str.str + i, .size = needle.size };
                        if (str_const_eq(sub, needle)) break;
                    }
                }
            }
            if (i == one_past_last) {
                i = str.size;
            }
        }
    }
    return i;
}

u64 str_find_last(str_const str, str_const needle, u32 offset) {
    u64 prev = str.size;
    if (offset == 0)
        offset = str.size;
    u64 idx = 0;
    while (true) {
        prev = idx;
        idx = str_const_find_first(str, needle, idx);
        if (idx >= offset) break;
        idx++;
    }
    return prev;
}

u32 str_hash(str_const str) {
    u32 hash = 2166136261u;
    for (int i = 0; i < str.size; i++) {
        hash ^= str.str[i];
        hash *= 16777619;
    }
    return hash;
}

u64 str_hash_64(str_const str) {
    u64 hash = 2166136261u;
    for (int i = 0; i < str.size; i++) {
        hash ^= str.str[i];
        hash *= 16777619;
    }
    return hash;
}

u64 str_const_substr_count(str_const str, str_const needle) {
    u32 ct = 0;
    u64 idx = 0;
    while (true) {
        idx = str_const_find_first(str, needle, idx);
        if (idx == str.size)
            break;
        ct++;
        idx++;
    }
    return ct;
}

str_const str_replace_all(arena_allocator* arena, str_const to_fix, str_const needle, str_const replacement) {
    if (needle.size == 0) return to_fix;
    u64 replaceable = str_const_substr_count(to_fix, needle);
    if (replaceable == 0) return to_fix;
    
    u64 new_size = (to_fix.size - replaceable * needle.size) + (replaceable * replacement.size);
    str_const ret = str_const_alloc(arena, new_size);
    
    b8 replaced;
    u64 o = 0;
    for (u64 i = 0; i < to_fix.size;) {
        replaced = false;
        if (to_fix.str[i] == needle.str[0]) {
            if ((to_fix.size - i) >= needle.size) {
                str_const sub = { .str = to_fix.str + i, .size = needle.size };
                if (str_const_eq(sub, needle)) {
                    // replace this one
                    memmove(ret.str + o, replacement.str, replacement.size);
                    replaced = true;
                }
            }
        }
        
        if (replaced) {
            o += replacement.size;
            i += needle.size;
            continue;
        }
        
        ret.str[o] = to_fix.str[i];
        o++; i++;
    }
    
    return ret;
}



#endif
