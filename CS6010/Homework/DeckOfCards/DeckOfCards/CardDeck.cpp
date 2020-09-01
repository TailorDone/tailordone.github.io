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
    vector<string> suits = {"S", "C", "D", "H"};
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
        cout << 'J' << card.suit << endl;
    } else if (card.rank == 12){
        cout << 'Q' << card.suit << endl;
    } else if (card.rank == 13){
        cout << 'K' << card.suit << endl;
    } else if (card.rank == 1){
        cout << 'A' << card.suit << endl;
    } else {
        cout << card.rank << card.suit << endl;
    }
}
