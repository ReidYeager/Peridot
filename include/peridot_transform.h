
#ifndef GEM_PERIDOT_TRANSFORM_H_
#define GEM_PERIDOT_TRANSFORM_H_

#include "include/peridot_defines.h"
#include "include/peridot_vector.h"
#include "include/peridot_matrix.h"
#include "include/peridot_quaternion.h"

inline Mat4 TransformToMat4(Vec3 _position, Quaternion _rotation, Vec3 _scale)
{
  Mat4 newMat = mat4Identity;

  newMat.col0.x *= _scale.x;
  newMat.col1.y *= _scale.y;
  newMat.col2.z *= _scale.z;

  newMat = Mat4MuliplyMat4(QuaternionToMat4(_rotation), newMat);

  newMat.col3.x += _position.x;
  newMat.col3.y += _position.y;
  newMat.col3.z += _position.z;

  return newMat;
}

inline Mat4 TransformEulerToMat4(Vec3 _position, Vec3 _eulerRotation, Vec3 _scale)
{
  Quaternion rotation = QuaternionFromEuler(_eulerRotation);
  return TransformToMat4(_position, rotation, _scale);
}

// TODO : Camera projection matrices

#include <stdio.h>

inline Mat4 ProjectionPerspective(float _screenRatio, float _fovY, float _near, float _far)
{
  float tanHalfFov = tanf(PERI_DEGREES_TO_RADIANS(_fovY) / 2.0);

  Mat4 newMat = { 0 };
  newMat.x.x = 1 / (_screenRatio * tanHalfFov);
  newMat.y.y = PERI_VULKAN_COPE / (tanHalfFov);
  newMat.z.z = -(_far + _near) / (_far - _near);
  newMat.z.w = -1;
  newMat.w.z = -(2 * _far * _near) / (_far - _near);

  return newMat;
}

// Perspective projection matrix guaranteed to tightly contain the full 16x9 frame within itself
// Alternative to cropping the frame for other ratios but can introduce warping at extreme ratios
inline Mat4 ProjectionPerspectiveExtended(float _screenRatio, float _fovY, float _near, float _far)
{
  const double hdRatio = 1.77777777778; // 16:9 ratio
  int lockX = (_screenRatio >= hdRatio);
  float ratioX = lockX ? _screenRatio : hdRatio;
  float ratioY = lockX ? 1.0f :  _screenRatio / hdRatio;

  float tanHalfFov = tanf(PERI_DEGREES_TO_RADIANS(_fovY) / 2.0);

  Mat4 newMat = { 0 };
  newMat.x.x = 1 / (ratioX * tanHalfFov);
  newMat.y.y = PERI_VULKAN_COPE * ratioY / (tanHalfFov);
  newMat.z.z = -(_far + _near) / (_far - _near);
  newMat.z.w = -1;
  newMat.w.z = -(2 * _far * _near) / (_far - _near);

  return newMat;
}

inline Mat4 ProjectionOrthographic(float _width, float _height, float _near, float _far)
{
  float hwidth = _width / 2.0f;
  float hheight = _height / 2.0f;

  float left = -hwidth;
  float right = hwidth;
  float top = -hheight;
  float bottom = hheight;

  Mat4 newMat = mat4Identity;
  newMat.x.x = 2 / (right - left);
  newMat.y.y = 2 / (top - bottom);
  newMat.z.z = -2 / (_far - _near);

  return newMat;
}


#endif // !GEM_PERIDOT_TRANSFORM_H_
