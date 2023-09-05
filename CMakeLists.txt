
cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (Peridot STATIC
  "include/peridot.h"
  "include/peridot_defines.h"
  "include/peridot_vector.h"
  "include/peridot_matrix.h"
  "include/peridot_quaternion.h"
  "include/peridot_transform.h"
  "peridot.c"
)

set_target_properties(Peridot PROPERTIES LINKER_LANGUAGE C)
target_compile_definitions(Peridot PUBLIC PERIDOT_MODE=1)

target_include_directories (Peridot PUBLIC
  ./
)
