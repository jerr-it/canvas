<h1 align="center">Cartwork</h1>
<p align="center">
    <img src="https://img.shields.io/badge/Language-C/C++-blue?style=for-the-badge&logo=c%2B%2Bl" />
</div>
<br>
<p align="center">
Library for rendering images and videos directly using C and the NetPBM image format
</p>

<h2 align="center">How to use</h2>

Compile repo:
```
cmake .
make Cartwork
./Cartwork

or 
g++ -o Cartwork main.cpp Artwork/Color.h Artwork/Artwork.h Artwork/Artwork.c
./Cartwork
```

<h2 align="center">Examples</h2>
<h6 align="center">Check main.cpp!</h6>

Include header:
```c
#include "Artwork/Artwork.h"
```

Create artwork and set values:
```c
Artwork art = newArt(400, 400);
```
Dont forget to free afterwards to avoid memory leaks!
```c
freeArt(art);
```

Set individual pixel
```c
setPixel(art, <x>, <y>, Color {255, 255, 255});
```

Draw line:
```c
drawLine(art, <x0>, <y0>, <x1>, <y1>, Color {0, 255, 0});
```

Draw rect:
```c
drawRect(art, <top-left x>, <top-left y>, <width>, <height>, Color { 255, 0, 255 });
```

Draw circle:
```c
drawCircle(art, <x>, <y>, <radius>, Color { 255, 255, 255 });
```

Draw ellipse:
```c
drawEllipse(art, <x>, <y>, <x-radius>, <y-radius>, Color { 0, 0, 0 });
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

The SFML_Artwork class is essentially a C++ wrapper for the standard rendering. It enables you to create Artworks from sf::Image objects, the entire window for example.

```c
#include "SFML_Artwork/SFML_Artwork.h"
```
Create your window and rendering:
```c
RenderWindow window(VideoMode(800, 800), "Rendering");
Rendering* rendering = createRendering(800, 800);

Texture texture;
Image image;
Vector2u windowsize;
```
Save your window as an image:
```c
windowsize = window.getSize();
texture.create(windowsize.x, windowsize.y);
texture.update(window);
image = texture.copyToImage();
Artwork art = SFML_Artwork::fromImage(image);
saveArt(art);
```
