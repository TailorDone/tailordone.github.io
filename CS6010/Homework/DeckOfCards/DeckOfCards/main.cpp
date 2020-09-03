//
//  main.cpp
//  DeckOfCards
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "CardDeck.hpp"

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    Deck newDeck = createDeck();
    for (Card card : newDeck.cards){
        printCard(card);
    }
    shuffle(newDeck);
    for (Card card : newDeck.cards){
        printCard(card);
    }
    runTests();
    Deck deck = createDeck();
    printStats(100, deck);
    printStats(10000, deck);
    return 0;
}
