
#ifndef GEM_PERIDOT_PROJECTION_H_
#define GEM_PERIDOT_PROJECTION_H_

#include "peridot_defines.h"

#ifdef PERIDOT_C
#include "peridot_vector.h"
#include "peridot_matrix.h"
#include "peridot_quaternion.h"
#else
#include "peridot_vector.hpp"
#include "peridot_matrix.hpp"
#include "peridot_quaternion.hpp"

#ifndef PERIDOT_NO_NAMESPACE
namespace Pdt {
#endif // !PERIDOT_NO_NAMESPACE
#endif // PERIDOT_C

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
inline Mat4 ProjectionPerspectiveExtended(float _screenRatio, float guaranteedRatio, float _fovY, float _near, float _far)
{
  int lockX = (_screenRatio >= guaranteedRatio);
  float ratioX = lockX ? _screenRatio : guaranteedRatio;
  float ratioY = lockX ? 1.0f : _screenRatio / guaranteedRatio;

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

  Mat4 newMat = Mat4Identity;
  newMat.x.x = 2 / (right - left);
  newMat.y.y = 2 / (top - bottom);
  newMat.z.z = -2 / (_far - _near);

  return newMat;
}

#if !defined PERIDOT_C && !defined PERIDOT_NO_NAMESPACE
} // namespace Pdt
#endif // !PERIDOT_C && !PERIDOT_NO_NAMESPACE

#endif // !GEM_PERIDOT_PROJECTION_H_