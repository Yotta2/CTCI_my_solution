#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>

using namespace std;

struct pet {
    string name;
    char category; // c for cat, d for dog
    int enqueueOrder;
    pet(string n, char c) : name(n), category(c) {}
};

class animalShelter {
public:
    animalShelter() : order(0) {}
    void enqueue(pet *newPet) {
        newPet->enqueueOrder = order;
        order++;
        if (newPet->category == 'c')
            catQueue.push_back(newPet);
        else
            dogQueue.push_back(newPet);
    }

    pet* dequeueAny() {
        if (catQueue.empty() && dogQueue.empty())
            throw "dequeueAny error: no pets available";
        if (catQueue.front()->enqueueOrder < dogQueue.front()->enqueueOrder)
            return dequeueCat();
        else
            return dequeueDog();
    }

    pet* dequeueDog() {
        if (dogQueue.empty())
            throw "dogQueue error: no dogs available";
        pet *front = dogQueue.front();
        dogQueue.pop_front();
        return front;
    }

    pet* dequeueCat() {
        if (catQueue.empty())
            throw "catQueue error: no cats available";
        pet *front = catQueue.front();
        catQueue.pop_front();
        return front;
    }


private:
    int order; // serves as enqueue timestamp, can use system time string to avoid int overflow
    list<pet *> catQueue;
    list<pet *> dogQueue;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    animalShelter as;
    pet *p = new pet("bob", 'd');
    as.enqueue(p);
    p = new pet("mary", 'c');
    as.enqueue(p);
    p = new pet("james", 'd');
    as.enqueue(p);
    cout << as.dequeueCat()->name << endl;
    cout << as.dequeueDog()->name << endl;
    cout << as.dequeueDog()->name << endl;

    //cout << as.dequeueAny()->name << endl;
    //cout << as.dequeueAny()->name << endl;
    //cout << as.dequeueAny()->name << endl;
    return 0;
}
