
#ifndef GEM_PERIDOT_H_
#define GEM_PERIDOT_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "include/peridot_defines.h"
#include "include/peridot_vector.h"
#include "include/peridot_matrix.h"
#include "include/peridot_quaternion.h"
#include "include/peridot_transform.h"
#include "include/peridot_projection.h"

#define PeriMin(a, b) ((a < b) ? a : b)
#define PeriMax(a, b) ((a > b) ? a : b)
#define PeriClamp(value, min, max) PeriMin(PeriMax(value, min), max)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !GEM_PERIDOT_H_
