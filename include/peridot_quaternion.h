
#ifndef GEM_PERIDOT_QUATERNION_H_
#define GEM_PERIDOT_QUATERNION_H_
#ifdef PERIDOT_C

#include "peridot_defines.h"
#include "peridot_vector.h"
#include "peridot_matrix.h"

typedef Vec4 Quaternion;

inline Quaternion QuaternionMultiplyQuaternion(Quaternion _left, Quaternion _right);
inline Quaternion QuaternionNormalize(Quaternion _quaternion);

inline Quaternion QuaternionFromEuler(Vec3 _euler)
{
  _euler = Vec3MultiplyFloat(_euler, 0.008726646f);

  Quaternion yaw   = { 0.0f, (float)sin(_euler.y), 0.0f, (float)cos(_euler.y) };
  Quaternion pitch = { (float)sin(_euler.x), 0.0f, 0.0f, (float)cos(_euler.x) };
  Quaternion roll  = { 0.0f, 0.0f, (float)sin(_euler.z), (float)cos(_euler.z) };

  Quaternion newQuat = QuaternionMultiplyQuaternion(yaw, pitch);
  newQuat = QuaternionMultiplyQuaternion(newQuat, roll);
  return QuaternionNormalize(newQuat);
}

//inline Vec3 QuaternionToEuler(Quaternion _quaternion)
//{
//  Vec3 euler = { 0 };
//
//
//
//  return euler;
//}

inline Quaternion QuaternionMultiplyQuaternion(Quaternion _left, Quaternion _right)
{
  Quaternion newQuat = {
    _left.w * _right.x + _left.x * _right.w + _left.y * _right.z - _left.z * _right.y, // X
    _left.w * _right.y + _left.y * _right.w + _left.z * _right.x - _left.x * _right.z, // Y
    _left.w * _right.z + _left.z * _right.w + _left.x * _right.y - _left.y * _right.x, // Z
    _left.w * _right.w - _left.x * _right.x - _left.y * _right.y - _left.z * _right.z  // W
  };

  return newQuat;
}

inline Quaternion QuaternionAddFloat(Quaternion _quaternion, float _value)
{
  _quaternion.x += _value;
  _quaternion.y += _value;
  _quaternion.z += _value;
  _quaternion.w += _value;
  return _quaternion;
}

inline Quaternion QuaternionSubtractFloat(Quaternion _quaternion, float _value)
{
  _quaternion.x -= _value;
  _quaternion.y -= _value;
  _quaternion.z -= _value;
  _quaternion.w -= _value;
  return _quaternion;
}

inline Quaternion QuaternionMultiplyFloat(Quaternion _quaternion, float _value)
{
  _quaternion.x *= _value;
  _quaternion.y *= _value;
  _quaternion.z *= _value;
  _quaternion.w *= _value;
  return _quaternion;
}

inline Quaternion QuaternionDivideFloat(Quaternion _quaternion, float _value)
{
  _quaternion.x /= _value;
  _quaternion.y /= _value;
  _quaternion.z /= _value;
  _quaternion.w /= _value;
  return _quaternion;
}

inline float QuaternionDot(Quaternion _a, Quaternion _b)
{
  return (float)(_a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w);
}

inline Quaternion QuaternionInvert(Quaternion _quaternion)
{
  Quaternion newQuat = { -_quaternion.x, -_quaternion.y, -_quaternion.z, _quaternion.w };
  return newQuat;
}

inline Quaternion QuaternionNormalize(Quaternion _quaternion)
{
  float magnitude = Vec4Magnitude(_quaternion);
  return QuaternionDivideFloat(_quaternion, magnitude);
}

inline Mat4 QuaternionToMat4(Quaternion _quaternion)
{
  float x = _quaternion.x;
  float y = _quaternion.y;
  float z = _quaternion.z;
  float w = _quaternion.w;

  // Column major
  Mat4 newMat = {
    2.0f*(w*w + x*x) - 1.0f, 2.0f*(x*y + w*z)       , 2.0f*(x*z - w*y)       , 0.0f,
    2.0f*(x*y - w*z)       , 2.0f*(w*w + y*y) - 1.0f, 2.0f*(y*z + w*x)       , 0.0f,
    2.0f*(x*z + w*y)       , 2.0f*(y*z - w*x)       , 2.0f*(w*w + z*z) - 1.0f, 0.0f,
    0.0f                   , 0.0f                   , 0.0f                   , 1.0f,
  };

  return newMat;
}

inline Vec3 QuaternionMultiplyVec3(Quaternion _quaternion, Vec3 _vector)
{
  Mat4 qMat = QuaternionToMat4(_quaternion);
  return Mat4MultiplyVec3(qMat, _vector);
}

#define QuaternionIdentity Quaternion{ 0.0f, 0.0f, 0.0f, 1.0f }

#endif // PERIDOT_C
#endif // !GEM_PERIDOT_QUATERNION_H_