
#ifndef GEM_PERIDOT_VECTOR_HPP_
#define GEM_PERIDOT_VECTOR_HPP_

#include "peridot_defines.h"

#ifndef PERIDOT_C

#ifndef PERIDOT_NO_NAMESPACE
namespace Pdt {
#endif // !PERIDOT_NO_NAMESPACE

#include <assert.h>
#include <math.h>

class Vec2;  class Vec3;  class Vec4;
class Vec2D; class Vec3D; class Vec4D;
class Vec2I; class Vec3I; class Vec4I;
class Vec2U; class Vec3U; class Vec4U;

#define __FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, symbol) \
inline base  operator symbol   (const alt& other) const;          \
inline base& operator symbol##= (const alt& other);

#define __FN_DEC_OPERATORS(base, baseType, alt)      \
__FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, +) \
__FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, -) \
__FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, *) \
__FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, /)

#define __FN_DEC_COMMON(base, baseType)          \
__FN_DEC_OPERATORS(base, baseType, float)        \
__FN_DEC_OPERATORS(base, baseType, double)       \
__FN_DEC_OPERATORS(base, baseType, int)          \
__FN_DEC_OPERATORS(base, baseType, unsigned int) \
__FN_DEC_OPERATORS(base, baseType, Vec2)         \
__FN_DEC_OPERATORS(base, baseType, Vec3)         \
__FN_DEC_OPERATORS(base, baseType, Vec4)         \
__FN_DEC_OPERATORS(base, baseType, Vec2D)        \
__FN_DEC_OPERATORS(base, baseType, Vec3D)        \
__FN_DEC_OPERATORS(base, baseType, Vec4D)        \
__FN_DEC_OPERATORS(base, baseType, Vec2I)        \
__FN_DEC_OPERATORS(base, baseType, Vec3I)        \
__FN_DEC_OPERATORS(base, baseType, Vec4I)        \
__FN_DEC_OPERATORS(base, baseType, Vec2U)        \
__FN_DEC_OPERATORS(base, baseType, Vec3U)        \
__FN_DEC_OPERATORS(base, baseType, Vec4U)        \
inline base operator -() const;                  \
inline float MagnitudeSquared() const;           \
inline float Magnitude() const;                  \
inline base Normal() const;                      \
inline base& Normalize();

