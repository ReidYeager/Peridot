
#ifndef GEM_PERIDOT_MATRIX_H_
#define GEM_PERIDOT_MATRIX_H_
#ifdef PERIDOT_C

#include "peridot_defines.h"
#include "peridot_vector.h"

typedef union Mat4
{
  float elements[16];
  struct
  {
    union { Vec4 x, col0; };
    union { Vec4 y, col1; };
    union { Vec4 z, col2; };
    union { Vec4 w, col3; };
  };
} Mat4;

#ifdef __clang__
#define mat4Identity (Mat4) { \
  1.0f, 0.0f, 0.0f, 0.0f,     \
  0.0f, 1.0f, 0.0f, 0.0f,     \
  0.0f, 0.0f, 1.0f, 0.0f,     \
  0.0f, 0.0f, 0.0f, 1.0f      \
}
#else
#define mat4Identity {    \
  1.0f, 0.0f, 0.0f, 0.0f, \
  0.0f, 1.0f, 0.0f, 0.0f, \
  0.0f, 0.0f, 1.0f, 0.0f, \
  0.0f, 0.0f, 0.0f, 1.0f  \
}
#endif

inline Mat4 Mat4FromElementArray(float* _elements, bool _inputIsRowMajor)
{
  Mat4 newMat = { 0 };
  newMat.elements[0                          ] = _elements[0 ];
  newMat.elements[1  + (3 * _inputIsRowMajor)] = _elements[1 ];
  newMat.elements[2  + (6 * _inputIsRowMajor)] = _elements[2 ];
  newMat.elements[3  + (9 * _inputIsRowMajor)] = _elements[3 ];
  newMat.elements[4  - (3 * _inputIsRowMajor)] = _elements[4 ];
  newMat.elements[5                          ] = _elements[5 ];
  newMat.elements[6  + (3 * _inputIsRowMajor)] = _elements[6 ];
  newMat.elements[7  + (6 * _inputIsRowMajor)] = _elements[7 ];
  newMat.elements[8  - (6 * _inputIsRowMajor)] = _elements[8 ];
  newMat.elements[9  - (3 * _inputIsRowMajor)] = _elements[9 ];
  newMat.elements[10                         ] = _elements[10];
  newMat.elements[11 + (3 * _inputIsRowMajor)] = _elements[11];
  newMat.elements[12 - (9 * _inputIsRowMajor)] = _elements[12];
  newMat.elements[13 - (6 * _inputIsRowMajor)] = _elements[13];
  newMat.elements[14 - (3 * _inputIsRowMajor)] = _elements[14];
  newMat.elements[15                         ] = _elements[15];

  return newMat;
}

inline Mat4 Mat4FromDiagonalValue(float _value)
{
  Mat4 newMat = {
    _value,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    _value,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    _value,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    _value };

  return newMat;
}

inline Mat4 Mat4FromScalar(float _value)
{
  Mat4 newMat = {
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value,
    _value };
  return newMat;
}

inline bool Mat4Compare(Mat4 _left, Mat4 _right)
{
  return
       _left.elements[0 ] == _right.elements[0 ]
    && _left.elements[1 ] == _right.elements[1 ]
    && _left.elements[2 ] == _right.elements[2 ]
    && _left.elements[3 ] == _right.elements[3 ]
    && _left.elements[4 ] == _right.elements[4 ]
    && _left.elements[5 ] == _right.elements[5 ]
    && _left.elements[6 ] == _right.elements[6 ]
    && _left.elements[7 ] == _right.elements[7 ]
    && _left.elements[8 ] == _right.elements[8 ]
    && _left.elements[9 ] == _right.elements[9 ]
    && _left.elements[10] == _right.elements[10]
    && _left.elements[11] == _right.elements[11]
    && _left.elements[12] == _right.elements[12]
    && _left.elements[13] == _right.elements[13]
    && _left.elements[14] == _right.elements[14]
    && _left.elements[15] == _right.elements[15];
}

inline Mat4 Mat4Transpose(Mat4 _matrix)
{
  Mat4 newMat = {
    _matrix.x.x, _matrix.y.x, _matrix.z.x, _matrix.w.x,
    _matrix.x.y, _matrix.y.y, _matrix.z.y, _matrix.w.y,
    _matrix.x.z, _matrix.y.z, _matrix.z.z, _matrix.w.z,
    _matrix.x.w, _matrix.y.w, _matrix.z.w, _matrix.w.w };
  return newMat;
}

