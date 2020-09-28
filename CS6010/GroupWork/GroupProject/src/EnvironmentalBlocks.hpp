//
//  EnvironmentalBlocks.hpp
//  groupProject
//
//  Created by Taylor Dunn on 9/21/20.
//

#ifndef EnvironmentalBlocks_hpp
#define EnvironmentalBlocks_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Mushroom{
    int xPos;
    int yPos;
public:
    Mushroom(int xPos, int yPos, sf::RenderWindow& window);
};

void createMushrooms(sf::RenderWindow& window);
#endif /* EnvironmentalBlocks_hpp */
