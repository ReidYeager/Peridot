
#ifndef GEM_PERIDOT_VECTOR_H_
#define GEM_PERIDOT_VECTOR_H_
#ifdef PERIDOT_C

#include "peridot_defines.h"

#include <math.h>
#include <assert.h>

#define PERI_DEF_VEC2(type, typeshort) \
typedef union Vec2##typeshort          \
{                                      \
  type elements[2];                    \
  struct                               \
  {                                    \
    union { type x, r, width; };       \
    union { type y, g, height; };      \
  };                                   \
} Vec2##typeshort;

#define PERI_DEF_VEC3(type, typeshort) \
typedef union Vec3##typeshort          \
{                                      \
  type elements[3];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
    union { type z, b; };              \
  };                                   \
} Vec3##typeshort;

#define PERI_DEF_VEC4(type, typeshort) \
typedef union Vec4##typeshort          \
{                                      \
  type elements[4];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
    union { type z, b; };              \
    union { type w, a; };              \
  };                                   \
} Vec4##typeshort;

PERI_DEF_VEC2(float, );
PERI_DEF_VEC3(float, );
PERI_DEF_VEC4(float, );

PERI_DEF_VEC2(double, D);
PERI_DEF_VEC3(double, D);
PERI_DEF_VEC4(double, D);

PERI_DEF_VEC2(int32_t, I);
PERI_DEF_VEC3(int32_t, I);
PERI_DEF_VEC4(int32_t, I);

PERI_DEF_VEC2(uint32_t, U);
PERI_DEF_VEC3(uint32_t, U);
PERI_DEF_VEC4(uint32_t, U);

#undef PERI_DEF_VEC2
#undef PERI_DEF_VEC3
#undef PERI_DEF_VEC4

// =====
// Vec2X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_21(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b),                                          \
    (basePrim)(_a.y + _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b),                                          \
    (basePrim)(_a.y - _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b),                                          \
    (basePrim)(_a.y * _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b && "Divide by zero");                                   \
  base f = {                                                        \
    (basePrim)(_a.x / _b),                                          \
    (basePrim)(_a.y / _b) };                                        \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_22(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && "Divide by zero");                         \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y) };                                      \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_23(base, basePrim, alt, altType) \
PERI_DEF_VECTOR_OPERATIONS_22(base, basePrim, alt, altType)

#define PERI_DEF_VECTOR_OPERATIONS_24(base, basePrim, alt, altType) \
PERI_DEF_VECTOR_OPERATIONS_22(base, basePrim, alt, altType)

#define PERI_DEF_OPERATIONS_2(base)                        \
inline float base##Magnitude(base _a)                      \
{                                                          \
  return (float)sqrt((_a.x * _a.x) + (_a.y * _a.y));       \
}                                                          \
inline base base##Normalize(base _a)                       \
{                                                          \
  return base##DivideFloat(_a, base##Magnitude(_a));       \
}                                                          \
inline float base##Dot(base _a, base _b)                   \
{                                                          \
  return (float)((_a.x * _b.x) + (_a.y * _b.y));           \
}                                                          \
inline uint32_t base##Compare(base _a, base _b)            \
{                                                          \
  return ((_a.x == _b.x) && (_a.y == _b.y));               \
}                                                          \
inline base base##Negate(base _a)                          \
{                                                          \
  base v = { -_a.x, -_a.y };                               \
  return v;                                                \
}

// =====
// Vec3X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_31(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b),                                          \
    (basePrim)(_a.y + _b),                                          \
    (basePrim)(_a.z + _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b),                                          \
    (basePrim)(_a.y - _b),                                          \
    (basePrim)(_a.z - _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b),                                          \
    (basePrim)(_a.y * _b),                                          \
    (basePrim)(_a.z * _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b && "Divide by zero");                                   \
  base f = {                                                        \
    (basePrim)(_a.x / _b),                                          \
    (basePrim)(_a.y / _b),                                          \
    (basePrim)(_a.z / _b) };                                        \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_32(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y),                                        \
    _a.z };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y),                                        \
    _a.z };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y),                                        \
    _a.z };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && "Divide by zero");                         \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y),                                        \
    _a.z };                                                         \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_33(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y),                                        \
    (basePrim)(_a.z + _b.z) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y),                                        \
    (basePrim)(_a.z - _b.z) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y),                                        \
    (basePrim)(_a.z * _b.z) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && _b.z && "Divide by zero");                 \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y),                                        \
    (basePrim)(_a.z / _b.z) };                                      \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_34(base, basePrim, alt, altType) \
