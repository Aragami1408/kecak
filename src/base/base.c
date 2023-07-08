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

i1_f32 i1f32(f32 min, f32 max) {
	i1_f32 r;
	r.min = min;
	r.max = max;
	if(max < min) {
		r.min = max;
		r.max = min;
	}
	return r;
}
i1_u64 i1u64(u64 min, u64 max) {
	i1_u64 r;
	r.min = min;
	r.max = max;
	if(max < min) {
		r.min = max;
		r.max = min;
	}
	return r;
}

i2_i32 i2i32(i32 x0, i32 y0, i32 x1, i32 y1) {
	i2_i32 r;
	r.x0=x0;
	r.y0=y0;
	r.x1=x1;
	r.y1=y1;
	if(x1 < x0) {
		r.x0 = x1;
		r.x1 = x0;
	}
	if(y1 < y0) {
		r.y0 = y1;
		r.y1 = y0;
	}
	return r;
}
i2_i32 i2i32_vec(v2_i32 min, v2_i32 max) {
	return i2i32(min.x, min.y, max.x, max.y);
}

i2_f32 i2f32(f32 x0, f32 y0, f32 x1, f32 y1) {
	i2_f32 r;
	r.x0=x0;
	r.y0=y0;
	r.x1=x1;
	r.y1=y1;
	if(x1 < x0) {
		r.x0 = x1;
		r.x1 = x0;
	}
	if(y1 < y0) {
		r.y0 = y1;
		r.y1 = y0;
	}
	return r;
}
i2_f32 i2f32_vec(v2_f32 min, v2_f32 max) {
	return i2f32(min.x, min.y, max.x, max.y);
}
i2_f32 i2f32_range(i1_f32 x, i1_f32 y) {
	return i2f32(x.min, y.min, x.max, y.max);	
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

b32 i1f32_intr_overlaps(i1_f32 a, i1_f32 b) {
	return (b.min < a.max && a.min < b.max);
}
b32 i1f32_intr_contains(i1_f32 r, f32 x) {
	return (r.min <= x && x < r.max);
}

b32 i2f32_intr_overlaps(i2_f32 a, i2_f32 b) {
	return (b.x0 < a.x1 && a.x0 < b.x1 && b.x0 < a.x1 && a.x0 < b.x1);
}
b32 i2f32_intr_contains(i2_f32 r, v2_f32 p) {
	return (r.x0 <= p.x && p.x < r.x1 && r.y0 <= p.y && p.y < r.y1);
}

b32 i2i32_intr_overlaps(i2_i32 a, i2_i32 b) {
	return (b.x0 < a.x1 && a.x0 < b.x1 && b.x0 < a.x1 && a.x0 < b.x1);
}
b32 i2i32_intr_contains(i2_i32 r, v2_i32 p) {
	return (r.x0 <= p.x && p.x < r.x1 && r.y0 <= p.y && p.y < r.y1);
}

f32 i1f32_intr_dim(i1_f32 r) {
	return r.max - r.min;
}
u64 i1u64_intr_dim(i1_u64 r) {
	return r.max - r.min;
}
v2_f32 i2f32_intr_dim(i2_f32 r) {
	return v2f32(r.x1 - r.x0, r.y1 - r.y0);
}
v2_i32 i2i32_intr_dim(i2_i32 r) {
	return v2i32(r.x1 - r.x0, r.y1 - r.y0);
}

f32 i1f32_intr_center(i1_f32 r) {
	return (r.min + r.max)*0.5f;
}
u64 i1u64_intr_center(i1_u64 r) {
	return (r.min + r.max)*0.5f;
}
v2_f32 i2f32_intr_center(i2_f32 r) {
	// return (r.min + r.max)*0.5f;
}
v2_i32 i2i32_intr_center(i2_i32 r) {

}

i1_f32 intr_axis(i2_f32 r, axis a) {
	return (i1_f32){
		r.p[0].v[a],
		r.p[1].v[a],
	};
}