inline Mat4 Mat4MultiplyFloat(Mat4 _matrix, float _float)
{
  Mat4 newMat = {
    _matrix.elements[0 ] * _float,
    _matrix.elements[1 ] * _float,
    _matrix.elements[2 ] * _float,
    _matrix.elements[3 ] * _float,
    _matrix.elements[4 ] * _float,
    _matrix.elements[5 ] * _float,
    _matrix.elements[6 ] * _float,
    _matrix.elements[7 ] * _float,
    _matrix.elements[8 ] * _float,
    _matrix.elements[9 ] * _float,
    _matrix.elements[10] * _float,
    _matrix.elements[11] * _float,
    _matrix.elements[12] * _float,
    _matrix.elements[13] * _float,
    _matrix.elements[14] * _float,
    _matrix.elements[15] * _float };
  return newMat;
}

inline Vec3 Mat4MultiplyVec3(Mat4 _matrix, Vec3 _vector)
{
  Vec3 newVec = {
    _matrix.x.x * _vector.x + _matrix.y.x * _vector.y + _matrix.z.x * _vector.z,
    _matrix.x.y * _vector.x + _matrix.y.y * _vector.y + _matrix.z.y * _vector.z,
    _matrix.x.z * _vector.x + _matrix.y.z * _vector.y + _matrix.z.z * _vector.z };
  return newVec;
}

inline Vec4 Mat4MultiplyVec4(Mat4 _matrix, Vec4 _vector)
{
  Vec4 newVec = {
    Vec4Dot(_matrix.x, _vector),
    Vec4Dot(_matrix.y, _vector),
    Vec4Dot(_matrix.z, _vector),
    Vec4Dot(_matrix.w, _vector) };
  return newVec;
}

inline Mat4 Mat4MuliplyMat4(Mat4 _left, Mat4 _right)
{
  _left = Mat4Transpose(_left);

  Mat4 newMat = {
    Vec4Dot(_left.x, _right.x), Vec4Dot(_left.y, _right.x), Vec4Dot(_left.z, _right.x), Vec4Dot(_left.w, _right.x),
    Vec4Dot(_left.x, _right.y), Vec4Dot(_left.y, _right.y), Vec4Dot(_left.z, _right.y), Vec4Dot(_left.w, _right.y),
    Vec4Dot(_left.x, _right.z), Vec4Dot(_left.y, _right.z), Vec4Dot(_left.z, _right.z), Vec4Dot(_left.w, _right.z),
    Vec4Dot(_left.x, _right.w), Vec4Dot(_left.y, _right.w), Vec4Dot(_left.z, _right.w), Vec4Dot(_left.w, _right.w) };
  return newMat;
}

