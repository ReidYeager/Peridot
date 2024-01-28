
#ifndef GEM_PERIDOT_MATRIX_HPP_
#define GEM_PERIDOT_MATRIX_HPP_
#ifndef PERIDOT_C

#include "peridot_defines.h"
#include "peridot_vector.hpp"

class Mat4
{
public:
  union
  {
    float elements[16];
    struct
    {
      union { Vec4 x, col0; };
      union { Vec4 y, col1; };
      union { Vec4 z, col2; };
      union { Vec4 w, col3; };
    };
  };

  Mat4(float diagonal = 0.0f) : elements {
    diagonal, 0.0f, 0.0f, 0.0f,
    0.0f, diagonal, 0.0f, 0.0f,
    0.0f, 0.0f, diagonal, 0.0f,
    0.0f, 0.0f, 0.0f, diagonal } { }

  Mat4(
    float i0,  float i1,  float i2,  float i3,
    float i4,  float i5,  float i6,  float i7,
    float i8,  float i9,  float i10, float i11,
    float i12, float i13, float i14, float i15)
    : elements{
      i0, i1, i2, i3,
      i4, i5, i6, i7,
      i8, i9, i10, i11,
      i12, i13, i14, i15} {}

  Mat4(float* elements, bool rowMajorInput)
  {
    elements[0] = elements[0];
    elements[1 + (3 * rowMajorInput)] = elements[1];
    elements[2 + (6 * rowMajorInput)] = elements[2];
    elements[3 + (9 * rowMajorInput)] = elements[3];
    elements[4 - (3 * rowMajorInput)] = elements[4];
    elements[5] = elements[5];
    elements[6 + (3 * rowMajorInput)] = elements[6];
    elements[7 + (6 * rowMajorInput)] = elements[7];
    elements[8 - (6 * rowMajorInput)] = elements[8];
    elements[9 - (3 * rowMajorInput)] = elements[9];
    elements[10] = elements[10];
    elements[11 + (3 * rowMajorInput)] = elements[11];
    elements[12 - (9 * rowMajorInput)] = elements[12];
    elements[13 - (6 * rowMajorInput)] = elements[13];
    elements[14 - (3 * rowMajorInput)] = elements[14];
    elements[15] = elements[15];
  }

  Mat4(const Mat4& other)
  {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
  }

  inline bool operator==(const Mat4& other) const
  {
    return elements[0]  == other.elements[0]
      &&   elements[1]  == other.elements[1]
      &&   elements[2]  == other.elements[2]
      &&   elements[3]  == other.elements[3]
      &&   elements[4]  == other.elements[4]
      &&   elements[5]  == other.elements[5]
      &&   elements[6]  == other.elements[6]
      &&   elements[7]  == other.elements[7]
      &&   elements[8]  == other.elements[8]
      &&   elements[9]  == other.elements[9]
      &&   elements[10] == other.elements[10]
      &&   elements[11] == other.elements[11]
      &&   elements[12] == other.elements[12]
      &&   elements[13] == other.elements[13]
      &&   elements[14] == other.elements[14]
      &&   elements[15] == other.elements[15];
  }

  inline Mat4 Transposed() const
  {
    return Mat4{
      x.x, y.x, z.x, w.x,
      x.y, y.y, z.y, w.y,
      x.z, y.z, z.z, w.z,
      x.w, y.w, z.w, w.w };
  }

  inline Mat4& Transpose()
  {
    *this = Mat4{
      x.x, y.x, z.x, w.x,
      x.y, y.y, z.y, w.y,
      x.z, y.z, z.z, w.z,
      x.w, y.w, z.w, w.w };

    return *this;
  }

  inline Mat4 operator*(const float& other) const
  {
    return Mat4{
      x.x * other, x.y * other, x.z * other, x.w * other,
      y.x * other, y.y * other, y.z * other, y.w * other,
      z.x * other, z.y * other, z.z * other, z.w * other,
      w.x * other, w.y * other, w.z * other, w.w * other
    };
  }

  inline Mat4& operator*=(const float& other)
  {
    x *= other;
    y *= other;
    z *= other;
    w *= other;
    return *this;
  }

  inline Vec3 operator*(const Vec3& other) const
  {
    return Vec3{
      x.x* other.x + y.x * other.y + z.x * other.z,
      x.y* other.x + y.y * other.y + z.y * other.z,
      x.z* other.x + y.z * other.y + z.z * other.z };
  }

