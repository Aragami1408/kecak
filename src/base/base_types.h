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

typedef size_t usize;

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

#endif
