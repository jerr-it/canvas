#include "Artwork.h"

Artwork newArt(size_t width, size_t height) {
    unsigned char* buffer = (unsigned char*)calloc(3 * width * height, sizeof(unsigned char));

    return
        (Artwork) {
            width,
            height,
            buffer,
        };
}

void setPixel(Artwork art, int x, int y, Color color) {
    if (x < 0 || x >= art.width || y < 0 || y >= art.height) {
        return;
    }

    art.buffer[(x + y * art.width) * 3 + 0] = color.r;
    art.buffer[(x + y * art.width) * 3 + 1] = color.g;
    art.buffer[(x + y * art.width) * 3 + 2] = color.b;
}

void drawLine(Artwork art, int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;

    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;

    int err = dx + dy;
    int err2;

    while (1) {
        setPixel(art, x0, y0, color);

        if (x0 == x1 && y0 == y1) {
            break;
        }

        err2 = 2 * err;

        if (err2 > dy) {
            err += dy;
            x0  += sx;
        }

        if (err2 < dx) {
            err += dx;
            y0  += sy;
        }
    }
}

void drawRect(Artwork art, int x, int y, size_t width, size_t height, Color color) {
    for (int ypos = y; ypos < y + height; ypos++) {
        for (int xpos = x; xpos < x + width; xpos++) {
            setPixel(art, xpos, ypos, color);
        }
    }
}

void saveArt(Artwork art, char* filename) {
    FILE* fp;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Can't open file!");
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", art.width, art.height);
    fwrite(art.buffer, 3 * art.width * art.height, 1, fp);

    fclose(fp);
}

void pipeArtTo(Artwork art, FILE* target) {
    printf("P6\n%d %d\n255\n", art.width, art.height);
    fwrite(art.buffer, 3 * art.width * art.height, 1, target);
}

void freeArt(Artwork art) {
    free(art.buffer);
}
