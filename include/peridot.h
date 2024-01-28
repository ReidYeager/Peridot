
#ifndef GEM_PERIDOT_H_
#define GEM_PERIDOT_H_

#include "peridot_defines.h"

#define PeriMin(a, b) ((a < b) ? a : b)
#define PeriMax(a, b) ((a > b) ? a : b)
#define PeriClamp(value, min, max) PeriMin(PeriMax(value, min), max)

#ifdef PERIDOT_C
#include "peridot_vector.h"
#include "peridot_matrix.h"
#include "peridot_quaternion.h"
#include "peridot_transform.h"
#else
#include "peridot_vector.hpp"
#include "peridot_matrix.hpp"
#include "peridot_quaternion.hpp"
#include "peridot_transform.hpp"
#endif // PERIDOT_C

#include "peridot_projection.h"

#endif // !GEM_PERIDOT_H_
