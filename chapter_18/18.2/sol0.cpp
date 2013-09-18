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
#include <time.h>

#define EPS 1e-6
#define SIZE 300

using namespace std;

enum Suit {Spade, Heart, Diamond, Club};

struct Card {
    Suit suit;
    int num;
    Card(Suit s, int n) : suit(s), num(n) {}
    Card() {}
};

vector<Card> createDeck() {
    vector<Card> deck;
    for (int i = 0; i <= 3; i++)
        for (int j = 1; j <= 13; j++) {
            Card card;
            card.num = j;
            switch (i) {
            case 0:
                card.suit = Spade;
                break;
            case 1:
                card.suit = Heart;
                break;
            case 2:
                card.suit = Diamond;
                break;
            case 3:
                card.suit = Club;
                break;
            }
            deck.push_back(card);
        }
    return deck;
}

void shuffleDeck(vector<Card> &deck) {
    srand(time(NULL));
    for (int i = deck.size() - 1; i >= 1; i--) {
        int index = rand() % (i + 1);
        swap(deck[i], deck[index]);
    }
}

void printDeck(vector<Card> &deck) {
    for (int i = 0; i < deck.size(); i++)
        cout << deck[i].suit << " " << deck[i].num << endl;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<Card> deck = createDeck();
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}