PERI_DEF_VECTOR_OPERATIONS_33(base, basePrim, alt, altType)

#define PERI_DEF_OPERATIONS_3(base)                                  \
inline float base##Magnitude(base _a)                                \
{                                                                    \
  return (float)sqrt((_a.x * _a.x) + (_a.y * _a.y) + (_a.z * _a.z)); \
}                                                                    \
inline base base##Normalize(base _a)                                 \
{                                                                    \
  return base##DivideFloat(_a, base##Magnitude(_a));                 \
}                                                                    \
inline float base##Dot(base _a, base _b)                             \
{                                                                    \
  return (float)((_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z));     \
}                                                                    \
inline uint32_t base##Compare(base _a, base _b)                      \
{                                                                    \
  return ((_a.x == _b.x) && (_a.y == _b.y) && (_a.z == _b.z));       \
}                                                                    \
inline base base##Cross(base _a, base _b)                            \
{                                                                    \
  base f = {                                                         \
    _a.y * _b.z - _a.z * _b.y,                                       \
    _a.z * _b.x - _a.x * _b.z,                                       \
    _a.x * _b.y - _a.y * _b.x };                                     \
  return f;                                                          \
}                                                                    \
inline float base##Angle(base _a, base _b)                           \
{                                                                    \
  float angle = base##Dot(_a, _b);                                   \
  angle /= (base##Magnitude(_a) * base##Magnitude(_b));              \
  return acosf(angle);                                               \
}                                                                    \
inline base base##Project(base _a, base _b)                          \
{                                                                    \
  base p = base##Normalize(_b);                                      \
  return base##MultiplyFloat(p, base##Dot(_a, _b));                  \
}                                                                    \
inline base base##Negate(base _a)                                    \
{                                                                    \
  base v = { -_a.x, -_a.y, -_a.z };                                  \
  return v;                                                          \
}

// =====
// Vec4X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_41(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b),                                          \
    (basePrim)(_a.y + _b),                                          \
    (basePrim)(_a.z + _b),                                          \
    (basePrim)(_a.w + _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b),                                          \
    (basePrim)(_a.y - _b),                                          \
    (basePrim)(_a.z - _b),                                          \
    (basePrim)(_a.w - _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b),                                          \
    (basePrim)(_a.y * _b),                                          \
    (basePrim)(_a.z * _b),                                          \
    (basePrim)(_a.w * _b) };                                        \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b && "Divide by zero");                                   \
  base f = {                                                        \
    (basePrim)(_a.x / _b),                                          \
    (basePrim)(_a.y / _b),                                          \
    (basePrim)(_a.z / _b),                                          \
    (basePrim)(_a.w / _b) };                                        \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_42(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y),                                        \
    _a.z,                                                           \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y),                                        \
    _a.z,                                                           \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y),                                        \
    _a.z,                                                           \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && "Divide by zero");                         \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y),                                        \
    _a.z,                                                           \
    _a.w };                                                         \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_43(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y),                                        \
    (basePrim)(_a.z + _b.z),                                        \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y),                                        \
    (basePrim)(_a.z - _b.z),                                        \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y),                                        \
    (basePrim)(_a.z * _b.z),                                        \
    _a.w };                                                         \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && _b.z && "Divide by zero");                 \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y),                                        \
    (basePrim)(_a.z / _b.z),                                        \
    _a.w };                                                         \
  return f;                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_44(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x + _b.x),                                        \
    (basePrim)(_a.y + _b.y),                                        \
    (basePrim)(_a.z + _b.z),                                        \
    (basePrim)(_a.w + _b.w) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x - _b.x),                                        \
    (basePrim)(_a.y - _b.y),                                        \
    (basePrim)(_a.z - _b.z),                                        \
    (basePrim)(_a.w - _b.w) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    (basePrim)(_a.x * _b.x),                                        \
    (basePrim)(_a.y * _b.y),                                        \
    (basePrim)(_a.z * _b.z),                                        \
    (basePrim)(_a.w * _b.w) };                                      \
  return f;                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  assert(_b.x && _b.y && _b.z && _b.w && "Divide by zero");         \
  base f = {                                                        \
    (basePrim)(_a.x / _b.x),                                        \
    (basePrim)(_a.y / _b.y),                                        \
    (basePrim)(_a.z / _b.z),                                        \
    (basePrim)(_a.w / _b.w) };                                      \
  return f;                                                         \
}

