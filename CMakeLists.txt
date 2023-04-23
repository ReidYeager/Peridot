
cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (Peridot STATIC
  "include/peridot.h"
  "include/peridot_defines.h"

  "src/defines.h"
  "src/core.c"
 )

set_target_properties(Peridot PROPERTIES LINKER_LANGUAGE C)

target_include_directories (Peridot PUBLIC
  ./
#  ${CMAKE_SOURCE_DIR}/Lapis/include/
)

#target_link_libraries(Peridot
#  Lapis
#)
