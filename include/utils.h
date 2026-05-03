#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// --- Macros ---
#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(x, lo, hi) (MAX(lo, MIN(hi, x)))

// Panic macro provides context on where the crash happened
#define panic(fmt, ...) \
    do { \
        fprintf(stderr, "[PANIC] %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
        abort(); \
    } while(0)

// --- Primitive Typedefs ---
typedef uint8_t  u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t  i32;
typedef int64_t  i64;
typedef float    f32;
typedef double   f64;

// --- Linear Algebra Structs ---
typedef struct { f32 x, y; } Vec2;
typedef struct { f32 x, y, z; } Vec3;
typedef struct { f32 x, y, z, w; } Vec4;

// --- StringView ---
// Useful for slicing strings without allocating new memory
typedef struct {
    const char* str;
    size_t len;
} StringView;

#define SV_FMT "%.*s"
#define SV_ARG(sv) (int)(sv).len, (sv).str

// --- Function Prototypes ---
StringView sv_from_cstr(const char* cstr);
bool       sv_equals(StringView a, StringView b);
Vec3       vec3_add(Vec3 a, Vec3 b);
Vec3       vec3_mul(Vec3 a, f32 s);

#ifdef UTILS_IMPLEMENTATION

StringView sv_from_cstr(const char* cstr) {
    return (StringView){ .str = cstr, .len = strlen(cstr) };
}

bool sv_equals(StringView a, StringView b) {
    if (a.len != b.len) return false;
    return memcmp(a.str, b.str, a.len) == 0;
}

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){ a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3 vec3_mul(Vec3 a, f32 s) {
    return (Vec3){ a.x * s, a.y * s, a.z * s };
}

#endif // UTILS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // UTILS_H
