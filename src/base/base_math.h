#ifndef BASE_MATH_H
#define BASE_MATH_H

#include "base_types.h"
#include "base_constants.h"

#include <math.h>

// NOTE(higanbana): Float Constant Functions
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

// NOTE(higanbana): Math Functions
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

f64 radians(f32 deg) { return (f64) (deg * DEG_TO_RAD); }

f32 degrees(f64 rad) { return (f32) (rad * RAD_TO_DEG); }

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

#endif
