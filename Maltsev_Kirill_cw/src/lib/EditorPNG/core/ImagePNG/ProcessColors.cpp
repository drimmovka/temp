#include "ImagePNG.h"


void epng::ImagePNG::colorReplace(Color old_color, Color new_color)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (getColor(x, y) == old_color) {
                setColor(x, y, new_color);
            }
        }
    }
}

void epng::ImagePNG::rgbaFilter(int component_idx, int component_value)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            row_pointers_[y][x * pixel_size_ + component_idx] = component_value;
        }
    }
}

void epng::ImagePNG::inverseColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            Color color = getColor(x, y);
            color.inverse();
            setColor(x, y, color);
        }
    }
}

void epng::ImagePNG::grayColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            Color color = getColor(x, y);
            color.gray();
            setColor(x, y, color);
        }
    }
}