#include <iostream>
#include "Deck.h"
#include <cstdlib>

using namespace std;

Deck::Deck()

{
    top = 0;
    char s[4] = {'S', 'H', 'D', 'C'};
    char r[3] = {'J', 'Q', 'K'};
    int c = 0;
    int l = 0;
    int a = 0;
    while (a != 52)
    {
        for (int c = 0; c < 4; c++)
        {
            for (int i = 0; i < 13; i++)
            {
                if (i == 0)
                {
                    deck[a].setCard('A', s[c]);
                }
                else if (i >= 1 && i <= 8)
                {
                    char l = '0' + i;
                    deck[a].setCard(l, s[c]);
                }
                else if (i == 9)
                {
                    deck[a].setCard('T', s[c]);
                }
                else if (i == 10)
                {
                    deck[a].setCard(r[l], s[c]);
                    l++;
                }
                else if (i == 11)
                {
                    deck[a].setCard(r[l], s[c]);
                    l++;
                }
                else if (i == 12)
                {
                    deck[a].setCard(r[l], s[c]);
                    l = 0;
                }
                a++;
            }
        }
    }
}
/*

for (int c; c < 4; c++)
{
    int l = 0;
    char s[4] = {'S', 'C', 'H', 'D'};
    char r[3] = {'J', 'Q', 'K'};
    for (int i = 1; i <= 13; i++)
    {
        if (i == 1)
        {
            deck[i].setCard('A', s[c]);
        }
        else if (i > 1 && i <= 9)
        {
            char l = '0' + i;
            deck[i].setCard(l, s[c]);
        }
        else if (i == 10)
        {
            deck[i].setCard('T', s[c]);
        }
        else if (i == 11)
        {
            deck[i].setCard(r[l], s[c]);
            l++;
        }
        else if (i == 12)
        {
            deck[i].setCard(r[l], s[c]);
            l++;
        }
        else if (i == 13)
        {
            deck[i].setCard(r[l], s[c]);
            l = 0;
        }
    }
}
*/

void Deck::shuffle()
{
    Card temp;
    for (int x = 0; x < 51; x++)
    {
        int r = rand() % 52;
        int r2 = rand() % 52;

        if (r != r2)
        {
            temp = deck[r2];
            deck[r2] = deck[r];
            deck[r] = temp;
        }
    }
}

void Deck::resetDeck()
{
    top = 0;
    char s[4] = {'S', 'H', 'D', 'C'};
    char r[3] = {'J', 'Q', 'K'};
    int c = 0;
    int l = 0;
    int a = 0;
    while (a != 52)
    {
        for (int c = 0; c < 4; c++)
        {
            for (int i = 0; i < 13; i++)
            {
                if (i == 0)
                {
                    deck[a].setCard('A', s[c]);
                }
                else if (i >= 1 && i <= 8)
                {
                    char l = '0' + i;
                    deck[a].setCard(l, s[c]);
                }
                else if (i == 9)
                {
                    deck[a].setCard('T', s[c]);
                }
                else if (i == 10)
                {
                    deck[a].setCard(r[l], s[c]);
                    l++;
                }
                else if (i == 11)
                {
                    deck[a].setCard(r[l], s[c]);
                    l++;
                }
                else if (i == 12)
                {
                    deck[a].setCard(r[l], s[c]);
                    l = 0;
                }
                a++;
            }
        }
    }
}

Card Deck::deal()
{

    if (top < 52)
    {
        return deck[top++];
    }
    else
    {
        return Card();
    }
}

void Deck::show()

{
    int acc = 0;
    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 13; b++)
        {
            deck[acc++].show();
        }
        cout << endl;
        cout << endl;
    }
}

bool Deck::isEmpty()
{
    if (top <= 51)
    {
        return false;
    }
    else
    {
        return true;
    }
}
