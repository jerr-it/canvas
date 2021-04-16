#include "SFML_Artwork.h"
#include "Color.h"

Artwork SFML_Artwork::fromImage(sf::Image image) {
    sf::Vector2u iSize = image.getSize();

    Artwork art = newArt(iSize.x, iSize.y);

    for (int y = 0; y < iSize.y; y++) {
        for (int x = 0; x < iSize.x; x++) {
            sf::Color color = image.getPixel(x, y);
            setPixel(art, x, y, Color { color.r, color.g, color.b });
        }
    }

    return art;
}
