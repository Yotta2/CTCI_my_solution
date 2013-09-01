#include "Deck.h"
#include <cstdlib>
#include <algorithm>

Deck::Deck() {
    Deck::CardSuit suits[4] = {Deck::CardSuit::CLUB, Deck::CardSuit::DIAMOND,
                              Deck::CardSuit::HEART, Deck::CardSuit::SPADE};
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++) {
            Deck::Card card(suits[i], j);
            cards.push_back(card);
        }
}

Deck::~Deck() {
}

void Deck::shuffle() {
    for (int i = 0; i < cards.size(); i++) {
        int j = rand() % cards.size();
        swap(cards[i], cards[j]);
    }
}

string Deck::toString() {
    string res;

    for (int i = 0; i < cards.size(); i++) {
        char s;
        switch(cards[i].suit) {
        case CardSuit::CLUB:
            s = 'C';
            break;
        case CardSuit::DIAMOND:
            s = 'D';
            break;
        case CardSuit::HEART:
            s = 'H';
            break;
        case CardSuit::SPADE:
            s = 'S';
            break;
        }
        res += s;
        res += '0' + cards[i].num;
        res += ' ';
        if (i % 13 == 0)
            res += '\n';
    }
    return res;
}
