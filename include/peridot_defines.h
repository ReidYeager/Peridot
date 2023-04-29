
#ifndef GEM_PERIDOT_DEFINES_H_
#define GEM_PERIDOT_DEFINES_H_

#include <stdint.h>

// =====
// Vectors
// =====

#define PERI_DEF_VEC2(type, typeshort) \
typedef union Vec2##typeshort       \
{                                      \
  type elements[2];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
  };                                   \
} Vec2##typeshort;

#define PERI_DEF_VEC3(type, typeshort) \
typedef union Vec3##typeshort       \
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
typedef union Vec4##typeshort       \
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

PERI_DEF_VEC2(float,);
PERI_DEF_VEC3(float,);
PERI_DEF_VEC4(float,);

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
// Matrix
// =====

typedef union Mat4
{
  float elements[16];
  struct
  {
    union { Vec4 x, col0; };
    union { Vec4 y, col1; };
    union { Vec4 z, col2; };
    union { Vec4 w, col3; };
  };
} Mat4;


#endif // !GEM_PERIDOT_DEFINES_H_

