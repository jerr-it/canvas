#ifndef ARTWORK_H
#define ARTWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Color.h"

typedef struct {
    size_t         width;
    size_t         height;

    size_t         strokeWidth;
    Color          strokeColor;
    Color          fillColor;

    unsigned char* buffer;
} Artwork;

/**
 * @brief Create a new artwork
 *
 * @param width Width of the new artwork
 * @param height Height of the new artwork
 * @return Artwork
 */
Artwork newArt(size_t width, size_t height);

/**
 * @brief Set an individual pixel of an artwork
 *
 * @param art Artwork to draw on
 * @param x X-Position of the target pixel
 * @param y Y-Position of the target pixel
 * @param color Color the pixel should become
 */
void setPixel(Artwork art, int x, int y, Color color);

/**
 * @brief Draws a line using the Bresenham algorithm
 *
 * @param art Artwork to draw on
 * @param x0 X-Coordinate of starting point
 * @param y0 Y-Coordinate of starting point
 * @param x1 X-Coordinate of end point
 * @param y1 Y-Coordinate of end point
 * @param color Color of the line
 */
void drawLine(Artwork art, int x0, int y0, int x1, int y1);

/**
 * @brief Draws a rectangle onto the given artwork.
 *
 * @param art The artwork to draw on
 * @param x The topleft corners x
 * @param y The topleft corners y
 * @param width Width of the rectangle
 * @param height Height of the rectangle
 * @param color Color of the rectangle
 */
void drawRect(Artwork art, int x, int y, size_t width, size_t height);

/**
 * @brief Draws an ellipse using the Bresenham algorithm
 *
 * @param art Artwork to draw on
 * @param x X-Coordinate of the ellipse center
 * @param y Y-Coordinate of the ellipse center
 * @param width Radius in x direction
 * @param height Radius in y direction
 */
void drawEllipse(Artwork art, int x, int y, int width, int height);

/**
 * @brief Draws a circle
 *
 * @param art Artwork to draw on
 * @param x X-Coordinate of circle center
 * @param y Y-Coordinate of circle center
 * @param radius Radius
 * @param color Color
 */
void drawCircle(Artwork art, int x, int y, int radius);

/**
 * @brief Save a given artwork to a file
 *
 * @param art The artwork to save
 * @param filename Target file name (should end with .ppm)
 */
void saveArt(Artwork art, char* filename);

/**
 * @brief Pipe the artwork to a given target
 *
 * @param art Artwork to pipe out
 * @param target The pipe target, e.g. stdout, stderr ...
 */
void pipeArtTo(Artwork art, FILE* target);

/**
 * @brief Free the artworks used memory
 *
 * @param art artwork
 */
void freeArt(Artwork art);

#ifdef __cplusplus
}
#endif

#endif //ARTWORK_H
