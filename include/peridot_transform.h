
#ifndef GEM_PERIDOT_TRANSFORM_H_
#define GEM_PERIDOT_TRANSFORM_H_

#include "include/peridot_defines.h"
#include "include/peridot_vector.h"
#include "include/peridot_matrix.h"
#include "include/peridot_quaternion.h"

inline Mat4 TransformToMat4(Vec3 _position, Quaternion _rotation, Vec3 _scale)
{
  Mat4 newMat = QuaternionToMat4(_rotation);

  newMat.col3.x = _position.x;
  newMat.col3.y = _position.y;
  newMat.col3.z = _position.z;

  newMat.col0.x *= _scale.x;
  newMat.col1.y *= _scale.y;
  newMat.col2.z *= _scale.z;

  return newMat;
}

inline Mat4 TransformEulerToMat4(Vec3 _position, Vec3 _eulerRotation, Vec3 _scale)
{
  Quaternion rotation = QuaternionFromEuler(_eulerRotation);
  return TransformToMat4(_position, rotation, _scale);
}

// TODO : Camera projection matrices

#include <stdio.h>

inline Mat4 ProjectionPerspective(float _screenRatio, float _fov, float _nearPlane, float _farPlane)
{
  const float hdRatio = 1.77777777778f; // 16:9 ratio
  int lockX = (_screenRatio >= hdRatio);

  float ratioX = lockX ? _screenRatio : 1.0f;
  float ratioY = lockX ? 1.0f : _screenRatio;

  float tanFovHalf = tanf(PDT_DEGREES_TO_RADIANS(_fov / 2.0));
  float d = 1.0 / tanFovHalf;

  float a = (-_farPlane - _nearPlane)/(_nearPlane - _farPlane);
  float b = (2 * _farPlane * _nearPlane)/(_nearPlane - _farPlane);

  Mat4 newMat = {
    d / ratioX, 0.0f      , 0.0f, 0.0f,
    0.0f      , d * ratioY, 0.0f, 0.0f,
    0.0f      , 0.0f      , a, 1.0f,
    0.0f      , 0.0f      , b, 0.0f
  };

  return newMat;
}

inline Mat4 ProjectionOrthographic()
{
  Mat4 newMat = IdentityMat4;



  return newMat;
}


#endif // !GEM_PERIDOT_TRANSFORM_H_
