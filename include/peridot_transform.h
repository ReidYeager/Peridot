
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


#endif // !GEM_PERIDOT_TRANSFORM_H_
