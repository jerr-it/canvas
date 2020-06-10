<h1 align="center">RenderInc</h1>
<p align="center">
    <img src="https://img.shields.io/badge/Language-C/C++-blue?style=for-the-badge&logo=c%2B%2Bl" />
</div>
<br>
<p align="center">
Library for rendering images and videos directly using C and the NetPBM image format, no other library involved. Includes a C++ Wrapper for usage with SFML.
</p>

<h2 align="center">How to use</h2>

Compile repo:
```
cmake .
make netPbmRender
./netPbmRender
```

<h2 align="center">Standart</h2>

Include header:
```c
#include "NetPBMRenderer/NetPBMRenderer.h"
```

Create rendering and set values:
```c
Rendering* rendering = createRendering(400, 400);

for (int y = 0; y < 400; y++)
{
    for (int x = 0; x < 400; x++)
    {
        //Grayscale image
        int rng = rand() % 255;
        setPixel(rendering, x, y, rng, rng, rng);
    }
}
```

Save image to a file (.ppm):
```c
saveRendering(rendering, "image.ppm");
```

Write image to standard output to create a video:
```c
writeRendering(rendering);
```

Pipe it to VLC:
```
./ExecutableNameHere | ppmtoy4m -F60:1 | vlc -
```

Or render the complete video:
```
./ExecutableNameHere | ffmpeg -i pipe:0 -c:v libx264rgb VideoName.avi
```

<h2 align="center">SFML Tandem</h2>

The SFMLNetPBMRenderer class is essentially a C++ wrapper for the standard rendering. It enables you to create Renderings from sf::Image objects, the entire window for example.

```c
#include "NetPBMRenderer/SFMLNetPBMRenderer.h"
```
Create your window and rendering:
```c
RenderWindow window(VideoMode(800, 800), "Rendering");
Rendering* rendering = createRendering(800, 800);

Texture texture;
Image image;
Vector2u windowsize;
```
Write your window to standard output for video creation:
```c
windowsize = window.getSize();
texture.create(windowsize.x, windowsize.y);
texture.update(window);
image = texture.copyToImage();
SFMLNetPBMRenderer::copyFromImage(rendering, image);
writeRendering(rendering);
```

<h2 align="center">Dont forget to free</h2>

```c
freeRendering(rendering);
```
