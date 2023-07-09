#include "base.h"

f32 inf_f32(void) {
	union {f32 f; u32 u;} r;
	r.u = 0x7f800000;
	return r.f;
}

f64 inf_f64(void) {
	union {f64 f; u64 u;} r;
	r.u = 0x7ff0000000000000;
	return r.f;
}

f32 neg_inf_f32(void) {
	union {f32 f; u32 u;} r;
	r.u = 0xff800000;
	return r.f;
}

f64 neg_inf_f64(void) {
	union {f64 f; u64 u;} r;
	r.u = 0xfff0000000000000;
	return r.f;
}

f32 abs_f32(f32 x) {
	union {f32 f; u32 u;} r;
	r.f = x;
	r.u &= 0x7fffffff;
	return r.f;
}

f64 abs_f64(f64 x){
	union {f64 f; u64 u;} r;
	r.f = x;
	r.u &= 0x7fffffffffffffff;
	return r.f;

}

#include <math.h>


f32 sqrt_f32(f32 x) {
	return sqrtf(x);
}

f64 sqrt_f64(f64 x) {
	return sqrt(x);
}

f32 sin_f32(f32 x) {
	return sinf(x);
}
f64 sin_f64(f64 x) {
	return sin(x);
}

f32 cos_f32(f32 x) {
	return cosf(x);
}
f64 cos_f64(f64 x) {
	return cos(x);
}

f32 tan_f32(f32 x) {
	return tan(x);
}

f64 tan_f64(f64 x) {
	return tan(x);
}

f32 ln_f32(f32 x) {
	return logf(x);
}

f64 ln_f64(f64 x) {
	return log(x);
}

f32 lerp(f32 a, f32 t, f32 b) {
	f32 x = a + (b-a)*t;
	return x;
}

f32 unlerp(f32 a, f32 x, f32 b) {
	f32 t = 0.0f;
	if(a != b) {
		t = (x-a)/(b-a);
	}
	return t;
}

v2_i32 v2i32(i32 x, i32 y) {
	return (v2_i32){x,y};
}

v2_f32 v2f32(f32 x, f32 y) {
	return (v2_f32){x,y};
}
v3_f32 v3f32(f32 x, f32 y, f32 z) {
	return (v3_f32){x,y,z};
}
v4_f32 v4f32(f32 x, f32 y, f32 z, f32 w) {
	return (v4_f32){x,y,z,w};
}

v2_i32 v2i32_add(const v2_i32 *a, const v2_i32 *b) {
	return (v2_i32){a->x + b->x, a->y + b->y};
}
v2_f32 v2f32_add(const v2_f32 *a, const v2_f32 *b) {
	return (v2_f32){a->x + b->x, a->y + b->y};
}
v3_f32 v3f32_add(const v3_f32 *a, const v3_f32 *b) {
	return (v3_f32){a->x + b->x, a->y + b->y, a->z + b->z};
}
v4_f32 v4f32_add(const v4_f32 *a, const v4_f32 *b) {
	return (v4_f32){a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w};
}

v2_i32 v2i32_subtract(const v2_i32 *a, const v2_i32 *b) {
	return (v2_i32){a->x - b->x, a->y - b->y};
}
v2_f32 v2f32_subtract(const v2_f32 *a, const v2_f32 *b) {
	return (v2_f32){a->x - b->x, a->y - b->y};
}
v3_f32 v3f32_subtract(const v3_f32 *a, const v3_f32 *b) {
	return (v3_f32){a->x - b->x, a->y - b->y, a->z - b->z};
}
v4_f32 v4f32_subtract(const v4_f32 *a, const v4_f32 *b) {
	return (v4_f32){a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w};
}

v2_i32 v2i32_multiply(const v2_i32 *a, const i32 b) {
	return (v2_i32){a->x * b, a->y * b};
}
v2_f32 v2f32_multiply(const v2_f32 *a, const f32 b) {
	return (v2_f32){a->x * b, a->y * b};
}
v3_f32 v3f32_multiply(const v3_f32 *a, const f32 b) {

	return (v3_f32){a->x * b, a->y * b, a->z * b};
}
v4_f32 v4f32_multiply(const v4_f32 *a, const f32 b) {
	return (v4_f32){a->x * b, a->y * b, a->z * b, a->w * b};
}

v2_f32 v2f32_hadamard(v2_f32 a, v2_f32 b){
	return (v2_f32){a.x * b.x, a.y * b.y};
}
v3_f32 v3f32_hadamard(v3_f32 a, v3_f32 b){

	return (v3_f32){a.x * b.x, a.y * b.y, a.z * b.z};
}
v4_f32 v4f32_hadamard(v4_f32 a, v4_f32 b){

	return (v4_f32){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

f32 v2f32_dot(v2_f32 a, v2_f32 b) {
	return a.x*b.x + a.y+b.y;
}
f32 v3f32_dot(v3_f32 a, v3_f32 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
f32 v4f32_dot(v4_f32 a, v4_f32 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}