#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

class Deck {
public:
    Deck();
    ~Deck();
    void shuffle();
    string toString();
    enum CardSuit {SPADE, HEART, DIAMOND, CLUB};
    struct Card {
        CardSuit suit;
        int num;
        Card(CardSuit s, int n) : suit(s), num(n) {}
    };
protected:
    vector<Card> cards;
};

#endif // DECK_H_INCLUDED
