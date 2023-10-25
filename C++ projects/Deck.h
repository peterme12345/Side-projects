#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
    Card deck[52];
    int top;

public:
    Deck();

    void resetDeck();

    Card deal();

    void shuffle();

    bool isEmpty();

    void show();
};
#endif