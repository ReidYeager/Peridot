
#ifndef GEM_PERIDOT_QUATERNION_HPP_
#define GEM_PERIDOT_QUATERNION_HPP_

#include "peridot_defines.h"

#ifndef PERIDOT_C

#ifndef PERIDOT_NO_NAMESPACE
namespace Pdt {
#endif // !PERIDOT_NO_NAMESPACE

#include "peridot_vector.hpp"
#include "peridot_matrix.hpp"

class Quaternion
{
public:
  union
  {
    float elements[4];
    struct
    {
      float x, y, z, w;
    };
    Vec4 vec;
  };

  Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
  Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
  Quaternion(const Quaternion& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
  Quaternion(const Vec4& vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}
  Quaternion(const Vec3& euler)
  {
    FromEuler(euler);
  }
  Quaternion(float pitch, float yaw, float roll)
  {
    FromEuler({pitch, yaw, roll});
  }

  inline Quaternion operator*(const Quaternion& other) const
  {
    return Quaternion{
      w* other.x + x * other.w + y * other.z - z * other.y,
      w* other.y + y * other.w + z * other.x - x * other.z,
      w* other.z + z * other.w + x * other.y - y * other.x,
      w* other.w - x * other.x - y * other.y - z * other.z
    };
  }

  inline Quaternion& operator*=(const Quaternion& other)
  {
    x = w * other.x + x * other.w + y * other.z - z * other.y;
    y = w * other.y + y * other.w + z * other.x - x * other.z;
    z = w * other.z + z * other.w + x * other.y - y * other.x;
    w = w * other.w - x * other.x - y * other.y - z * other.z;
    return *this;
  }

  inline Vec3 operator*(const Vec3& other) const
  {
    return Matrix() * other;
  }

  inline Quaternion operator+(const float& other) const
  {
    return vec + other;
  }
  inline Quaternion& operator+=(const float& other)
  {
    vec += other;
    return *this;
  }

  inline Quaternion operator-(const float& other) const
  {
    return vec - other;
  }
  inline Quaternion& operator-=(const float& other)
  {
    vec -= other;
    return *this;
  }

  inline Quaternion operator*(const float& other) const
  {
    return vec * other;
  }
  inline Quaternion& operator*=(const float& other)
  {
    vec *= other;
    return *this;
  }

  inline Quaternion operator/(const float& other) const
  {
    return vec / other;
  }
  inline Quaternion& operator/=(const float& other)
  {
    vec /= other;
    return *this;
  }

  inline float Dot(const Quaternion& other) const
  {
    return vec.Dot(other.vec);
  }

  inline Quaternion Inverse() const
  {
    return Quaternion{ -x, -y, -z, w };
  }

  inline Quaternion Invert()
  {
    x *= -1;
    y *= -1;
    z *= -1;
    return *this;
  }

  inline Quaternion Normal() const
  {
    return vec.Normal();
  }

  inline Quaternion& Normalize()
  {
    vec.Normalize();
    return *this;
  }

  inline Mat4 Matrix() const
  {
    // Column major
    return Mat4 {
      2.0f * (w * w + x * x) - 1.0f, 2.0f * (x * y + w * z)       , 2.0f * (x * z - w * y)       , 0.0f,
      2.0f * (x * y - w * z)       , 2.0f * (w * w + y * y) - 1.0f, 2.0f * (y * z + w * x)       , 0.0f,
      2.0f * (x * z + w * y)       , 2.0f * (y * z - w * x)       , 2.0f * (w * w + z * z) - 1.0f, 0.0f,
      0.0f                         , 0.0f                         , 0.0f                         , 1.0f,
    };
  }

  // TODO : understand this page https://www.ncbi.nlm.nih.gov/pmc/articles/PMC9648712/
  //inline Vec3 Euler() const
  //{
  //  Vec3 out;
  //  return out;
  //}

  static Quaternion LookAt(Vec3 origin, Vec3 target, Vec3 up = Vec3{ 0.0f, 1.0f, 0.0f })
  {
    // TODO : Return here and actually absorb what is happening for a rewrite
    // Taken from Glm (quatLookAtRH(...))

    Vec3 direction = (target - origin).Normal();

    Vec3 col2 = -direction;

    Vec3 right = Cross(up, col2);
    Vec3 col0 = right * (1.0f / sqrt(PeriMax(0.00001, right.Dot(right))));
    Vec3 col1 = Cross(col2, col0);

    float fourXSquaredMinus1 = col0.x - col1.y - col2.z;
    float fourYSquaredMinus1 = col1.y - col0.x - col2.z;
    float fourZSquaredMinus1 = col2.z - col0.x - col1.y;
    float fourWSquaredMinus1 = col0.x + col1.y + col2.z;

    int biggestIndex = 3;
    float fourBiggestSquaredMinus1 = fourWSquaredMinus1;

    if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
    {
      fourBiggestSquaredMinus1 = fourXSquaredMinus1;
      biggestIndex = 0;
    }
    if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
    {
      fourBiggestSquaredMinus1 = fourYSquaredMinus1;
      biggestIndex = 1;
    }
    if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
    {
      fourBiggestSquaredMinus1 = fourZSquaredMinus1;
      biggestIndex = 2;
    }

    float biggestValue = sqrt(fourBiggestSquaredMinus1 + 1) * 0.5;
    float mult = 0.25 / biggestValue;

    switch (biggestIndex)
    {
    case 0:  return Quaternion{ biggestValue            , (col0.y + col1.x) * mult, (col2.x + col0.z) * mult, (col1.z - col2.y) * mult };
    case 1:  return Quaternion{ (col0.y + col1.x) * mult, biggestValue            , (col1.z + col2.y) * mult, (col2.x - col0.z) * mult };
    case 2:  return Quaternion{ (col2.x + col0.z) * mult, (col1.z + col2.y) * mult, biggestValue            , (col0.y - col1.x) * mult };
    case 3:  return Quaternion{ (col1.z - col2.y) * mult, (col2.x - col0.z) * mult, (col0.y - col1.x) * mult, biggestValue             };
    default: return Quaternion{ 0.0f, 0.0f, 0.0f, 1.0f };
    }
  }


private:
  void FromEuler(Vec3 euler)
  {
    euler *= 0.008726646; // (Degrees to radians) * 0.5

    float sp = sin(euler.x); // sin-pitch
    float cp = cos(euler.x); // cos-pitch
    float sy = sin(euler.y); // sin-yaw
    float cy = cos(euler.y); // cos-yaw
    float sr = sin(euler.z); // sin-roll
    float cr = cos(euler.z); // cos-roll

    vec = Vec4{
      cy*sp*cr + sy*cp*sr,
      sy*cp*cr - cy*sp*sr,
      cy*cp*sr - sy*sp*cr,
      cy*cp*cr + sy*sp*sr
    };
  }
};

// #if defined __cplusplus && !defined PERIDOT_C
#define QuaternionIdentity Quaternion{ 0.0f, 0.0f, 0.0f, 1.0f }

#ifndef PERIDOT_NO_NAMESPACE
} // namespace Pdt
#endif // !PERIDOT_NO_NAMESPACE
#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_QUATERNION_HPP_
