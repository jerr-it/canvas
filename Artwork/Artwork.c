#include "Artwork.h"

Artwork newArt(size_t width, size_t height) {
    unsigned char* buffer = (unsigned char*)calloc(3 * width * height, sizeof(unsigned char));

    return
        (Artwork) {
            width,
            height,
            1,
            (Color) { 255, 255, 255 },
            (Color) { 255, 255, 255 },
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

//Helper for filling shapes like circles and rectangles
void drawLineColor(Artwork art, int x0, int y0, int x1, int y1, Color color) {
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

void drawLine(Artwork art, int x0, int y0, int x1, int y1) {
    drawLineColor(art, x0, y0, x1, y1, art.strokeColor);
}

void drawRect(Artwork art, int x, int y, size_t width, size_t height) {
    drawLineColor(art, x, y, x + width - 1, y, art.strokeColor);
    drawLineColor(art, x, y + height - 1, x + width - 1, y + height - 1, art.strokeColor);
    drawLineColor(art, x, y, x, y + height - 1, art.strokeColor);
    drawLineColor(art, x + width - 1, y, x + width - 1, y + height - 1, art.strokeColor);

    for (int ypos = y + 1; ypos < y + height - 1; ypos++) {
        for (int xpos = x + 1; xpos < x + width - 1; xpos++) {
            setPixel(art, xpos, ypos, art.fillColor);
        }
    }
}

//Helper for drawing ellipse with stroke
void drawEllipseColor(Artwork art, int x, int y, int width, int height, Color color) {
    int dx = 0;
    int dy = height;

    long w2 = width * width;
    long h2 = height * height;

    long err = h2 - (2 * height - 1) * w2;
    long err2;

    do{
        drawLineColor(art, x, y + dy, x + dx, y + dy, color);
        drawLineColor(art, x, y + dy, x - dx, y + dy, color);
        drawLineColor(art, x, y - dy, x - dx, y - dy, color);
        drawLineColor(art, x, y - dy, x + dx, y - dy, color);

        setPixel(art, x + dx, y + dy, color);
        setPixel(art, x - dx, y + dy, color);
        setPixel(art, x - dx, y - dy, color);
        setPixel(art, x + dx, y - dy, color);

        err2 = 2 * err;

        if (err2 < (2 * dx + 1) * h2) {
            dx++;
            err += (2 * dx + 1) * h2;
        }

        if (err2 > -(2 * dy - 1) * w2) {
            dy--;
            err -= (2 * dy - 1) * w2;
        }
    } while (dy >= 0);

    while (dx++ < width) {
        setPixel(art, x + dx, y, color);
        setPixel(art, x - dx, y, color);
    }
}

void drawEllipse(Artwork art, int x, int y, int width, int height) {
    drawEllipseColor(art, x, y, width, height, art.strokeColor);
    drawEllipseColor(art, x, y, width - art.strokeWidth, height - art.strokeWidth, art.fillColor);
}

void drawCircle(Artwork art, int x, int y, int radius) {
    drawEllipse(art, x, y, radius, radius);
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
