#include "Artwork/Artwork.h"

//Create video using:
//./netPbmRender | ffmpeg -i pipe:0 -c:v libx264rgb VideoName.avi

int main() {
    Artwork art = newArt(400, 400);

    for (int i = 0; i < 60 * 10; i++) {
        for (int y = 0; y < 400; y++) {
            unsigned char rng = (unsigned char)(rand() % 255);
            drawLine(art, 0, y, 399, y + 50, Color { rng, rng, rng });
        }

        drawRect(art, 200 - 25, 200 - 25, 50, 50, Color { 255, 255, 255 });
        drawLine(art, 200 - 25, 200 - 25, 200 + 25, 200 + 25, Color { 0, 0, 0 });
    }

    char fileName[] = "test.ppm";

    saveArt(art, fileName);

    freeArt(art);
    return 0;
}