inline Mat4 Mat4Invert(Mat4 _matrix)
{
    Mat4 newMat = { 0 };
    double determinant;

    // Row 0 =====

    newMat.elements[0] =
        _matrix.elements[5 ] * _matrix.elements[10] * _matrix.elements[15]
      - _matrix.elements[5 ] * _matrix.elements[11] * _matrix.elements[14]
      - _matrix.elements[9 ] * _matrix.elements[6 ] * _matrix.elements[15]
      + _matrix.elements[9 ] * _matrix.elements[7 ] * _matrix.elements[14]
      + _matrix.elements[13] * _matrix.elements[6 ] * _matrix.elements[11]
      - _matrix.elements[13] * _matrix.elements[7 ] * _matrix.elements[10];

    newMat.elements[4] =
      - _matrix.elements[4 ] * _matrix.elements[10] * _matrix.elements[15]
      + _matrix.elements[4 ] * _matrix.elements[11] * _matrix.elements[14]
      + _matrix.elements[8 ] * _matrix.elements[6 ] * _matrix.elements[15]
      - _matrix.elements[8 ] * _matrix.elements[7 ] * _matrix.elements[14]
      - _matrix.elements[12] * _matrix.elements[6 ] * _matrix.elements[11]
      + _matrix.elements[12] * _matrix.elements[7 ] * _matrix.elements[10];

    newMat.elements[8] =
        _matrix.elements[4 ] * _matrix.elements[9 ] * _matrix.elements[15]
      - _matrix.elements[4 ] * _matrix.elements[11] * _matrix.elements[13]
      - _matrix.elements[8 ] * _matrix.elements[5 ] * _matrix.elements[15]
      + _matrix.elements[8 ] * _matrix.elements[7 ] * _matrix.elements[13]
      + _matrix.elements[12] * _matrix.elements[5 ] * _matrix.elements[11]
      - _matrix.elements[12] * _matrix.elements[7 ] * _matrix.elements[9 ];

    newMat.elements[12] =
      - _matrix.elements[4 ] * _matrix.elements[9 ] * _matrix.elements[14]
      + _matrix.elements[4 ] * _matrix.elements[10] * _matrix.elements[13]
      + _matrix.elements[8 ] * _matrix.elements[5 ] * _matrix.elements[14]
      - _matrix.elements[8 ] * _matrix.elements[6 ] * _matrix.elements[13]
      - _matrix.elements[12] * _matrix.elements[5 ] * _matrix.elements[10]
      + _matrix.elements[12] * _matrix.elements[6 ] * _matrix.elements[9 ];

    determinant =
        (double)_matrix.elements[0 ] * (double)newMat.elements[0 ]
      + (double)_matrix.elements[1 ] * (double)newMat.elements[4 ]
      + (double)_matrix.elements[2 ] * (double)newMat.elements[8 ]
      + (double)_matrix.elements[3 ] * (double)newMat.elements[12];

    if (determinant == 0)
    {
      // No inverse exists. Don't calculate the rest
      return _matrix;
    }

    // Row 1 =====

    newMat.elements[1] =
      - _matrix.elements[1 ] * _matrix.elements[10] * _matrix.elements[15]
      + _matrix.elements[1 ] * _matrix.elements[11] * _matrix.elements[14]
      + _matrix.elements[9 ] * _matrix.elements[2 ] * _matrix.elements[15]
      - _matrix.elements[9 ] * _matrix.elements[3 ] * _matrix.elements[14]
      - _matrix.elements[13] * _matrix.elements[2 ] * _matrix.elements[11]
      + _matrix.elements[13] * _matrix.elements[3 ] * _matrix.elements[10];

    newMat.elements[5] =
        _matrix.elements[0 ] * _matrix.elements[10] * _matrix.elements[15]
      - _matrix.elements[0 ] * _matrix.elements[11] * _matrix.elements[14]
      - _matrix.elements[8 ] * _matrix.elements[2 ] * _matrix.elements[15]
      + _matrix.elements[8 ] * _matrix.elements[3 ] * _matrix.elements[14]
      + _matrix.elements[12] * _matrix.elements[2 ] * _matrix.elements[11]
      - _matrix.elements[12] * _matrix.elements[3 ] * _matrix.elements[10];

    newMat.elements[9] =
      - _matrix.elements[0 ] * _matrix.elements[9 ] * _matrix.elements[15]
      + _matrix.elements[0 ] * _matrix.elements[11] * _matrix.elements[13]
      + _matrix.elements[8 ] * _matrix.elements[1 ] * _matrix.elements[15]
      - _matrix.elements[8 ] * _matrix.elements[3 ] * _matrix.elements[13]
      - _matrix.elements[12] * _matrix.elements[1 ] * _matrix.elements[11]
      + _matrix.elements[12] * _matrix.elements[3 ] * _matrix.elements[9 ];

    newMat.elements[13] =
        _matrix.elements[0 ] * _matrix.elements[9 ] * _matrix.elements[14]
      - _matrix.elements[0 ] * _matrix.elements[10] * _matrix.elements[13]
      - _matrix.elements[8 ] * _matrix.elements[1 ] * _matrix.elements[14]
      + _matrix.elements[8 ] * _matrix.elements[2 ] * _matrix.elements[13]
      + _matrix.elements[12] * _matrix.elements[1 ] * _matrix.elements[10]
      - _matrix.elements[12] * _matrix.elements[2 ] * _matrix.elements[9 ];

    // Row 2 =====

    newMat.elements[2] =
        _matrix.elements[1 ] * _matrix.elements[6 ] * _matrix.elements[15]
      - _matrix.elements[1 ] * _matrix.elements[7 ] * _matrix.elements[14]
      - _matrix.elements[5 ] * _matrix.elements[2 ] * _matrix.elements[15]
      + _matrix.elements[5 ] * _matrix.elements[3 ] * _matrix.elements[14]
      + _matrix.elements[13] * _matrix.elements[2 ] * _matrix.elements[7 ]
      - _matrix.elements[13] * _matrix.elements[3 ] * _matrix.elements[6 ];

    newMat.elements[6] =
      - _matrix.elements[0 ] * _matrix.elements[6 ] * _matrix.elements[15]
      + _matrix.elements[0 ] * _matrix.elements[7 ] * _matrix.elements[14]
      + _matrix.elements[4 ] * _matrix.elements[2 ] * _matrix.elements[15]
      - _matrix.elements[4 ] * _matrix.elements[3 ] * _matrix.elements[14]
      - _matrix.elements[12] * _matrix.elements[2 ] * _matrix.elements[7 ]
      + _matrix.elements[12] * _matrix.elements[3 ] * _matrix.elements[6 ];

    newMat.elements[10] =
        _matrix.elements[0 ] * _matrix.elements[5 ] * _matrix.elements[15]
      - _matrix.elements[0 ] * _matrix.elements[7 ] * _matrix.elements[13]
      - _matrix.elements[4 ] * _matrix.elements[1 ] * _matrix.elements[15]
      + _matrix.elements[4 ] * _matrix.elements[3 ] * _matrix.elements[13]
      + _matrix.elements[12] * _matrix.elements[1 ] * _matrix.elements[7 ]
      - _matrix.elements[12] * _matrix.elements[3 ] * _matrix.elements[5 ];

    newMat.elements[14] =
      - _matrix.elements[0 ] * _matrix.elements[5 ] * _matrix.elements[14]
      + _matrix.elements[0 ] * _matrix.elements[6 ] * _matrix.elements[13]
      + _matrix.elements[4 ] * _matrix.elements[1 ] * _matrix.elements[14]
      - _matrix.elements[4 ] * _matrix.elements[2 ] * _matrix.elements[13]
      - _matrix.elements[12] * _matrix.elements[1 ] * _matrix.elements[6 ]
      + _matrix.elements[12] * _matrix.elements[2 ] * _matrix.elements[5 ];

    // Row 3 =====

    newMat.elements[3] =
      - _matrix.elements[1 ] * _matrix.elements[6 ] * _matrix.elements[11]
      + _matrix.elements[1 ] * _matrix.elements[7 ] * _matrix.elements[10]
      + _matrix.elements[5 ] * _matrix.elements[2 ] * _matrix.elements[11]
      - _matrix.elements[5 ] * _matrix.elements[3 ] * _matrix.elements[10]
      - _matrix.elements[9 ] * _matrix.elements[2 ] * _matrix.elements[7 ]
      + _matrix.elements[9 ] * _matrix.elements[3 ] * _matrix.elements[6 ];

    newMat.elements[7] =
        _matrix.elements[0 ] * _matrix.elements[6 ] * _matrix.elements[11]
      - _matrix.elements[0 ] * _matrix.elements[7 ] * _matrix.elements[10]
      - _matrix.elements[4 ] * _matrix.elements[2 ] * _matrix.elements[11]
      + _matrix.elements[4 ] * _matrix.elements[3 ] * _matrix.elements[10]
      + _matrix.elements[8 ] * _matrix.elements[2 ] * _matrix.elements[7 ]
      - _matrix.elements[8 ] * _matrix.elements[3 ] * _matrix.elements[6 ];

    newMat.elements[11] =
      - _matrix.elements[0 ] * _matrix.elements[5 ] * _matrix.elements[11]
      + _matrix.elements[0 ] * _matrix.elements[7 ] * _matrix.elements[9 ]
      + _matrix.elements[4 ] * _matrix.elements[1 ] * _matrix.elements[11]
      - _matrix.elements[4 ] * _matrix.elements[3 ] * _matrix.elements[9 ]
      - _matrix.elements[8 ] * _matrix.elements[1 ] * _matrix.elements[7 ]
      + _matrix.elements[8 ] * _matrix.elements[3 ] * _matrix.elements[5 ];

    newMat.elements[15] =
        _matrix.elements[0 ] * _matrix.elements[5 ] * _matrix.elements[10]
      - _matrix.elements[0 ] * _matrix.elements[6 ] * _matrix.elements[9 ]
      - _matrix.elements[4 ] * _matrix.elements[1 ] * _matrix.elements[10]
      + _matrix.elements[4 ] * _matrix.elements[2 ] * _matrix.elements[9 ]
      + _matrix.elements[8 ] * _matrix.elements[1 ] * _matrix.elements[6 ]
      - _matrix.elements[8 ] * _matrix.elements[2 ] * _matrix.elements[5 ];

    determinant = 1.0 / determinant;
    newMat = Mat4MultiplyFloat(newMat, (float)determinant);

    return newMat;
}

#endif // PERIDOT_C
#endif // !GEM_PERIDOT_MATRIX_H_
