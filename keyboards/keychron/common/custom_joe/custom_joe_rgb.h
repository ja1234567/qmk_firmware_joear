#pragma once
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

// Declare the array and functions
extern const rgb_t base_colors[];
#define BASE_COLORS_COUNT 9

void incrementCapslockRGB(void);
rgb_t getCapslockRGB(void);
