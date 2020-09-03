//
//  CardDeck.cpp
//  DeckOfCards
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn and Tyler Jette. All rights reserved.
//
#include <iostream>
#include <ctime>
#include "CardDeck.hpp"
using namespace std;

//Creates a deck of cards
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

//Prints a Card
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

//Gives a random index for a deck of cards.
int newIndex(Deck& deck){
    int random = rand();
    int val = (random % deck.cards.size());
    return val;
}

//Swaps a card with another card in a deck
void swap(Card& firstIndex, Card& swapIndex){
    Card temp = firstIndex;
    firstIndex=swapIndex;
    swapIndex = temp;
    }

int findMin(const Deck& deck){
    int least = deck.cards[0].rank;
    for(int i = 0; i < deck.cards.size(); i ++){
        if(deck.cards[i].rank < least){
          least = deck.cards[i].rank;
        }
    }
  return least;
}

int findMax(const Deck& deck){
    int max = deck.cards[0].rank;
    for(Card c : deck.cards){
        if(c.rank > max)
            max = c.rank;
    }
    return max;
}

bool contains(const Deck& deck, int lookFor){
    for(Card c : deck.cards){
      if(c.rank == lookFor)
      return true;
  }
  return false;
}

Deck shuffle(Deck& deck){
    for (int currentIndex = 0; currentIndex < deck.cards.size(); currentIndex++){
        int randomIndex = newIndex(deck);
        swap(deck.cards[currentIndex], deck.cards[randomIndex]);
    }
    return deck;
}

bool isFlush(const Deck& deck){
    string suit = deck.cards[1].suit;
    for (int i = 1; i < 5; i++){
        if(!(deck.cards[i].suit==suit)){
            return false;
        }
    }
    return true;
}

Deck fiveCards(Deck deck){
    Deck fiveCardDraw;
    for (int i = 0; i < 5; i++){
        fiveCardDraw.cards.push_back(deck.cards[i]);
    }
    return fiveCardDraw;
}

bool isStraight(const Deck& deck){
  int min = findMin(deck);
  int range = min + 4;
  for(int i = min; i < range; i++){
    if(!(contains(deck, i)))
      return false;
  }
  return true;
};

bool isStraightFlush(const Deck& deck){
    return (isStraight(deck) == true && isFlush(deck) == true);
}

bool isFullHouse(const Deck& deck){
    int min = findMin(deck);
    int max = findMax(deck);
    int minCount = 0;
    for (int i = 0; i < deck.cards.size(); i ++){
        if (deck.cards[i].rank != min && deck.cards[i].rank != max){
            return false;
        } else if (deck.cards[i].rank == min) {
            minCount++;
        } else {
            //Do nothing
        }
        if (minCount ==1 || minCount == 4){
            return false;
        }
    }
    return true;
}

