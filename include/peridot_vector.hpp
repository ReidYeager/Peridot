
#ifndef GEM_PERIDOT_VECTOR_HPP_
#define GEM_PERIDOT_VECTOR_HPP_
#ifndef PERIDOT_C

#include <assert.h>
#include <math.h>

class Vec2;  class Vec3;  class Vec4;
class Vec2D; class Vec3D; class Vec4D;
class Vec2I; class Vec3I; class Vec4I;
class Vec2U; class Vec3U; class Vec4U;

#define FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, symbol) \
inline base  operator symbol   (const alt other) const; \
inline base& operator symbol##=(const alt other);

#define FN_DEC_OPERATORS(base, baseType, alt) \
FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, +) \
FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, -) \
FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, *) \
FN_DEC_OPERATOR_ARITHMETIC(base, baseType, alt, /)

#define FN_DEC_COMMON(base, baseType) \
FN_DEC_OPERATORS(base, baseType, float) \
FN_DEC_OPERATORS(base, baseType, double) \
FN_DEC_OPERATORS(base, baseType, int) \
FN_DEC_OPERATORS(base, baseType, unsigned int) \
FN_DEC_OPERATORS(base, baseType, Vec2) \
FN_DEC_OPERATORS(base, baseType, Vec3) \
FN_DEC_OPERATORS(base, baseType, Vec4) \
FN_DEC_OPERATORS(base, baseType, Vec2D) \
FN_DEC_OPERATORS(base, baseType, Vec3D) \
FN_DEC_OPERATORS(base, baseType, Vec4D) \
FN_DEC_OPERATORS(base, baseType, Vec2I) \
FN_DEC_OPERATORS(base, baseType, Vec3I) \
FN_DEC_OPERATORS(base, baseType, Vec4I) \
FN_DEC_OPERATORS(base, baseType, Vec2U) \
FN_DEC_OPERATORS(base, baseType, Vec3U) \
FN_DEC_OPERATORS(base, baseType, Vec4U) \
inline float Magnitude() const; \
inline base Normal() const; \
inline base& Normalize();\

