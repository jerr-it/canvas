#include "SFMLNetPBMRenderer.h"

void SFMLNetPBMRenderer::copyFromImage(Rendering* rendering, sf::Image image)
{
    sf::Vector2u iSize = image.getSize();

    for (int y = 0; y < iSize.y; y++)
    {
        for (int x = 0; x < iSize.x; x++)
        {
            sf::Color color = image.getPixel(x, y);
            setPixel(rendering, x, y, color.r, color.g, color.b);
        }
    }
}
