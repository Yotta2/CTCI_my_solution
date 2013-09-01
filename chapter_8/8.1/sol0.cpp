#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include "Deck.h"
#include "Blackjack.h"

#define EPS 1e-6

using namespace std;

void testDeck() {
    Deck deck;
    deck.shuffle();
    cout << deck.toString() << endl;
}

void testBlackjack() {
    Blackjack blackjack;
    blackjack.getNewDeck();
    blackjack.shuffle();

    cout << blackjack.toString() << endl;
    int count = 1;
    while (!blackjack.deckIsEmpty()) {
        cout << count << "th card is ";
        Blackjack::Card card = blackjack.nextCardOnTop();
        switch (card.suit) {
        case Blackjack::CardSuit::CLUB:
            cout << "CLUB" << card.num << endl;
            break;
        case Blackjack::CardSuit::DIAMOND:
            cout << "DIAMOND" << card.num << endl;
            break;
        case Blackjack::CardSuit::HEART:
            cout << "HEART" << card.num << endl;
            break;
        case Blackjack::CardSuit::SPADE:
            cout << "SPADE" << card.num << endl;
            break;
        }
        count++;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //testDeck();
    testBlackjack();
    return 0;
}
