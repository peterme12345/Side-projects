#include <iostream>
#include "Card.h"

using namespace std;

    char rank;
    char suit;
   

Card::Card()
{
    rank = '0';
    suit = '0';
}
Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}

int Card::getValue()
{
    if (rank == 'A')
    {
        return 1;
    }
    else if (rank == '2')
    {
        return 3;
    }
    else if (rank == '3')
    {
        return 4;
    }
    else if (rank == '4')
    {
        return 5;
    }
    else if (rank == '5')
    {
        return 6;
    }
    else if (rank == '6')
    {
        return 7;
    }
    else if (rank == '7')
    {
        return 8;
    }
    else if (rank == '8')
    {
        return 9;
    }
    else if (rank == '9')
    {
        return 10;
    }
    else if (rank == 'T' || rank == 'K' || rank == 'Q' || rank == 'J')
    {
        return 10;
    }
    else
    {

        return 2;
    }
}

void Card::show()
{

    if (rank == 'T')
    {
        cout << 10 << suit << ", ";
    }
    else if (rank <= 57 && rank >= 49)
    {
        cout << (char)(rank + 1) << suit << ", ";
    }
    else
    {
        cout << rank << suit << ", ";
    }
}

void Card::setCard(char r, char s)
{
    rank = r;
    suit = s;
}
