
#ifndef GEM_PERIDOT_QUATERNION_HPP_
#define GEM_PERIDOT_QUATERNION_HPP_

#include "peridot_defines.h"

#ifndef PERIDOT_C

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

  //inline Vec3 Euler() const
  //{
  //  return Vec3 { 0.0f, 0.0f, 0.0f };
  //}


private:
  void FromEuler(const Vec3& angles)
  {
    Vec3 euler(angles);
    euler *= 0.008726646f;

    Quaternion yaw = { 0.0f, (float)sin(euler.y), 0.0f, (float)cos(euler.y) };
    Quaternion pitch = { (float)sin(euler.x), 0.0f, 0.0f, (float)cos(euler.x) };
    Quaternion roll = { 0.0f, 0.0f, (float)sin(euler.z), (float)cos(euler.z) };

    vec = (yaw * pitch * roll).Normal().vec;
  }
};

#ifdef __clang__
#define quaternionIdentity (Quaternion){ 0.0f, 0.0f, 0.0f, 1.0f }
#else
#define quaternionIdentity { 0.0f, 0.0f, 0.0f, 1.0f }
#endif

#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_QUATERNION_HPP_
