#include "custom_joe_rgb.h"

const rgb_t base_colors[] = {
    {255, 0, 0},        // Red
    {255, 165, 0},      // Orange
    {255, 255, 0},      // Yellow
    {0, 255, 0},        // Green
    {0, 255, 255},      // Cyan
    {0, 0, 255},        // Blue
    {153, 51, 255},     // Purple
    {255, 51, 153},     // Pink
    {255, 255, 255},    // White
};

static uint8_t current_capslock_index = 0;

void incrementCapslockRGB(void) {
    current_capslock_index = (current_capslock_index + 1) % BASE_COLORS_COUNT;
}

rgb_t getCapslockRGB(void) {
    return base_colors[current_capslock_index];
}
