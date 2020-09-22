//
//  EnvironmentalBlocks.cpp
//  groupProject
//
//  Created by Taylor Dunn on 9/21/20.
//

#include "EnvironmentalBlocks.hpp"
#include <cmath>

Mushroom::Mushroom(int xPos, int yPos, sf::RenderWindow& window){
    sf::RectangleShape block(sf::Vector2f(50,50));
    block.setPosition(xPos*50, yPos*50);
    block.setFillColor(sf::Color(254, 127, 156));
    window.draw(block);
}

void createMushrooms(sf::RenderWindow& window){
    int spawnChance = 3;
    for (int i = 0; i < 25; i++){
        for(int j = 0; j < 17; j++){
            int spawnRoll=(rand() % 100);
            if (spawnRoll < spawnChance){
                Mushroom(i, j, window);
            }
        }
    }
}
