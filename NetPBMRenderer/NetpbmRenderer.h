#ifndef NETPBMRENDER_NETPBMRENDERER_H
#define NETPBMRENDER_NETPBMRENDERER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    unsigned char* buffer;
} Rendering;

/**
 * Create a new Rendering
 * @param width width of image
 * @param height height of image
 * @return new Rendering
 */
Rendering* createRendering(int width, int height);

/**
 * Set a pixel of a rendering
 * @param rendering rendering
 * @param x x position
 * @param y y position
 * @param r r channel (0-255)
 * @param g g channel (0-255)
 * @param b b channel (0-255)
 */
void setPixel(Rendering* rendering, int x, int y, unsigned char r, unsigned char g, unsigned char b);

/**
 * Save rendering to file
 * @param rendering to save
 */
void saveRendering(Rendering* rendering, char* filename);

/**
 * Write rendering to standard output
 * @param rendering to write
 */
void writeRendering(Rendering* rendering);

/**
 * Free memory used by rendering
 * @param rendering rendering
 */
void freeRendering(Rendering* rendering);

#ifdef __cplusplus
}
#endif

#endif //NETPBMRENDER_NETPBMRENDERER_H