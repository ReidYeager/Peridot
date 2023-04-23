
#ifndef GEM_PERIDOT_DEFINES_H_
#define GEM_PERIDOT_DEFINES_H_

#include <stdint.h>

// =====
// Vectors
// =====

#define PERI_DEF_VEC2(type, typeshort) \
typedef union Vector2##typeshort       \
{                                      \
  type elements[2];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
  };                                   \
} Vector2##typeshort;

#define PERI_DEF_VEC3(type, typeshort) \
typedef union Vector3##typeshort       \
{                                      \
  type elements[3];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
    union { type z, b; };              \
  };                                   \
} Vector3##typeshort;

#define PERI_DEF_VEC4(type, typeshort) \
typedef union Vector4##typeshort       \
{                                      \
  type elements[4];                    \
  struct                               \
  {                                    \
    union { type x, r; };              \
    union { type y, g; };              \
    union { type z, b; };              \
    union { type w, a; };              \
  };                                   \
} Vector4##typeshort;

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


#endif // !GEM_PERIDOT_DEFINES_H_

