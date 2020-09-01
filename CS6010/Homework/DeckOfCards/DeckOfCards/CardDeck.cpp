//
//  CardDeck.cpp
//  DeckOfCards
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//
#include <iostream>
#include "CardDeck.hpp"
using namespace std;

Deck createDeck(){
    Deck myDeck;
    vector<string> suits = {"Spades", "Clubs", "Diamonds", "Hearts"};
    for (string suit : suits){
        for (int i = 1; i <= 13; i++){
            Card newCard = {suit, i};
            myDeck.cards.push_back(newCard);
        }
    }
    return myDeck;
}

void printCard(Card card){
    if (card.rank == 11){
        cout << 'J' << " of " << card.suit << endl;
    } else if (card.rank == 12){
        cout << 'Q' << " of " << card.suit << endl;
    } else if (card.rank == 13){
        cout << 'K' << " of " << card.suit << endl;
    } else if (card.rank == 1){
        cout << 'A' << " of " << card.suit << endl;
    } else {
        cout << card.rank << " of " << card.suit << endl;
    }
}