  inline Vec4 operator*(const Vec4& other) const
  {
    return Vec4{ x.Dot(other), y.Dot(other), z.Dot(other), w.Dot(other) };
  }

  inline Mat4 operator*(const Mat4& other) const
  {
    Mat4 t = Transposed();

    return Mat4{
    t.x.Dot(other.x), t.y.Dot(other.x), t.z.Dot(other.x), t.w.Dot(other.x),
    t.x.Dot(other.y), t.y.Dot(other.y), t.z.Dot(other.y), t.w.Dot(other.y),
    t.x.Dot(other.z), t.y.Dot(other.z), t.z.Dot(other.z), t.w.Dot(other.z),
    t.x.Dot(other.w), t.y.Dot(other.w), t.z.Dot(other.w), t.w.Dot(other.w) };
  }

  inline Mat4& Invert()
  {
    *this = Inverted();
    return *this;
  }

  inline Mat4 Inverted() const
  {
    Mat4 newMat;
    double determinant;

    // Row 0 =====

    newMat.elements[ 0] =
        elements[ 5] * elements[10] * elements[15]
      - elements[ 5] * elements[11] * elements[14]
      - elements[ 9] * elements[ 6] * elements[15]
      + elements[ 9] * elements[ 7] * elements[14]
      + elements[13] * elements[ 6] * elements[11]
      - elements[13] * elements[ 7] * elements[10];

    newMat.elements[ 4] =
      - elements[ 4] * elements[10] * elements[15]
      + elements[ 4] * elements[11] * elements[14]
      + elements[ 8] * elements[ 6] * elements[15]
      - elements[ 8] * elements[ 7] * elements[14]
      - elements[12] * elements[ 6] * elements[11]
      + elements[12] * elements[ 7] * elements[10];

    newMat.elements[ 8] =
        elements[ 4] * elements[ 9] * elements[15]
      - elements[ 4] * elements[11] * elements[13]
      - elements[ 8] * elements[ 5] * elements[15]
      + elements[ 8] * elements[ 7] * elements[13]
      + elements[12] * elements[ 5] * elements[11]
      - elements[12] * elements[ 7] * elements[ 9];

    newMat.elements[12] =
      - elements[ 4] * elements[ 9] * elements[14]
      + elements[ 4] * elements[10] * elements[13]
      + elements[ 8] * elements[ 5] * elements[14]
      - elements[ 8] * elements[ 6] * elements[13]
      - elements[12] * elements[ 5] * elements[10]
      + elements[12] * elements[ 6] * elements[ 9];

    determinant =
        (double)elements[0] * (double)newMat.elements[0]
      + (double)elements[1] * (double)newMat.elements[4]
      + (double)elements[2] * (double)newMat.elements[8]
      + (double)elements[3] * (double)newMat.elements[12];

    if (determinant == 0)
    {
      // No inverse exists. Don't calculate the rest
      return *this;
    }

    // Row 1 =====

    newMat.elements[ 1] =
      - elements[ 1] * elements[10] * elements[15]
      + elements[ 1] * elements[11] * elements[14]
      + elements[ 9] * elements[ 2] * elements[15]
      - elements[ 9] * elements[ 3] * elements[14]
      - elements[13] * elements[ 2] * elements[11]
      + elements[13] * elements[ 3] * elements[10];

    newMat.elements[ 5] =
        elements[ 0] * elements[10] * elements[15]
      - elements[ 0] * elements[11] * elements[14]
      - elements[ 8] * elements[ 2] * elements[15]
      + elements[ 8] * elements[ 3] * elements[14]
      + elements[12] * elements[ 2] * elements[11]
      - elements[12] * elements[ 3] * elements[10];

    newMat.elements[ 9] =
      - elements[ 0] * elements[ 9] * elements[15]
      + elements[ 0] * elements[11] * elements[13]
      + elements[ 8] * elements[ 1] * elements[15]
      - elements[ 8] * elements[ 3] * elements[13]
      - elements[12] * elements[ 1] * elements[11]
      + elements[12] * elements[ 3] * elements[ 9];

    newMat.elements[13] =
        elements[ 0] * elements[ 9] * elements[14]
      - elements[ 0] * elements[10] * elements[13]
      - elements[ 8] * elements[ 1] * elements[14]
      + elements[ 8] * elements[ 2] * elements[13]
      + elements[12] * elements[ 1] * elements[10]
      - elements[12] * elements[ 2] * elements[ 9];

    // Row 2 =====

    newMat.elements[ 2] =
        elements[ 1] * elements[ 6] * elements[15]
      - elements[ 1] * elements[ 7] * elements[14]
      - elements[ 5] * elements[ 2] * elements[15]
      + elements[ 5] * elements[ 3] * elements[14]
      + elements[13] * elements[ 2] * elements[ 7]
      - elements[13] * elements[ 3] * elements[ 6];

    newMat.elements[ 6] =
      - elements[ 0] * elements[ 6] * elements[15]
      + elements[ 0] * elements[ 7] * elements[14]
      + elements[ 4] * elements[ 2] * elements[15]
      - elements[ 4] * elements[ 3] * elements[14]
      - elements[12] * elements[ 2] * elements[ 7]
      + elements[12] * elements[ 3] * elements[ 6];

    newMat.elements[10] =
        elements[ 0] * elements[ 5] * elements[15]
      - elements[ 0] * elements[ 7] * elements[13]
      - elements[ 4] * elements[ 1] * elements[15]
      + elements[ 4] * elements[ 3] * elements[13]
      + elements[12] * elements[ 1] * elements[ 7]
      - elements[12] * elements[ 3] * elements[ 5];

    newMat.elements[14] =
      - elements[ 0] * elements[ 5] * elements[14]
      + elements[ 0] * elements[ 6] * elements[13]
      + elements[ 4] * elements[ 1] * elements[14]
      - elements[ 4] * elements[ 2] * elements[13]
      - elements[12] * elements[ 1] * elements[ 6]
      + elements[12] * elements[ 2] * elements[ 5];

    // Row 3 =====

    newMat.elements[ 3] =
      - elements[ 1] * elements[ 6] * elements[11]
      + elements[ 1] * elements[ 7] * elements[10]
      + elements[ 5] * elements[ 2] * elements[11]
      - elements[ 5] * elements[ 3] * elements[10]
      - elements[ 9] * elements[ 2] * elements[ 7]
      + elements[ 9] * elements[ 3] * elements[ 6];

    newMat.elements[ 7] =
        elements[ 0] * elements[ 6] * elements[11]
      - elements[ 0] * elements[ 7] * elements[10]
      - elements[ 4] * elements[ 2] * elements[11]
      + elements[ 4] * elements[ 3] * elements[10]
      + elements[ 8] * elements[ 2] * elements[ 7]
      - elements[ 8] * elements[ 3] * elements[ 6];

    newMat.elements[11] =
      - elements[ 0] * elements[ 5] * elements[11]
      + elements[ 0] * elements[ 7] * elements[ 9]
      + elements[ 4] * elements[ 1] * elements[11]
      - elements[ 4] * elements[ 3] * elements[ 9]
      - elements[ 8] * elements[ 1] * elements[ 7]
      + elements[ 8] * elements[ 3] * elements[ 5];

    newMat.elements[15] =
        elements[ 0] * elements[ 5] * elements[10]
      - elements[ 0] * elements[ 6] * elements[ 9]
      - elements[ 4] * elements[ 1] * elements[10]
      + elements[ 4] * elements[ 2] * elements[ 9]
      + elements[ 8] * elements[ 1] * elements[ 6]
      - elements[ 8] * elements[ 2] * elements[ 5];

    determinant = 1.0 / determinant;
    newMat *= (float)determinant;

    return newMat;
  }

};

#ifdef __clang__
#define mat4Identity (Mat4) { \
  1.0f, 0.0f, 0.0f, 0.0f,     \
  0.0f, 1.0f, 0.0f, 0.0f,     \
  0.0f, 0.0f, 1.0f, 0.0f,     \
  0.0f, 0.0f, 0.0f, 1.0f      \
}
#else
#define mat4Identity {    \
  1.0f, 0.0f, 0.0f, 0.0f, \
  0.0f, 1.0f, 0.0f, 0.0f, \
  0.0f, 0.0f, 1.0f, 0.0f, \
  0.0f, 0.0f, 0.0f, 1.0f  \
}
#endif

#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_MATRIX_HPP_
