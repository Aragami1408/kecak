#ifndef BASE_MATH_H
#define BASE_MATH_H

#include "base_types.h"
#include "base_constants.h"

// NOTE(higanbana): Float Constant Functions
f32 inf_f32(void);
f32 neg_inf_f32(void);
f64 inf_f64(void);
f64 neg_inf_f64(void);

// NOTE(higanbana): Math Functions
f32 abs_f32(f32 x);
f64 abs_f64(f64 x);

f32 sqrt_f32(f32 x);
f64 sqrt_f64(f64 x);

f32 sin_f32(f32 x);
f64 sin_f64(f64 x);

f32 cos_f32(f32 x);
f64 cos_f64(f64 x);

f32 tan_f32(f32 x);
f64 tan_f64(f64 x);

f32 ln_f32(f32 x);
f64 ln_f64(f64 x);

f32 lerp(f32 a, f32 t, f32 b);
f32 unlerp(f32 a, f32 x, f32 b);

// NOTE(higanbana): Compound Type Functions
v2_i32 v2i32(i32 x, i32 y);

v2_f32 v2f32(f32 x, f32 y);
v3_f32 v3f32(f32 x, f32 y, f32 z);
v4_f32 v4f32(f32 x, f32 y, f32 z, f32 w);

v2_i32 v2i32_add(const v2_i32 *a, const v2_i32 *b);
v2_f32 v2f32_add(const v2_f32 *a, const v2_f32 *b);
v3_f32 v3f32_add(const v3_f32 *a, const v3_f32 *b);
v4_f32 v4f32_add(const v4_f32 *a, const v4_f32 *b);

v2_i32 v2i32_subtract(const v2_i32 *a, const v2_i32 *b);
v2_f32 v2f32_subtract(const v2_f32 *a, const v2_f32 *b);
v3_f32 v3f32_subtract(const v3_f32 *a, const v3_f32 *b);
v4_f32 v4f32_subtract(const v4_f32 *a, const v4_f32 *b);

v2_i32 v2i32_multiply(const v2_i32 *a, const i32 b);
v2_f32 v2f32_multiply(const v2_f32 *a, const f32 b);
v3_f32 v3f32_multiply(const v3_f32 *a, const f32 b);
v4_f32 v4f32_multiply(const v4_f32 *a, const f32 b);

v2_f32 v2f32_hadamard(v2_f32 a, v2_f32 b);
v3_f32 v3f32_hadamard(v3_f32 a, v3_f32 b);
v4_f32 v4f32_hadamard(v4_f32 a, v4_f32 b);

f32 v2f32_dot(v2_f32 a, v2_f32 b);
f32 v3f32_dot(v3_f32 a, v3_f32 b);
f32 v4f32_dot(v4_f32 a, v4_f32 b);

#endif