#define DEF_VEC_2(baseType, suffix)                                   \
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
  FN_DEC_COMMON(Vec2##suffix, baseType)                               \
  inline bool operator==(const Vec2##suffix& other) const             \
  {                                                                   \
    return x == other.x && y == other.y;                              \
  }                                                                   \
  inline float Dot(const Vec2##suffix& other) const                   \
  {                                                                   \
    return float((x * other.x) + (y * other.y));                      \
  }                                                                   \
};

#define DEF_VEC_3(baseType, suffix)                                                  \
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
  FN_DEC_COMMON(Vec3##suffix, baseType)                                              \
  inline bool operator==(const Vec3##suffix& other) const                            \
  {                                                                                  \
    return x == other.x && y == other.y && z == other.z;                             \
  }                                                                                  \
  inline float Dot(const Vec3##suffix& other) const                                  \
  {                                                                                  \
    return float((x * other.x) + (y * other.y) + (z * other.z));                     \
  }                                                                                  \
  inline Vec3##suffix Cross(const Vec3##suffix& other)   const                       \
  {                                                                                  \
    return Vec3##suffix {                                                            \
      y * other.z - z * other.y,                                                     \
      z * other.x - x * other.z,                                                     \
      x * other.y - y * other.x };                                                   \
  }                                                                                  \
  inline float Angle(const Vec3##suffix& other)   const                              \
  {                                                                                  \
    float angle = Dot(other);                                                        \
    angle /= (Magnitude() * other.Magnitude());                                      \
    return acosf(angle);                                                             \
  }                                                                                  \
  inline Vec3##suffix Project(const Vec3##suffix& other) const                       \
  {                                                                                  \
    Vec3##suffix p = other.Normal();                                                 \
    return p * Dot(other);                                                           \
  }                                                                                  \
};

#define DEF_VEC_4(baseType, suffix)                                                                        \
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
  FN_DEC_COMMON(Vec4##suffix, baseType)                                                                    \
  inline bool operator==(const Vec4##suffix& other) const                                                  \
  {                                                                                                        \
    return x == other.x && y == other.y && z == other.z && w == other.w;                                   \
  }                                                                                                        \
  inline float Dot(const Vec4##suffix& other) const                                                        \
  {                                                                                                        \
    return float((x * other.x) + (y * other.y) + (z * other.z) + (w * other.w));                           \
  }                                                                                                        \
};

DEF_VEC_2(float,)
DEF_VEC_3(float,)
DEF_VEC_4(float,)
DEF_VEC_2(double, D)
DEF_VEC_3(double, D)
DEF_VEC_4(double, D)
DEF_VEC_2(int, I)
DEF_VEC_3(int, I)
DEF_VEC_4(int, I)
DEF_VEC_2(unsigned int, U)
DEF_VEC_3(unsigned int, U)
DEF_VEC_4(unsigned int, U)

// Vec2
// ============================================================

// Arithmetic operators

#define FN_DEF_OPERATOR_ARITHMETIC_2_1(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other, y symbol (baseType)other }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other; y symbol##=(baseType)other; return *this; }

#define FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other.x, y symbol (baseType)other.y }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other.x; y symbol##=(baseType)other.y; return *this; }

#define FN_DEF_OPERATOR_ARITHMETIC_2_3(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)
#define FN_DEF_OPERATOR_ARITHMETIC_2_4(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)

// Common

#define FN_DEF_COMMON_2(base, baseType)                \
float base::Magnitude() const                          \
{                                                      \
  return (float)sqrt((x * x) + (y * y));               \
}                                                      \
base base::Normal() const                              \
{                                                      \
  float mag = Magnitude();                             \
  return base{ (baseType)(x/mag), (baseType)(y/mag) }; \
}                                                      \
base& base::Normalize()                                \
{                                                      \
  float mag = Magnitude();                             \
  x /= mag;                                            \
  y /= mag;                                            \
  return *this;                                        \
}

// Vec3
// ============================================================

// Arithmetic operators

#define FN_DEF_OPERATOR_ARITHMETIC_3_1(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other, y symbol (baseType)other, z symbol (baseType)other }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other; y symbol##=(baseType)other; z symbol##=(baseType)other; return *this; }

#define FN_DEF_OPERATOR_ARITHMETIC_3_2(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)

#define FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other.x, y symbol (baseType)other.y, z symbol (baseType)other.z }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other.x; y symbol##=(baseType)other.y; z symbol##=(baseType)other.z; return *this; }

#define FN_DEF_OPERATOR_ARITHMETIC_3_4(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)

// Common

#define FN_DEF_COMMON_3(base, baseType)                                   \
float base::Magnitude() const                                             \
{                                                                         \
  return (float)sqrt((x * x) + (y * y) + (z * z));                        \
}                                                                         \
base base::Normal() const                                                 \
{                                                                         \
  float mag = Magnitude();                                                \
  return base{ (baseType)(x/mag), (baseType)(y/mag), (baseType)(z/mag) }; \
}                                                                         \
base& base::Normalize()                                                   \
{                                                                         \
  float mag = Magnitude();                                                \
  x /= mag;                                                               \
  y /= mag;                                                               \
  z /= mag;                                                               \
  return *this;                                                           \
}

// Vec4
// ============================================================

// Arithmetic operators

#define FN_DEF_OPERATOR_ARITHMETIC_4_1(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other, y symbol (baseType)other, z symbol (baseType)other, w symbol (baseType)other }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other; y symbol##=(baseType)other; z symbol##=(baseType)other; w symbol##=(baseType)other; return *this; }

#define FN_DEF_OPERATOR_ARITHMETIC_4_2(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_2_2(base, baseType, alt, symbol)
#define FN_DEF_OPERATOR_ARITHMETIC_4_3(base, baseType, alt, symbol) FN_DEF_OPERATOR_ARITHMETIC_3_3(base, baseType, alt, symbol)

#define FN_DEF_OPERATOR_ARITHMETIC_4_4(base, baseType, alt, symbol)\
base  base::operator symbol (const alt other) const { return base{ x symbol (baseType)other.x, y symbol (baseType)other.y, z symbol (baseType)other.z, w symbol (baseType)other.w }; } \
base& base::operator symbol##= (const alt other) {  x symbol##=(baseType)other.x; y symbol##=(baseType)other.y; z symbol##=(baseType)other.z; w symbol##=(baseType)other.w; return *this; }


// Common

#define FN_DEF_COMMON_4(base, baseType)                                                      \
float base::Magnitude() const                                                                \
{                                                                                            \
  return (float)sqrt((x * x) + (y * y) + (z * z) + (w * w));                                 \
}                                                                                            \
base base::Normal() const                                                                    \
{                                                                                            \
  float mag = Magnitude();                                                                   \
  return base{ (baseType)(x/mag), (baseType)(y/mag), (baseType)(z/mag), (baseType)(w/mag) }; \
}                                                                                            \
base& base::Normalize()                                                                      \
{                                                                                            \
  float mag = Magnitude();                                                                   \
  x /= mag;                                                                                  \
  y /= mag;                                                                                  \
  z /= mag;                                                                                  \
  w /= mag;                                                                                  \
  return *this;                                                                              \
}

// XXX
// ============================================================

#define FN_DEF_COL_OPERATOR_ARITHMETIC(base, baseType, count, alt, altType, altCount)\
FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount (base, baseType, alt, +)\
FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount (base, baseType, alt, -)\
FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount (base, baseType, alt, *)\
FN_DEF_OPERATOR_ARITHMETIC_##count##_##altCount (base, baseType, alt, /)

#define DUPLICATE_FOR_ALL(thing, base, baseType, count)\
thing(base, baseType, count, float,        float,        1) \
thing(base, baseType, count, double,       double,       1) \
thing(base, baseType, count, int,          int,          1) \
thing(base, baseType, count, unsigned int, unsigned int, 1) \
thing(base, baseType, count, Vec2,         float,        2) \
thing(base, baseType, count, Vec2D,        double,       2) \
thing(base, baseType, count, Vec2I,        int,          2) \
thing(base, baseType, count, Vec2U,        unsigned int, 2) \
thing(base, baseType, count, Vec3,         float,        3) \
thing(base, baseType, count, Vec3D,        double,       3) \
thing(base, baseType, count, Vec3I,        int,          3) \
thing(base, baseType, count, Vec3U,        unsigned int, 3) \
thing(base, baseType, count, Vec4,         float,        4) \
thing(base, baseType, count, Vec4D,        double,       4) \
thing(base, baseType, count, Vec4I,        int,          4) \
thing(base, baseType, count, Vec4U,        unsigned int, 4)

#define FN_DEF_VEC(base, baseType, count)\
DUPLICATE_FOR_ALL(FN_DEF_COL_OPERATOR_ARITHMETIC, base, baseType, count)\
FN_DEF_COMMON_##count(base, baseType)

FN_DEF_VEC(Vec2, float, 2);
FN_DEF_VEC(Vec3, float, 3);
FN_DEF_VEC(Vec4, float, 4);
FN_DEF_VEC(Vec2D, double, 2);
FN_DEF_VEC(Vec3D, double, 3);
FN_DEF_VEC(Vec4D, double, 4);
FN_DEF_VEC(Vec2I, int, 2);
FN_DEF_VEC(Vec3I, int, 3);
FN_DEF_VEC(Vec4I, int, 4);
FN_DEF_VEC(Vec2U, unsigned int, 2);
FN_DEF_VEC(Vec3U, unsigned int, 3);
FN_DEF_VEC(Vec4U, unsigned int, 4);

#undef FN_DEC_OPERATOR_ARITHMETIC
#undef FN_DEC_OPERATORS
#undef FN_DEC_COMMON
#undef DEF_VEC_2
#undef DEF_VEC_3
#undef DEF_VEC_4
#undef FN_DEF_OPERATOR_ARITHMETIC_2_1
#undef FN_DEF_OPERATOR_ARITHMETIC_2_2
#undef FN_DEF_OPERATOR_ARITHMETIC_2_3
#undef FN_DEF_OPERATOR_ARITHMETIC_2_4
#undef FN_DEF_COMMON_2
#undef FN_DEF_OPERATOR_ARITHMETIC_3_1
#undef FN_DEF_OPERATOR_ARITHMETIC_3_2
#undef FN_DEF_OPERATOR_ARITHMETIC_3_3
#undef FN_DEF_OPERATOR_ARITHMETIC_3_4
#undef FN_DEF_COMMON_3
#undef FN_DEF_OPERATOR_ARITHMETIC_4_1
#undef FN_DEF_OPERATOR_ARITHMETIC_4_2
#undef FN_DEF_OPERATOR_ARITHMETIC_4_3
#undef FN_DEF_OPERATOR_ARITHMETIC_4_4
#undef FN_DEF_COMMON_4
#undef FN_DEF_COL_OPERATOR_ARITHMETIC
#undef DUPLICATE_FOR_ALL
#undef FN_DEF_VEC

#endif // PERIDOT_C
#endif // !GEM_PERIDOT_VECTOR_HPP_
