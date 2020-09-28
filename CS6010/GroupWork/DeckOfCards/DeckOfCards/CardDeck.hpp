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

Deck createDeck();

//Prints a Card
void printCard(Card card);

//Gives a random index for a deck of cards.
int newIndex(Deck& deck);

//Swaps a card with another card in a deck
void swap(Card& firstIndex, Card& swapIndex);

int findMin(const Deck& deck);

int findMax(const Deck& deck);

bool contains(const Deck& deck, int lookFor);

Deck shuffle(Deck& deck);

bool isFlush(const Deck& deck);

Deck fiveCards(Deck deck);

bool isStraight(const Deck& deck);

bool isStraightFlush(const Deck& deck);

bool isFullHouse(const Deck& deck);

void runTests();
void printStats(int upperBounds, Deck& deck);
void runHandAnalysis(const Deck& deck);

#endif /* CardDeck_hpp */
