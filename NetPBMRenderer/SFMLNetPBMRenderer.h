#ifndef NETPBMRENDER_SFMLNETPBMRENDERER_H
#define NETPBMRENDER_SFMLNETPBMRENDERER_H

#include "NetpbmRenderer.h"
#include "SFML/Graphics.hpp"

class SFMLNetPBMRenderer
{
public:
    /**
     * Create a rendering from an sf::Image
     * @param image sf::Image
     * @return new Rendering
     */
    static void copyFromImage(Rendering* rendering, sf::Image image);
};


#endif //NETPBMRENDER_SFMLNETPBMRENDERER_H
