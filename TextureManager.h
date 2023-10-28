#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


#include <vector> 
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class TextureManager
{
	std::vector < std::vector<int>> texture;
public:
	TextureManager() {
        for (int x = 0; x < TEX_WIDTH; x++)
            for (int y = 0; y < TEX_HEIGHT; y++)
            {
                int xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
                //int xcolor = x * 256 / texWidth;
                int ycolor = y * 256 / TEX_HEIGHT;
                int xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
                texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
                texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
                texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
                texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
                texture[4][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
                texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
                texture[6][TEX_WIDTH * y + x] = 65536 * ycolor; //red gradient
                texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
            }
    }
    std::vector<int> get(int i);
};

#endif // !TEXTUREMANAGER_H
