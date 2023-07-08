#ifndef BASE_TYPES_H
#define BASE_TYPES_H

// NOTE(higanbana): Basic Types
#include <stdint.h>
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i16 b16;
typedef i32 b32;
typedef i64 b64;

typedef float f32;
typedef double f64;

// NOTE(higanbana): Compound Types
typedef union v2_i32 {
    struct {
        i32 x;
        i32 y;
    };
    i32 v[2];
} v2_i32;

typedef union v3_i32 {
    struct {
        i32 x;
        i32 y;
        i32 z;
    };
    i32 v[3];
} v3_i32;

typedef union v4_i32 {
    struct {
        i32 x;
        i32 y;
        i32 z;
        i32 w;
    };
    i32 v[4];
} v4_i32;

typedef union v2_f32 {
    struct {
        f32 x;
        f32 y;
    };
    f32 v[2];
} v2_f32;

typedef union v3_f32 {
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 v[3];
} v3_f32;

typedef union v4_f32 {
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    f32 v[4];
} v4_f32;

typedef union i1_f32 {
    struct  {
        f32 min;
        f32 max;
    };
    f32 v[2];
} i1_f32;

typedef union i1_u64 {
    struct {
        u64 min;
        u64 max;
    };
    struct {
        u64 first;
        u64 opl;
    };
    u64 v[2];
} i1_u64;

typedef union i2_i32 {
    struct {
        v2_i32 min;
        v2_i32 max;
    };
    struct {
        v2_i32 p0;
        v2_i32 p1;
    };
    struct {
        i32 x0;
        i32 y0;
        i32 x1;
        i32 y1;
    };
    v2_i32 p[2];
    i32 v[4];
} i2_i32;

typedef union i2_f32 {
    struct {
        v2_f32 min;
        v2_f32 max;
    };
    struct {
        v2_f32 p0;
        v2_f32 p1;
    };
    struct {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
    };
    v2_f32 p[2];
    f32 v[4];
} i2_f32;

#endif
