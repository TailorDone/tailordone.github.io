//
//  main.cpp
//  DeckOfCards
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include "CardDeck.hpp"

int main(int argc, const char * argv[]) {
    Deck newDeck = createDeck();
    for (Card card : newDeck.cards){
        printCard(card);
    }
    return 0;
}
