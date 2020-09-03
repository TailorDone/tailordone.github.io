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
    
    Deck newDeck2;
    Card card1 = {"Spades", 10};
    Card card2 = {"Clubs", 10};
    Card card3 = {"Hearts", 10};
    Card card4 = {"Clubs", 4};
    Card card5 = {"Diamonds", 4};
    newDeck2.cards.push_back(card1);
    newDeck2.cards.push_back(card2);
    newDeck2.cards.push_back(card3);
    newDeck2.cards.push_back(card4);
    newDeck2.cards.push_back(card5);
    bool fullHouse = isFullHouse(newDeck2);
    cout << "is this a full house? " << fullHouse << endl;
    return 0;
}