#define __DEF_VEC_2(baseType, suffix)                                 \
class Vec2##suffix                                                    \
{                                                                     \
public:                                                               \
  union                                                               \
  {                                                                   \
    baseType elements[2];                                             \
    struct                                                            \
    {                                                                 \
      union { baseType x, r, width; };                                \
      union { baseType y, g, height; };                               \
    };                                                                \
  };                                                                  \
  Vec2##suffix(baseType x = 0, baseType y = 0) : x(x), y(y) {}        \
  Vec2##suffix(Vec2##suffix& other) : x(other.x), y(other.y) {}       \
  Vec2##suffix(const Vec2##suffix& other) : x(other.x), y(other.y) {} \
  __FN_DEC_COMMON(Vec2##suffix, baseType)                             \
  inline bool operator==(const Vec2##suffix& other) const;            \
  inline float Dot(const Vec2##suffix& other) const;                  \
};

#define __DEF_VEC_3(baseType, suffix)                                                \
class Vec3##suffix                                                                   \
{                                                                                    \
public:                                                                              \
  union                                                                              \
  {                                                                                  \
    baseType elements[3];                                                            \
    struct                                                                           \
    {                                                                                \
      union { baseType x, r, width; };                                               \
      union { baseType y, g, height; };                                              \
      union { baseType z, b, depth; };                                               \
    };                                                                               \
  };                                                                                 \
  Vec3##suffix(baseType x = 0, baseType y = 0, baseType z = 0) : x(x), y(y), z(z) {} \
  Vec3##suffix(Vec3##suffix& other) : x(other.x), y(other.y), z(other.z) {}          \
  Vec3##suffix(const Vec3##suffix& other) : x(other.x), y(other.y), z(other.z) {}    \
  __FN_DEC_COMMON(Vec3##suffix, baseType)                                            \
  inline bool operator==(const Vec3##suffix& other) const;                           \
  inline float Dot(const Vec3##suffix& other) const;                                 \
  inline float Angle(const Vec3##suffix& other) const;                               \
  inline Vec3##suffix Cross(const Vec3##suffix& other) const;                        \
  inline Vec3##suffix Project(const Vec3##suffix& other) const;                      \
};

#define __DEF_VEC_4(baseType, suffix)                                                                      \
class Vec4##suffix                                                                                         \
{                                                                                                          \
public:                                                                                                    \
  union                                                                                                    \
  {                                                                                                        \
    baseType elements[4];                                                                                  \
    struct                                                                                                 \
    {                                                                                                      \
      union { baseType x, r; };                                                                            \
      union { baseType y, g; };                                                                            \
      union { baseType z, b; };                                                                            \
      union { baseType w, a; };                                                                            \
    };                                                                                                     \
  };                                                                                                       \
  Vec4##suffix(baseType x = 0, baseType y = 0, baseType z = 0, baseType w = 0) : x(x), y(y), z(z), w(w) {} \
  Vec4##suffix(Vec4##suffix& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}                    \
  Vec4##suffix(const Vec4##suffix& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}              \
  __FN_DEC_COMMON(Vec4##suffix, baseType)                                                                  \
  inline bool operator==(const Vec4##suffix& other) const;                                                 \
  inline float Dot(const Vec4##suffix& other) const;                                                       \
};

__DEF_VEC_2(float,)
__DEF_VEC_3(float,)
__DEF_VEC_4(float,)
__DEF_VEC_2(double, D)
__DEF_VEC_3(double, D)
__DEF_VEC_4(double, D)
__DEF_VEC_2(int, I)
__DEF_VEC_3(int, I)
__DEF_VEC_4(int, I)
__DEF_VEC_2(unsigned int, U)
__DEF_VEC_3(unsigned int, U)
__DEF_VEC_4(unsigned int, U)

// Scalars
// ============================================================

#define __FN_DEF_OPERATOR_ARITHMETIC_1_2(base, baseType, alt, symbol)        \
inline base  operator symbol (const alt& other, const base& vec)             \
{                                                                            \
  return base{ (baseType)other symbol vec.x, (baseType)other symbol vec.y }; \
}
#define __FN_DEF_OPERATOR_DIVIDE_1_2(base, baseType, alt)          \
inline base  operator/(const alt& other, const base& vec)          \
{                                                                  \
  assert(vec.x && vec.y && "Divide by zero");                      \
  return base{ (baseType)other / vec.x, (baseType)other / vec.y }; \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_1_3(base, baseType, alt, symbol)                                      \
inline base  operator symbol (const alt& other, const base& vec)                                           \
{                                                                                                          \
  return base{ (baseType)other symbol vec.x, (baseType)other symbol vec.y, (baseType)other symbol vec.z }; \
}
#define __FN_DEF_OPERATOR_DIVIDE_1_3(base, baseType, alt)                                   \
inline base  operator/(const alt& other, const base& vec)                                   \
{                                                                                           \
  assert(vec.x && vec.y && vec.z && "Divide by zero");                                      \
  return base{ (baseType)other / vec.x, (baseType)other / vec.y, (baseType)other / vec.z }; \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_1_4(base, baseType, alt, symbol)                                                                    \
inline base  operator symbol (const alt& other, const base& vec)                                                                         \
{                                                                                                                                        \
  return base{ (baseType)other symbol vec.x, (baseType)other symbol vec.y, (baseType)other symbol vec.z, (baseType)other symbol vec.w }; \
}
#define __FN_DEF_OPERATOR_DIVIDE_1_4(base, baseType, alt)                                                            \
inline base  operator/(const alt& other, const base& vec)                                                            \
{                                                                                                                    \
  assert(vec.x && vec.y && vec.z && vec.w && "Divide by zero");                                                      \
  return base{ (baseType)other / vec.x, (baseType)other / vec.y, (baseType)other / vec.z, (baseType)other / vec.w }; \
}

// Vec2
// ============================================================

// Arithmetic operators

#define __FN_DEF_OPERATOR_ARITHMETIC_2_1(base, baseType, alt, symbol) \
inline base  base::operator symbol (const alt& other) const           \
{                                                                     \
  return base{ x symbol (baseType)other, y symbol (baseType)other };  \
}                                                                     \
inline base& base::operator symbol##= (const alt& other)              \
{                                                                     \
  x symbol##= (baseType)other;                                        \
  y symbol##= (baseType)other;                                        \
  return *this;                                                       \
}

#define __FN_DEF_OPERATOR_DIVIDE_2_1(base, baseType, alt)  \
inline base  base::operator / (const alt& other) const     \
{                                                          \
  assert(other && "Divide by zero");                       \
  return base{ x / (baseType)other, y / (baseType)other }; \
}                                                          \
inline base& base::operator /= (const alt& other)          \
{                                                          \
  assert(other && "Divide by zero");                       \
  x /= (baseType)other;                                    \
  y /= (baseType)other;                                    \
  return *this;                                            \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)    \
inline base  base::operator symbol (const alt& other) const              \
{                                                                        \
  return base{ x symbol (baseType)other.x, y symbol (baseType)other.y }; \
}                                                                        \
inline base& base::operator symbol##= (const alt& other)                 \
{                                                                        \
  x symbol##= (baseType)other.x;                                         \
  y symbol##= (baseType)other.y;                                         \
  return *this;                                                          \
}

#define __FN_DEF_OPERATOR_DIVIDE_2_2(base, baseType, alt)      \
inline base  base::operator / (const alt& other) const         \
{                                                              \
  assert(other.x && other.y && "Divide by zero");              \
  return base{ x / (baseType)other.x, y / (baseType)other.y }; \
}                                                              \
inline base& base::operator /= (const alt& other)              \
{                                                              \
  assert(other.x && other.y && "Divide by zero");              \
  x /= (baseType)other.x;                                      \
  y /= (baseType)other.y;                                      \
  return *this;                                                \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_2_3(base, baseType, alt, symbol)__FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)
#define __FN_DEF_OPERATOR_ARITHMETIC_2_4(base, baseType, alt, symbol) __FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)

#define __FN_DEF_OPERATOR_DIVIDE_2_3(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_2_2(base, baseType, alt)
#define __FN_DEF_OPERATOR_DIVIDE_2_4(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_2_2(base, baseType, alt)

// Common

#define __FN_DEF_COMMON_2(base, baseType)              \
base base::operator -() const                          \
{                                                      \
  return base{ -x, -y };                               \
}                                                      \
float base::MagnitudeSquared() const                   \
{                                                      \
  return (float)((x * x) + (y * y));                   \
}                                                      \
float base::Magnitude() const                          \
{                                                      \
  return (float)sqrt((x * x) + (y * y));               \
}                                                      \
base base::Normal() const                              \
{                                                      \
  float mag = MagnitudeSquared();                      \
  if (mag == 0)                                        \
  {                                                    \
    return *this;                                      \
  }                                                    \
  mag = sqrt(mag);                                     \
  return base{ (baseType)(x/mag), (baseType)(y/mag) }; \
}                                                      \
base& base::Normalize()                                \
{                                                      \
  *this = this->Normal();                              \
  return *this;                                        \
}                                                      \
inline bool base::operator==(const base& other) const  \
{                                                      \
  return x == other.x && y == other.y;                 \
}                                                      \
inline float base::Dot(const base& other) const        \
{                                                      \
  return float((x * other.x) + (y * other.y));         \
}                                                      \
float Dot(const base& left, const base& right)         \
{                                                      \
  return left.Dot(right);                              \
}

// Vec3
// ============================================================

// Arithmetic operators

#define __FN_DEF_OPERATOR_ARITHMETIC_3_1(base, baseType, alt, symbol)                          \
inline base  base::operator symbol (const alt& other) const                                    \
{                                                                                              \
  return base{ x symbol (baseType)other, y symbol (baseType)other, z symbol (baseType)other }; \
}                                                                                              \
inline base& base::operator symbol##= (const alt& other)                                       \
{                                                                                              \
  x symbol##= (baseType)other;                                                                 \
  y symbol##= (baseType)other;                                                                 \
  z symbol##= (baseType)other;                                                                 \
  return *this;                                                                                \
}

#define __FN_DEF_OPERATOR_DIVIDE_3_1(base, baseType, alt)                       \
inline base  base::operator / (const alt& other) const                          \
{                                                                               \
  assert(other && "Divide by zero");                                            \
  return base{ x / (baseType)other, y / (baseType)other, z / (baseType)other }; \
}                                                                               \
inline base& base::operator /= (const alt& other)                               \
{                                                                               \
  assert(other && "Divide by zero");                                            \
  x /= (baseType)other;                                                         \
  y /= (baseType)other;                                                         \
  z /= (baseType)other;                                                         \
  return *this;                                                                 \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_3_2(base, baseType, alt, symbol) __FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)
#define __FN_DEF_OPERATOR_DIVIDE_3_2(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_2_2(base, baseType, alt)

#define __FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)                                \
inline base  base::operator symbol (const alt& other) const                                          \
{                                                                                                    \
  return base{ x symbol (baseType)other.x, y symbol (baseType)other.y, z symbol (baseType)other.z }; \
}                                                                                                    \
inline base& base::operator symbol##= (const alt& other)                                             \
{                                                                                                    \
  x symbol##= (baseType)other.x;                                                                     \
  y symbol##= (baseType)other.y;                                                                     \
  z symbol##= (baseType)other.z;                                                                     \
  return *this;                                                                                      \
}

#define __FN_DEF_OPERATOR_DIVIDE_3_3(base, baseType, alt)                             \
inline base  base::operator / (const alt& other) const                                \
{                                                                                     \
  assert(other.x && other.y && other.z && "Divide by zero");                          \
  return base{ x / (baseType)other.x, y / (baseType)other.y, z / (baseType)other.z }; \
}                                                                                     \
inline base& base::operator /= (const alt& other)                                     \
{                                                                                     \
  assert(other.x && other.y && other.z && "Divide by zero");                          \
  x /= (baseType)other.x;                                                             \
  y /= (baseType)other.y;                                                             \
  z /= (baseType)other.z;                                                             \
  return *this;                                                                       \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_3_4(base, baseType, alt, symbol) __FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)
#define __FN_DEF_OPERATOR_DIVIDE_3_4(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_3_3(base, baseType, alt)

// Common

#define __FN_DEF_COMMON_3(base, baseType)                                 \
base base::operator -() const                                             \
{                                                                         \
  return base{ -x, -y, -z };                                              \
}                                                                         \
float base::MagnitudeSquared() const                                      \
{                                                                         \
  return (float)((x * x) + (y * y) + (z * z));                            \
}                                                                         \
float base::Magnitude() const                                             \
{                                                                         \
  return (float)sqrt((x * x) + (y * y) + (z * z));                        \
}                                                                         \
base base::Normal() const                                                 \
{                                                                         \
  float mag = MagnitudeSquared();                                         \
  if (mag == 0)                                                           \
  {                                                                       \
    return *this;                                                         \
  }                                                                       \
  mag = sqrt(mag);                                                        \
  return base{ (baseType)(x/mag), (baseType)(y/mag), (baseType)(z/mag) }; \
}                                                                         \
base& base::Normalize()                                                   \
{                                                                         \
  *this = this->Normal();                                                 \
  return *this;                                                           \
}                                                                         \
inline bool base::operator==(const base& other) const                     \
{                                                                         \
  return x == other.x && y == other.y && z == other.z;                    \
}                                                                         \
inline float base::Dot(const base& other) const                           \
{                                                                         \
  return float((x * other.x) + (y * other.y) + (z * other.z));            \
}                                                                         \
inline base base::Cross(const base& other) const                          \
{                                                                         \
  return base{                                                            \
    y * other.z - z * other.y,                                            \
    z * other.x - x * other.z,                                            \
    x * other.y - y * other.x };                                          \
}                                                                         \
inline float base::Angle(const base& other) const                         \
{                                                                         \
  float angle = Dot(other);                                               \
  angle /= (Magnitude() * other.Magnitude());                             \
  return acosf(angle);                                                    \
}                                                                         \
inline base base::Project(const base& other) const                        \
{                                                                         \
  base p = other.Normal();                                                \
  return p * Dot(other);                                                  \
}                                                                         \
float Dot(const base& left, const base& right)                            \
{                                                                         \
  return left.Dot(right);                                                 \
}                                                                         \
inline base Cross(const base& left, const base& right)                    \
{                                                                         \
  return base{                                                            \
    left.y * right.z - left.z * right.y,                                  \
    left.z * right.x - left.x * right.z,                                  \
    left.x * right.y - left.y * right.x };                                \
}

// Vec4
// ============================================================

// Arithmetic operators

#define __FN_DEF_OPERATOR_ARITHMETIC_4_1(base, baseType, alt, symbol)                                                    \
inline base  base::operator symbol (const alt& other) const                                                              \
{                                                                                                                        \
  return base{ x symbol (baseType)other, y symbol (baseType)other, z symbol (baseType)other, w symbol (baseType)other }; \
}                                                                                                                        \
inline base& base::operator symbol##= (const alt& other)                                                                 \
{                                                                                                                        \
  x symbol##= (baseType)other;                                                                                           \
  y symbol##= (baseType)other;                                                                                           \
  z symbol##= (baseType)other;                                                                                           \
  w symbol##= (baseType)other;                                                                                           \
  return *this;                                                                                                          \
}

#define __FN_DEF_OPERATOR_DIVIDE_4_1(base, baseType, alt)                                            \
inline base  base::operator / (const alt& other) const                                               \
{                                                                                                    \
  assert(other && "Divide by zero");                                                                 \
  return base{ x / (baseType)other, y / (baseType)other, z / (baseType)other, w / (baseType)other }; \
}                                                                                                    \
inline base& base::operator /= (const alt& other)                                                    \
{                                                                                                    \
  assert(other && "Divide by zero");                                                                 \
  x /= (baseType)other;                                                                              \
  y /= (baseType)other;                                                                              \
  z /= (baseType)other;                                                                              \
  w /= (baseType)other;                                                                              \
  return *this;                                                                                      \
}

#define __FN_DEF_OPERATOR_ARITHMETIC_4_2(base, baseType, alt, symbol) __FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)
#define __FN_DEF_OPERATOR_ARITHMETIC_4_3(base, baseType, alt, symbol) __FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)
#define __FN_DEF_OPERATOR_DIVIDE_4_2(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_2_2(base, baseType, alt)
#define __FN_DEF_OPERATOR_DIVIDE_4_3(base, baseType, alt) __FN_DEF_OPERATOR_DIVIDE_3_3(base, baseType, alt)

#define __FN_DEF_OPERATOR_ARITHMETIC_4_4(base, baseType, alt, symbol)                                                            \
inline base  base::operator symbol (const alt& other) const                                                                      \
{                                                                                                                                \
  return base{ x symbol (baseType)other.x, y symbol (baseType)other.y, z symbol (baseType)other.z, w symbol (baseType)other.w }; \
}                                                                                                                                \
inline base& base::operator symbol##= (const alt& other)                                                                         \
{                                                                                                                                \
  x symbol##= (baseType)other.x;                                                                                                 \
  y symbol##= (baseType)other.y;                                                                                                 \
  z symbol##= (baseType)other.z;                                                                                                 \
  w symbol##= (baseType)other.w;                                                                                                 \
  return *this;                                                                                                                  \
}

#define __FN_DEF_OPERATOR_DIVIDE_4_4(base, baseType, alt)                                                    \
inline base  base::operator / (const alt& other) const                                                       \
{                                                                                                            \
  assert(other.x && other.y && other.z && other.w && "Divide by zero");                                      \
  return base{ x / (baseType)other.x, y / (baseType)other.y, z / (baseType)other.z, w / (baseType)other.w }; \
}                                                                                                            \
inline base& base::operator /= (const alt& other)                                                            \
{                                                                                                            \
  assert(other.x && other.y && other.z && other.w && "Divide by zero");                                      \
  x /= (baseType)other.x;                                                                                    \
  y /= (baseType)other.y;                                                                                    \
  z /= (baseType)other.z;                                                                                    \
  w /= (baseType)other.w;                                                                                    \
  return *this;                                                                                              \
}


// Common

#define __FN_DEF_COMMON_4(base, baseType)                                                    \
inline base base::operator -() const                                                         \
{                                                                                            \
  return base{ -x, -y, -z, -w };                                                             \
}                                                                                            \
float base::MagnitudeSquared() const                                                         \
{                                                                                            \
  return (float)((x * x) + (y * y) + (z * z) + (w * w));                                     \
}                                                                                            \
float base::Magnitude() const                                                                \
{                                                                                            \
  return (float)sqrt((x * x) + (y * y) + (z * z) + (w * w));                                 \
}                                                                                            \
base base::Normal() const                                                                    \
{                                                                                            \
  float mag = MagnitudeSquared();                                                            \
  if (mag == 0)                                                                              \
  {                                                                                          \
    return *this;                                                                            \
  }                                                                                          \
  mag = sqrt(mag);                                                                           \
  return base{ (baseType)(x/mag), (baseType)(y/mag), (baseType)(z/mag), (baseType)(w/mag) }; \
}                                                                                            \
base& base::Normalize()                                                                      \
{                                                                                            \
  *this = this->Normal();                                                                    \
  return *this;                                                                              \
}                                                                                            \
inline bool base::operator==(const base& other) const                                        \
{                                                                                            \
  return x == other.x && y == other.y && z == other.z && w == other.w;                       \
}                                                                                            \
inline float base::Dot(const base& other) const                                              \
{                                                                                            \
  return float((x * other.x) + (y * other.y) + (z * other.z) + (w * other.w));               \
}                                                                                            \
float Dot(const base& left, const base& right)                                               \
{                                                                                            \
  return left.Dot(right);                                                                    \
}

// XXX
// ============================================================

#define __FN_DEF_COL_OPERATOR_ARITHMETIC(base, baseType, count, alt, altType, altCount) \
__FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount(base, baseType, alt, +)               \
__FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount(base, baseType, alt, -)               \
__FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount(base, baseType, alt, *)               \
__FN_DEF_OPERATOR_DIVIDE_##count##_##altCount(base, baseType, alt)

#define __FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS(base, baseType, count, alt, altType, altCount) \
__FN_DEF_OPERATOR_ARITHMETIC_##altCount##_##count(base, baseType, alt, +)                       \
__FN_DEF_OPERATOR_ARITHMETIC_##altCount##_##count(base, baseType, alt, -)                       \
__FN_DEF_OPERATOR_ARITHMETIC_##altCount##_##count(base, baseType, alt, *)                       \
__FN_DEF_OPERATOR_DIVIDE_##altCount##_##count(base, baseType, alt)

#define __FN_DEF_COL_ARITHMETIC(base, baseType, count)                                         \
__FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS(base, baseType, count, float,        float,        1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS(base, baseType, count, double,       double,       1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS(base, baseType, count, int,          int,          1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS(base, baseType, count, unsigned int, unsigned int, 1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, float,        float,        1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, double,       double,       1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, int,          int,          1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, unsigned int, unsigned int, 1) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec2,         float,        2) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec2D,        double,       2) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec2I,        int,          2) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec2U,        unsigned int, 2) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec3,         float,        3) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec3D,        double,       3) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec3I,        int,          3) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec3U,        unsigned int, 3) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec4,         float,        4) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec4D,        double,       4) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec4I,        int,          4) \
__FN_DEF_COL_OPERATOR_ARITHMETIC(        base, baseType, count, Vec4U,        unsigned int, 4)

#define __FN_DEF_VEC(base, baseType, count)    \
__FN_DEF_COL_ARITHMETIC(base, baseType, count) \
__FN_DEF_COMMON_##count(base, baseType)

__FN_DEF_VEC(Vec2, float, 2);
__FN_DEF_VEC(Vec3, float, 3);
__FN_DEF_VEC(Vec4, float, 4);
__FN_DEF_VEC(Vec2D, double, 2);
__FN_DEF_VEC(Vec3D, double, 3);
__FN_DEF_VEC(Vec4D, double, 4);
__FN_DEF_VEC(Vec2I, int, 2);
__FN_DEF_VEC(Vec3I, int, 3);
__FN_DEF_VEC(Vec4I, int, 4);
__FN_DEF_VEC(Vec2U, unsigned int, 2);
__FN_DEF_VEC(Vec3U, unsigned int, 3);
__FN_DEF_VEC(Vec4U, unsigned int, 4);

#undef __FN_DEC_OPERATOR_ARITHMETIC
#undef __FN_DEC_OPERATORS
#undef __FN_DEC_COMMON
#undef __DEF_VEC_2
#undef __DEF_VEC_3
#undef __DEF_VEC_4
#undef __FN_DEF_OPERATOR_ARITHMETIC_1_2
#undef __FN_DEF_OPERATOR_DIVIDE_1_2
#undef __FN_DEF_OPERATOR_ARITHMETIC_1_3
#undef __FN_DEF_OPERATOR_DIVIDE_1_3
#undef __FN_DEF_OPERATOR_ARITHMETIC_1_4
#undef __FN_DEF_OPERATOR_DIVIDE_1_4
#undef __FN_DEF_OPERATOR_ARITHMETIC_2_1
#undef __FN_DEF_OPERATOR_DIVIDE_2_1
#undef __FN_DEF_OPERATOR_ARITHMETIC_2_2
#undef __FN_DEF_OPERATOR_DIVIDE_2_2
#undef __FN_DEF_OPERATOR_ARITHMETIC_2_3
#undef __FN_DEF_OPERATOR_ARITHMETIC_2_4
#undef __FN_DEF_OPERATOR_DIVIDE_2_3
#undef __FN_DEF_OPERATOR_DIVIDE_2_4
#undef __FN_DEF_COMMON_2
#undef __FN_DEF_OPERATOR_ARITHMETIC_3_1
#undef __FN_DEF_OPERATOR_DIVIDE_3_1
#undef __FN_DEF_OPERATOR_ARITHMETIC_3_2
#undef __FN_DEF_OPERATOR_DIVIDE_3_2
#undef __FN_DEF_OPERATOR_ARITHMETIC_3_3
#undef __FN_DEF_OPERATOR_DIVIDE_3_3
#undef __FN_DEF_OPERATOR_ARITHMETIC_3_4
#undef __FN_DEF_OPERATOR_DIVIDE_3_4
#undef __FN_DEF_COMMON_3
#undef __FN_DEF_OPERATOR_ARITHMETIC_4_1
#undef __FN_DEF_OPERATOR_DIVIDE_4_1
#undef __FN_DEF_OPERATOR_ARITHMETIC_4_2
#undef __FN_DEF_OPERATOR_ARITHMETIC_4_3
#undef __FN_DEF_OPERATOR_DIVIDE_4_2
#undef __FN_DEF_OPERATOR_DIVIDE_4_3
#undef __FN_DEF_OPERATOR_ARITHMETIC_4_4
#undef __FN_DEF_OPERATOR_DIVIDE_4_4
#undef __FN_DEF_COMMON_4
#undef __FN_DEF_COL_OPERATOR_ARITHMETIC
#undef __FN_DEF_COL_OPERATOR_ARITHMETIC_SCALARS
#undef __FN_DEF_COL_ARITHMETIC
#undef __FN_DEF_VEC


#ifndef PERIDOT_NO_NAMESPACE
} // namespace Pdt
#endif // !PERIDOT_NO_NAMESPACE
#endif // PERIDOT_C
#endif // !GEM_PERIDOT_VECTOR_HPP_