#define PERI_DEF_OPERATIONS_4(base)                                                  \
inline float base##Magnitude(base _a)                                                \
{                                                                                    \
  return (float)sqrt((_a.x * _a.x) + (_a.y * _a.y) + (_a.z * _a.z) + (_a.w * _a.w)); \
}                                                                                    \
inline base base##Normalize(base _a)                                                 \
{                                                                                    \
  return base##DivideFloat(_a, base##Magnitude(_a));                                 \
}                                                                                    \
inline float base##Dot(base _a, base _b)                                             \
{                                                                                    \
  return (float)((_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z) + (_a.w * _b.w));     \
}                                                                                    \
inline uint32_t base##Compare(base _a, base _b)                                      \
{                                                                                    \
  return ((_a.x == _b.x) && (_a.y == _b.y) && (_a.z == _b.z) && (_a.w == _b.w));     \
}                                                                                    \
inline base base##Negate(base _a)                                                    \
{                                                                                    \
  base v = { -_a.x, -_a.y, -_a.z, -_a.w };                                           \
  return v;                                                                          \
}

#define PERI_DEF_FULL_VECTOR_OPERATIONS(size, base, basePrimitive)        \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, Float, float)   \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, Double, double) \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, Int, int32_t)   \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, Uint, uint32_t) \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vec2, Vec2)     \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vec3, Vec3)     \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vec4, Vec4)     \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vec2D, Vec2D)   \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vec3D, Vec3D)   \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vec4D, Vec4D)   \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vec2I, Vec2I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vec3I, Vec3I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vec4I, Vec4I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vec2U, Vec2U)   \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vec3U, Vec3U)   \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vec4U, Vec4U)   \
PERI_DEF_OPERATIONS_##size(base)

PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vec2, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vec3, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vec4, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vec2D, double)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vec3D, double)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vec4D, double)
PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vec2I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vec3I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vec4I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vec2U, uint32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vec3U, uint32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vec4U, uint32_t)

#undef PERI_DEF_VECTOR_OPERATIONS_21
#undef PERI_DEF_VECTOR_OPERATIONS_22
#undef PERI_DEF_VECTOR_OPERATIONS_23
#undef PERI_DEF_VECTOR_OPERATIONS_24
#undef PERI_DEF_OPERATIONS_2
#undef PERI_DEF_VECTOR_OPERATIONS_31
#undef PERI_DEF_VECTOR_OPERATIONS_32
#undef PERI_DEF_VECTOR_OPERATIONS_33
#undef PERI_DEF_VECTOR_OPERATIONS_34
#undef PERI_DEF_OPERATIONS_3
#undef PERI_DEF_VECTOR_OPERATIONS_41
#undef PERI_DEF_VECTOR_OPERATIONS_42
#undef PERI_DEF_VECTOR_OPERATIONS_43
#undef PERI_DEF_VECTOR_OPERATIONS_44
#undef PERI_DEF_OPERATIONS_4
#undef PERI_DEF_FULL_VECTOR_OPERATIONS

#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_VECTOR_H_
