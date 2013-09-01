#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

#include "Deck.h"
#include <vector>

class Blackjack : public Deck
{
public:
    Blackjack();
    ~Blackjack();
    Deck::Card nextCardOnTop();
    void getNewDeck();
    bool deckIsEmpty();
    void shuffle();
private:
    vector<Deck::Card> cardsInDeck;
    vector<Deck::Card> cardsUsed;
};

#endif // BLACKJACK_H_INCLUDED
