#include "ImagePNG.h"

#include <queue>


void epng::ImagePNG::floodFill(int x, int y, Color color)
{
    std::queue<Coord> coords;
    coords.push({x, y});

    while (!coords.empty()) {
        Coord p = coords.front();
        if (checkCoordsValidity(p.x, p.y) && !isColored(p.x, p.y)) {
            setColor(p.x, p.y, color);
            coords.push({p.x+1, p.y});
            coords.push({p.x-1, p.y});
            coords.push({p.x, p.y+1});
            coords.push({p.x, p.y-1});
        }
        coords.pop();
    }
}

void epng::ImagePNG::fill(int x, int y, Color color)
{
    clearColoredPixels();
    Color start_color = getColor(x, y);

    std::queue<Coord> coords;
    coords.push({x, y});

    while (!coords.empty()) {
        Coord p = coords.front();
        if (checkCoordsValidity(p.x, p.y) && 
            getColor(p.x, p.y) == start_color && 
            !isColored(p.x, p.y)) {
            
            setColor(p.x, p.y, color);
            coords.push({p.x+1, p.y});
            coords.push({p.x-1, p.y});
            coords.push({p.x, p.y+1});
            coords.push({p.x, p.y-1});
        }
        coords.pop();
    }
}