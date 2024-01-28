
#ifndef GEM_PERIDOT_TRANSFORM_HPP_
#define GEM_PERIDOT_TRANSFORM_HPP_

#include "peridot_defines.h"

#ifndef PERIDOT_C

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
    Mat4 newMat(1.0f);

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

#endif // !PERIDOT_C
#endif // !GEM_PERIDOT_TRANSFORM_HPP_
