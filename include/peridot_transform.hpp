
#ifndef GEM_PERIDOT_TRANSFORM_HPP_
#define GEM_PERIDOT_TRANSFORM_HPP_

#include "peridot_defines.h"

#ifndef PERIDOT_C

#ifndef PERIDOT_NO_NAMESPACE
namespace Pdt {
#endif // !PERIDOT_NO_NAMESPACE

#include "peridot_vector.hpp"
#include "peridot_matrix.hpp"
#include "peridot_quaternion.hpp"

class Transform
{
public:
  Vec3 position = { 0.0f, 0.0f, 0.0f };
  Vec3 rotation = { 0.0f, 0.0f, 0.0f };
  Vec3 scale = { 1.0f, 1.0f, 1.0f };

  inline Mat4 Matrix() const
  {
    Mat4 newMat = Mat4Identity;

    newMat.col0.x *= scale.x;
    newMat.col1.y *= scale.y;
    newMat.col2.z *= scale.z;

    Quaternion rot(rotation);
    newMat = rot.Matrix() * newMat;

    newMat.col3.x = position.x;
    newMat.col3.y = position.y;
    newMat.col3.z = position.z;

    return newMat;
  }
};

// #if defined __cplusplus && !defined PERIDOT_C
#define TransformIdentity Transform{ { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } }

#ifndef PERIDOT_NO_NAMESPACE
} // namespace Pdt
#endif // !PERIDOT_NO_NAMESPACE
#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_TRANSFORM_HPP_
