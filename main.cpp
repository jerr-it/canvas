#include "Artwork/Artwork.h"

//Create video using:
//./netPbmRender | ffmpeg -i pipe:0 -c:v libx264rgb VideoName.avi

int main()
{
	Artwork art = newArt(400, 400);

	for (int y = 0; y < 400; y++) {
		unsigned char v = (unsigned char)((float)y * (255.0 / 400.0));
		art.strokeColor = Color { v, v, v };
		drawLine(art, 0, y, 399, y + 200);
	}

	art.strokeColor = Color { 255, 0, 0 };
	art.fillColor = Color { 255, 255, 255 };
	art.strokeWidth = 10;
	drawRect(art, 200 - 25, 200 - 25, 50, 50);

	art.fillColor = Color { 0, 0, 0 };
	drawEllipse(art, 75, 200, 25, 50);

	art.strokeColor = Color { 255, 255, 255 };
	art.fillColor = Color { 255, 0, 0 };
	art.strokeWidth = 5;
	drawCircle(art, 400 - 75, 200, 50);

	char fileName[] = "test.ppm";

	saveArt(art, fileName);

	freeArt(art);
	return 0;
}
