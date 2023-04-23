
#ifndef GEM_PERIDOT_H_
#define GEM_PERIDOT_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "include/peridot_defines.h"

#include <math.h>

// =====
// Vec2X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_21(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b,                                            \
    _a.y + (basePrim)_b };                                          \
  return f;                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b,                                            \
    _a.y - (basePrim)_b };                                          \
    return f;                                                       \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b,                                            \
    _a.y * (basePrim)_b };                                          \
    return f;                                                       \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b,                                            \
    _a.y / (basePrim)_b };                                          \
    return f;                                                       \
}

#define PERI_DEF_VECTOR_OPERATIONS_22(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y };                                        \
    return f;                                                       \
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
  return base##DivideScalarFloat(_a, base##Magnitude(_a)); \
}                                                          \
inline float base##Dot(base _a, base _b)                   \
{                                                          \
  return (float)((_a.x * _b.x) + (_a.y * _b.y));           \
}                                                          \
inline uint32_t base##Compare(base _a, base _b)            \
{                                                          \
  return ((_a.x == _b.x) && (_a.y == _b.y));               \
}

// =====
// Vec3X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_31(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b,                                            \
    _a.y + (basePrim)_b,                                            \
    _a.z + (basePrim)_b };                                          \
    return f;                                                       \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b,                                            \
    _a.y - (basePrim)_b,                                            \
    _a.z - (basePrim)_b };                                          \
    return f;                                                       \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b,                                            \
    _a.y * (basePrim)_b,                                            \
    _a.z * (basePrim)_b };                                          \
    return f;                                                       \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b,                                            \
    _a.y / (basePrim)_b,                                            \
    _a.z / (basePrim)_b };                                          \
    return f;                                                       \
}

#define PERI_DEF_VECTOR_OPERATIONS_32(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y,                                          \
    _a.z };                                                         \
    return f;                                                       \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y,                                          \
    _a.z };                                                         \
    return f;                                                       \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y,                                          \
    _a.z };                                                         \
    return f;                                                       \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y,                                          \
    _a.z };                                                         \
    return f;                                                       \
}

#define PERI_DEF_VECTOR_OPERATIONS_33(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y,                                          \
    _a.z + (basePrim)_b.z };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y,                                          \
    _a.z - (basePrim)_b.z };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y,                                          \
    _a.z * (basePrim)_b.z };                                        \
    return f;                                                       \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y,                                          \
    _a.z / (basePrim)_b.z };                                        \
    return f;                                                       \
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
  return base##DivideScalarFloat(_a, base##Magnitude(_a));           \
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
}

// =====
// Vec4X
// =====

#define PERI_DEF_VECTOR_OPERATIONS_41(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b,                                            \
    _a.y + (basePrim)_b,                                            \
    _a.z + (basePrim)_b,                                            \
    _a.w + (basePrim)_b };                                          \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b,                                            \
    _a.y - (basePrim)_b,                                            \
    _a.z - (basePrim)_b,                                            \
    _a.w - (basePrim)_b };                                          \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b,                                            \
    _a.y * (basePrim)_b,                                            \
    _a.z * (basePrim)_b,                                            \
    _a.w * (basePrim)_b };                                          \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b,                                            \
    _a.y / (basePrim)_b,                                            \
    _a.z / (basePrim)_b,                                            \
    _a.w / (basePrim)_b };                                          \
}

#define PERI_DEF_VECTOR_OPERATIONS_42(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y,                                          \
    _a.z,                                                           \
    _a.w };                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y,                                          \
    _a.z,                                                           \
    _a.w };                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y,                                          \
    _a.z,                                                           \
    _a.w };                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y,                                          \
    _a.z,                                                           \
    _a.w };                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_43(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y,                                          \
    _a.z + (basePrim)_b.z,                                          \
    _a.w };                                                         \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y,                                          \
    _a.z - (basePrim)_b.z,                                          \
    _a.w };                                                         \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y,                                          \
    _a.z * (basePrim)_b.z,                                          \
    _a.w };                                                         \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y,                                          \
    _a.z / (basePrim)_b.z,                                          \
    _a.w };                                                         \
}

#define PERI_DEF_VECTOR_OPERATIONS_44(base, basePrim, alt, altType) \
inline base base##Add##alt(base _a, altType _b)                     \
{                                                                   \
  base f = {                                                        \
    _a.x + (basePrim)_b.x,                                          \
    _a.y + (basePrim)_b.y,                                          \
    _a.z + (basePrim)_b.z,                                          \
    _a.w + (basePrim)_b.w };                                        \
}                                                                   \
inline base base##Subtract##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x - (basePrim)_b.x,                                          \
    _a.y - (basePrim)_b.y,                                          \
    _a.z - (basePrim)_b.z,                                          \
    _a.w - (basePrim)_b.w };                                        \
}                                                                   \
inline base base##Multiply##alt(base _a, altType _b)                \
{                                                                   \
  base f = {                                                        \
    _a.x * (basePrim)_b.x,                                          \
    _a.y * (basePrim)_b.y,                                          \
    _a.z * (basePrim)_b.z,                                          \
    _a.w * (basePrim)_b.w };                                        \
}                                                                   \
inline base base##Divide##alt(base _a, altType _b)                  \
{                                                                   \
  base f = {                                                        \
    _a.x / (basePrim)_b.x,                                          \
    _a.y / (basePrim)_b.y,                                          \
    _a.z / (basePrim)_b.z,                                          \
    _a.w / (basePrim)_b.w };                                        \
}

#define PERI_DEF_OPERATIONS_4(base)                                                  \
inline float base##Magnitude(base _a)                                                \
{                                                                                    \
  return (float)sqrt((_a.x * _a.x) + (_a.y * _a.y) + (_a.z * _a.z) + (_a.w * _a.w)); \
}                                                                                    \
inline base base##Normalize(base _a)                                                 \
{                                                                                    \
  return base##DivideScalarFloat(_a, base##Magnitude(_a));                           \
}                                                                                    \
inline float base##Dot(base _a, base _b)                                             \
{                                                                                    \
  return (float)((_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z) + (_a.w * _b.w));     \
}                                                                                    \
inline uint32_t base##Compare(base _a, base _b)                                      \
{                                                                                    \
  return ((_a.x == _b.x) && (_a.y == _b.y) && (_a.z == _b.z) && (_a.w == _b.w));     \
}

#define PERI_DEF_FULL_VECTOR_OPERATIONS(size, base, basePrimitive)              \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, ScalarFloat, float)   \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, ScalarInt, int32_t)   \
PERI_DEF_VECTOR_OPERATIONS_##size##1(base, basePrimitive, ScalarUint, uint32_t) \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vector2, Vector2)     \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vector3, Vector3)     \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vector4, Vector4)     \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vector2I, Vector2I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vector3I, Vector3I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vector4I, Vector4I)   \
PERI_DEF_VECTOR_OPERATIONS_##size##2(base, basePrimitive, Vector2U, Vector2U)   \
PERI_DEF_VECTOR_OPERATIONS_##size##3(base, basePrimitive, Vector3U, Vector3U)   \
PERI_DEF_VECTOR_OPERATIONS_##size##4(base, basePrimitive, Vector4U, Vector4U)   \
PERI_DEF_OPERATIONS_##size(base)

PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vector2, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vector3, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vector4, float)
PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vector2I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vector3I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vector4I, int32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(2, Vector2U, uint32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(3, Vector3U, uint32_t)
PERI_DEF_FULL_VECTOR_OPERATIONS(4, Vector4U, uint32_t)

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

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !GEM_PERIDOT_H_
