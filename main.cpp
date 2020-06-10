#include "NetPBMRenderer/NetPBMRenderer.h"

//Create video using:
//./netPbmRender | ffmpeg -i pipe:0 -c:v libx264rgb VideoName.avi

int main()
{
    Rendering* rendering = createRendering(400, 400);

    for (int i = 0; i < 60 * 10; i++)
    {
        for (int y = 0; y < 400; y++)
        {
            for (int x = 0; x < 400; x++)
            {
                int rng = rand() % 255;
                setPixel(rendering, x, y, (255 - rng), rng, rng);
            }
        }

        writeRendering(rendering);
    }

    freeRendering(rendering);
    return(0);
}
