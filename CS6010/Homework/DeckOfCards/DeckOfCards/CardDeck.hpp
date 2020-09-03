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

//Creates a deck of cards
Deck createDeck();

//Prints a Card
void printCard(Card card);

//Gives a random index for a deck of cards.
int newIndex(Deck& deck);

//Swaps a card with another card in a deck
void swap(Card& firstIndex, Card& swapIndex);

//finds the minimum ranking card in a deck
int findMin(const Deck& deck);

//finds the maximum ranking card in a deck
int findMax(const Deck& deck);

//Searches a deck to find a particular rank
bool contains(const Deck& deck, int lookFor);

//Shuffles a deck of cards
Deck shuffle(Deck& deck);

//Determines if a hand is a flush
bool isFlush(const Deck& deck);

//Determines if a hand is a straight flush
bool isStraightFlush(Deck& deck);

//Determines if a hand is a royal flush
bool isRoyalFlush(const Deck& deck);

//Determines if a hand is a full house
bool isFullHouse(const Deck& deck);

//runs the analysis for a deck of cards
void runHandAnalysis(Deck& deck);

void printStats(int upperBounds, Deck& deck);

//runsTest
void runTests();

#endif /* CardDeck_hpp */
