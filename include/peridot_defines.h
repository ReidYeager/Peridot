
#ifndef GEM_PERIDOT_DEFINES_H_
#define GEM_PERIDOT_DEFINES_H_

#include <stdint.h>
#include <stdbool.h>

#if !defined __cplusplus || defined PERIDOT_C
#ifndef PERIDOT_C
#define PERIDOT_C
#endif // !PERIDOT_C
#endif

#ifdef PERIDOT_VULKAN
#define PERI_VULKAN_COPE -1
#else
#define PERI_VULKAN_COPE 1
#endif // PERIDOT_VULKAN

#define PERI_PI 3.14159
#define PERI_DEGREES_TO_RADIANS(x) ((x) * (PERI_PI / 180.0))
#define PERI_RADIANS_TO_DEGREES(x) ((x) * (180.0 / PERI_PI))

#endif // !GEM_PERIDOT_DEFINES_H_

