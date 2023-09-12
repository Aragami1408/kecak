#ifndef BASE_LINALG_H
#define BASE_LINALG_H

#include "base_math.h"
#include "base_types.h"
#include "base_helper.h"

typedef struct vec2 vec2;
typedef struct vec3 vec3;
typedef struct vec4 vec4;

typedef struct mat3 mat3;
typedef struct mat4 mat4;

typedef struct rect rect;
typedef struct quat quat;

struct vec2 { f32 x; f32 y; };
struct vec3 { f32 x; f32 y; f32 z; };
struct vec4 { f32 x; f32 y; f32 z; f32 t; };

struct mat3 { f32 a[3*3]; };
struct mat4 { f32 a[4*4]; };

struct rect { f32 x; f32 y; f32 w; f32 h; };
struct quat { f32 s; f32 i; f32 j; f32 k; };

#define VEC2(x,y) ((vec2){(x),(y)})
#define VEC3(x,y,z) ((vec3){(x),(y),(z)})
#define QUAD(type,a,b,c,d) ((type){(a),(b),(c),(d)}) // QUAD NOT QUAT

static inline vec2 vec2_init(f32 x, f32 y) { return VEC2(x,y); }
static inline vec3 vec3_init(f32 x, f32 y, f32 z) { return VEC3(x,y,z); }
static inline vec4 vec4_init(f32 x, f32 y, f32 z, f32 t) { return QUAD(vec4,x,y,z,t); }
static inline rect rect_init(f32 x, f32 y, f32 w, f32 h) { return QUAD(rect,x,y,w,h); }
static inline quat quat_init(f32 s, f32 i, f32 j, f32 k) { return QUAD(quat,s,i,j,k); }

static inline f32 mat3_idx(const mat3 *m3, u16 x, u16 y) { return m3->a[y * 3 + x]; }
static inline f32 mat4_idx(const mat4 *m4, u16 x, u16 y) { return m4->a[y * 4 + x]; }

static inline vec2 vec2_add(vec2 a, vec2 b) { return (vec2) { .x = a.x + b.x, .y = a.y + b.y }; }
static inline vec2 vec2_sub(vec2 a, vec2 b) { return (vec2) { .x = a.x - b.x, .y = a.y - b.y }; }
static inline vec2 vec2_scale(vec2 a, f32 s) { return (vec2) { .x = a.x * s, .y = a.y * s }; }
static inline f32  vec2_mag(vec2 v) { return sqrtf(v.x * v.x + v.y * v.y); }
static inline f32  vec2_magsq(vec2 v) { return v.x * v.x + v.y * v.y; }
static inline vec2 vec2_normalize(vec2 v) { return vec2_scale(v, 1.f / vec2_mag(v)); }
static inline vec2 vec2_neg(vec2 v) { return (vec2) { .x = -v.x, .y = -v.y }; }
static inline f32  vec2_dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }

static inline
vec3 vec3_add(vec3 a, vec3 b) { return (vec3) { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z }; }
static inline
vec3 vec3_sub(vec3 a, vec3 b) { return (vec3) { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z }; }
static inline
vec3 vec3_scale(vec3 a, f32 s) { return (vec3) { .x = a.x * s, .y = a.y * s, .z = a.z * s }; }
static inline
vec3 vec3_cross(vec3 a, vec3 b) { return (vec3) { .x = a.y * b.z - b.y * a.z, .y = a.x * b.z - b.x * a.z, .z = a.x * b.y + b.x * a.y }; }

static inline
vec4 vec4_add(vec4 a, vec4 b) { return (vec4) { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .t = a.t + b.t }; }
static inline
vec4 vec4_sub(vec4 a, vec4 b) { return (vec4) { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .t = a.t - b.t }; }
static inline
vec4 vec4_scale(vec4 a, f32 s) { return (vec4) { .x = a.x * s, .y = a.y * s, .z = a.z * s, .t = a.t * s }; }
static inline
vec4 vec4_lerp(vec4 a, vec4 b, f32 t) { return (vec4) { lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t), lerp(a.t, b.t, t) }; }

static inline vec2 vec2_triple_product(vec2 a, vec2 b, vec2 c) {
	vec3 p = vec3_cross(VEC3(b.x,b.y,0.0), VEC3(c.x,c.y,0.0));
	vec3 q = vec3_cross(VEC3(a.x,a.y,0.0), p);
	return VEC2(q.x,q.y);
}

static inline vec2 vec2_clamp(vec2 vec, rect quad) {
	return (vec2) {
		.x = Clamp(quad.x, vec.x, quad.x + quad.w),
		.y = Clamp(quad.y, vec.y, quad.y + quad.h)
	};
}


#endif
