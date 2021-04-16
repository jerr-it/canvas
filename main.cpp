#include "Artwork/Artwork.h"

//Create video using:
//./netPbmRender | ffmpeg -i pipe:0 -c:v libx264rgb VideoName.avi

int main() {
    Artwork art = newArt(400, 400);

    for (int i = 0; i < 60 * 10; i++) {
        for (int y = 0; y < 400; y++) {
            unsigned char v = (unsigned char)((float)y * (255.0 / 400.0));
            drawLine(art, 0, y, 399, y + 200, Color { v, v, v });
        }
    }

    drawRect(art, 200 - 25, 200 - 25, 50, 50, Color { 255, 255, 255 });

    drawLine(art, 200 - 25, 200 - 25, 200 + 25, 200 + 25, Color { 0, 0, 0 });

    drawEllipse(art, 75, 200, 25, 50, Color { 0, 0, 0 });

    drawCircle(art, 400 - 75, 200, 50, Color { 255, 255, 255 });

    char fileName[] = "test.ppm";

    saveArt(art, fileName);

    freeArt(art);
    return 0;
}
