#ifndef BASE_STRING_H
#define BASE_STRING_H

#include "base_types.h"
#include "base_defines.h"
#include "base_helper.h"

typedef struct string8 string8;
typedef struct string8_node string8_node;
typedef struct string8_list string8_list;

struct string8 {
	u8 *str;
	u64 size;
};

internal string8 str8(u8 *str, u64 size) {
	string8 str8 = {str, size};
	return(str8);
}
internal string8 str8_range(u8 *first, u8 *opl) {
	string8 str8 = {first, (u64)(opl - first)};
	return(str8);
}
internal string8 str8_cstring(u8 *cstr) {
	u8 *ptr = cstr;
	while(*ptr != 0) {
		ptr += 1;
	}
	string8 str8 = str8_range(cstr, ptr);
	return str8;
}

#define str8_lit(s) str8((u8*)(s), sizeof(s) - 1)

internal string8 str8_prefix(string8 str, u64 size) {
	u64 size_clamped = ClampTop(size, str.size);
	string8 result = {str.str, size_clamped};
	return(result);
}

internal string8 str8_chop(string8 str, u64 amount) {
	u64 amount_clamped = ClampTop(amount, str.size);
	u64 remaining_size = str.size - amount_clamped;
	string8 result = {str.str, remaining_size};
	return(result);
}

internal string8 str8_postfix(string8 str, u64 size) {
	u64 size_clamped = ClampTop(size, str.size);
	u64 skip_to = str.size - size_clamped;
	string8 result = {str.str + skip_to, size_clamped};
	return(result);
}

internal string8 str8_skip(string8 str, u64 amount) {
	u64 amount_clamped = ClampTop(amount, str.size);
	u64 remaining_size = str.size - amount_clamped;
	string8 result = {str.str + amount_clamped, remaining_size};
	return(result);
}

internal string8 str8_substr_opl(string8 str, u64 first, u64 opl) {
	u64 opl_clamped = ClampTop(opl, str.size);
	u64 first_clamped = ClampTop(first, opl_clamped);
	string8 result = {str.str + first_clamped, opl_clamped - first_clamped};
	return(result);
}

internal string8 str8_substr_size(string8 str, u64 first, u64 size) {
	string8 result = str8_substr_opl(str, first, first + size);
	return(result);
}

#define str8_expand(s) (int)((s).size), ((s).str)



#endif
