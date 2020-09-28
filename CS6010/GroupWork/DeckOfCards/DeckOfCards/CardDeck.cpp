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
#include <cassert>
using namespace std;

//Global Variables
int numberOfShuffles = 0;
int Flush = 0;
int straight = 0;
int straightFlush = 0;
int royalFlush = 0;
int fullHouse = 0;

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
    runHandAnalysis(deck);
    return deck;
}

bool isFlush(const Deck& deck){
    string suit = deck.cards[0].suit;
    for (int i = 1; i < 5; i++){
        if(deck.cards[i].suit!=suit){
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
    Deck playerHand = fiveCards(deck);
    int min = findMin(playerHand);
  int range = min + 4;
  for(int i = min; i < range; i++){
      if(!(contains(playerHand, i)))
      return false;
  }
  return true;
};

bool isStraightFlush(const Deck& deck){
    return (isStraight(deck) == true && isFlush(deck) == true);
}

bool isRoyalFlush(const Deck& deck){
    Deck playerHand = fiveCards(deck);
    int min = findMin(playerHand);
    bool ans;
    (isFlush(playerHand) && isStraight(playerHand) && min == 10) ? ans = true : ans = false;
    return ans;

}

bool isFullHouse(const Deck& deck){
    Deck playerHand = fiveCards(deck);
    int min = findMin(playerHand);
    int max = findMax(playerHand);
    int minCount = 0;
    for (int i = 0; i < 5; i ++){
        if (playerHand.cards[i].rank != min && playerHand.cards[i].rank != max){
            return false;
        } else if (playerHand.cards[i].rank == min) {
            minCount++;
        } else {
            //Do nothing
        }
    }
    if (minCount ==1 || minCount == 4){
        return false;
    }
    return true;
}

void runHandAnalysis(const Deck& deck){
    if(isFlush(deck)){
        Flush++;
    }
    if(isStraight(deck)){
        straight++;
    }
    if(isStraightFlush(deck)){
        straightFlush++;
    }
    if(isRoyalFlush(deck)){
        royalFlush++;
    }
    if(isFullHouse(deck)){
        fullHouse++;
    }
}

void printStats(int upperBounds, Deck& deck){
    for(int i = 0; i < upperBounds; i++){
        shuffle(deck);
    }
    
    cout<<"statistical relevance for "<<upperBounds<<" hands: "<<endl;
    cout<<"Flush: "<<Flush<<" / "<<upperBounds<<endl;
    cout<<"Straight: "<<straight<<" / "<<upperBounds<<endl;
    cout<<"StraightFlush: "<<straightFlush<<" / "<<upperBounds<<endl;
    cout<<"RoyalFlush: "<<royalFlush<<" / "<<upperBounds<<endl;
    cout<<"FullHouse : "<<fullHouse<<" / "<<upperBounds<<endl;
}

void runTests(){
    Deck deck = createDeck();
    assert(deck.cards.size() == 52); //check for proper number of cards in the deck (52)
    int hearts = 0;
    int spades = 0;
    int diamonds = 0;
    int clubs = 0;
    for(int i = 0; i < deck.cards.size(); i++){
        if(deck.cards[i].suit == "Hearts"){
            hearts++;
        }else if(deck.cards[i].suit == "Diamonds"){
            diamonds++;
        }else if(deck.cards[i].suit == "Spades"){
            spades++;
        }else if(deck.cards[i].suit == "Clubs"){
            clubs++;
        }
    }
    //checks proper size for suits, respectively.
    assert(hearts == 13);
    assert(diamonds == 13);
    assert(spades == 13);
    assert(clubs == 13);
    //test that the ranks are within 2 - 14
    for(Card c : deck.cards){
        assert((c.rank >= 1) && (c.rank <= 13));
        
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
        assert(isFullHouse(newDeck2)==true);
    }
}

