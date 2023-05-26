
cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (Peridot STATIC
  "include/peridot.h"
  "include/peridot_defines.h"

  "src/defines.h"
  "src/core.c"
  "include/peridot_vector.h"
  "include/peridot_matrix.h"
  "include/peridot_quaternion.h"
  "include/peridot_transform.h")

set_target_properties(Peridot PROPERTIES LINKER_LANGUAGE C)

target_include_directories (Peridot PUBLIC
  ./
)
