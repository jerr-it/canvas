#ifndef SFML_ARTWORK_H
#define SFML_ARTWORK_H

#include "Artwork.h"
#include "SFML/Graphics.hpp"

class SFML_Artwork
{
public:

    /**
     * Create a rendering from an sf::Image
     * @param image sf::Image
     * @return new Rendering
     */
    static Artwork fromImage(sf::Image image);
};


#endif //SFML_ARTWORK_H
