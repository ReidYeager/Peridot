
cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

define_property(GLOBAL PROPERTY PeridotSource INHERITED)
set_property(GLOBAL PROPERTY PeridotSource
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_defines.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_vector.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_matrix.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_quaternion.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_transform.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_vector.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_matrix.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_quaternion.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/peridot_transform.hpp
)
