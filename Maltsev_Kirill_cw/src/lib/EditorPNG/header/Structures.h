#ifndef STRUCTURES_H
#define STRUCTURES_H

#define R_IDX        0
#define G_IDX        1
#define B_IDX        2
#define A_IDX        3

namespace epng
{

struct Coord
{
    int x;
    int y;
};

struct Color
{
    int r;
    int g;
    int b;
    int a;

    bool operator==(Color other)
    {
        return (r == other.r) && 
               (g == other.g) && 
               (b == other.b) && 
               (a == other.a);
    }

    bool operator!=(Color other)
    {
        return !(*this == other);
    }

    void inverse()
    {
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
    }

    void gray()
    {
        r = (0.299 * r) + (0.587 * g) + (0.114 * b);
        g = (0.299 * r) + (0.587 * g) + (0.114 * b);
        b = (0.299 * r) + (0.587 * g) + (0.114 * b);
    }
};

}
#endif