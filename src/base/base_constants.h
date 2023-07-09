#ifndef BASE_CONSTANTS_H
#define BASE_CONSTANTS_H
#include "base_defines.h"
#include "base_types.h"

// NOTE(higanbana): Some constants
global_variable f32 machine_epsilon_f32 = 1.1920929e-7f;
global_variable f32 pi_f32 = 3.14159265359f;
global_variable f32 tau_f32 = 6.28318530718f;
global_variable f32 e_f32 = 2.71828182846f;
global_variable f32 gold_big_f32 = 1.61803398875f;
global_variable f32 gold_small_f32 = 0.61803398875f;

global_variable f64 machine_epsilon_f64 = 2.220446e-16;
global_variable f64 pi_f64 = 3.14159265359;
global_variable f64 tau_f64 = 6.28318530718;
global_variable f64 e_f64 = 2.71828182846;
global_variable f64 gold_big_f64 = 1.61803398875;
global_variable f64 gold_small_f64 = 0.61803398875;

// NOTE(higanbana): Symbolic Constants
typedef enum axis {
    axis_x,
    axis_y,
    axis_z,
    axis_w,
} axis;

#endif
