//
//  CardDeck.hpp
//  DeckOfCards
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

struct Card{
    string suit;
    int rank;
};

struct Deck{
    vector<Card> cards;
};

//Creates a Deck of Cards
Deck createDeck();

//Prints rank and suit of a card
void printCard(Card card);

#endif /* CardDeck_hpp */
