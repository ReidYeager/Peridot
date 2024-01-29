
#ifndef GEM_PERIDOT_TRANSFORM_H_
#define GEM_PERIDOT_TRANSFORM_H_
#ifdef PERIDOT_C

#include "peridot_defines.h"
#include "peridot_vector.h"
#include "peridot_matrix.h"
#include "peridot_quaternion.h"

typedef struct Transform
{
  Vec3 position;
  Vec3 rotation;
  Vec3 scale;
} Transform;

inline Mat4 TransformToMat4(Transform _transform)
{
  Mat4 newMat = Mat4Identity;

  newMat.col0.x *= _transform.scale.x;
  newMat.col1.y *= _transform.scale.y;
  newMat.col2.z *= _transform.scale.z;

  Quaternion rotationQuat = QuaternionFromEuler(_transform.rotation);
  newMat = Mat4MuliplyMat4(QuaternionToMat4(rotationQuat), newMat);

  newMat.col3.x += _transform.position.x;
  newMat.col3.y += _transform.position.y;
  newMat.col3.z += _transform.position.z;

  return newMat;
}

#define TransformIdentity Transform{ { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } }

#endif // PERIDOT_C
#endif // !GEM_PERIDOT_TRANSFORM_H_
