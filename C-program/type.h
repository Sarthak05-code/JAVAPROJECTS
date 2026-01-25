#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/* Type aliases */
typedef uint32_t u32;
typedef uint64_t u64;
typedef float    f32;
typedef int      b32;

/* Utility functions */

static inline b32 isEven(u32 num)
{
    return (num % 2 == 0);
}

static inline u32 findMaxArray(const u32 *array, u32 n)
{
    if (array == NULL || n == 0)
        return 0;

    u32 max = array[0];

    for (u32 i = 1; i < n; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

#endif /* TYPES_H */
