#include "Blackjack.h"
#include <cstdlib>

Blackjack::Blackjack()
{
    //ctor
}

Blackjack::~Blackjack()
{
    //dtor
}

void Blackjack::getNewDeck() {
    cardsInDeck = cards;
    cardsUsed.empty();
}

Deck::Card Blackjack::nextCardOnTop() {
    Card card = cardsInDeck.back();
    cardsInDeck.pop_back();
    cardsUsed.push_back(card);
    return card;
}

bool Blackjack::deckIsEmpty() {
    return cardsInDeck.size() == 0;
}

void Blackjack::shuffle() {
    for (int i = 0; i < cardsInDeck.size(); i++) {
        int j = rand() % cardsInDeck.size();
        swap(cardsInDeck[i], cardsInDeck[j]);
    }
}
