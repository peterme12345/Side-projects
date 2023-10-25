// Peter Nguyen
// CECS 325-02
// Prog 2 – fibo Solitaire (Single File)
// 02/21/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card
{
public:
    char rank;
    char suit;

    Card();
    Card(char r, char s);
    int getValue();
    void show();
    void setCard(char r, char s);
};

class Deck
{
public:
    Card deck[52];
    int top;

    Deck();
    void shuffle();
    void resetDeck();
    Card deal();
    void show();
    bool isEmpty();
};

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

bool isFibo(int i)
{
    if (i == 1 || i == 2 || i == 3 || i == 5 || i == 8 || i == 13 || i == 21 || i == 34 || i == 55 || i == 89 || i == 144 || i == 233 || i == 377 || i == 610)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Deck d;
    int sum = 0;
    int wins = 0;
    int games = 0;
    int user;
    while (user != 6)
    {

        cout << "\nWelcome to Fibonacci Solitaire!\n1) Create New Deck\n2) Shuffle Deck\n3) Display Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire\n6) Exit" << endl;

        cout << "Enter option: ";

        cin >> user;

        if (user == 1)
        {
            d.resetDeck();
        }
        else if (user == 2)
        {
            d.shuffle();
        }
        else if (user == 3)
        {
            d.show();
        }
        else if (user == 4)
        {
            wins = 0;
            cout << endl;
            cout << "Playing Fibonacci Solitaire!!!" << endl;
            cout << endl;
            while (d.isEmpty() == false)
            {

                Card c = d.deal();
                sum += c.getValue();
                c.show();
                if (isFibo(sum) == true)
                {
                    cout << "Fibo: " << sum << " " << endl;
                    sum = 0;
                    wins++;
                }
                if (d.isEmpty() == true && isFibo(sum) == false)
                {
                    wins++;
                    cout << "Last Pile NOT Fibo: " << sum << endl;
                    cout << endl;
                    cout << "Loser in " << wins << " piles!" << endl;
                    sum = 0;
                }
                else if (d.isEmpty() == true && isFibo(sum) == true)
                {
                    cout << "Winner in " << wins << " piles!" << endl;
                }
            }
        }
        else if (user == 5)
        {
            bool loop = isFibo(sum);
            while (loop != true)
            {
                while (d.isEmpty() == false)
                {

                    Card c = d.deal();
                    sum += c.getValue();
                    c.show();
                    if (isFibo(sum) == true)
                    {
                        cout << "Fibo: " << sum << " " << endl;
                        wins++;
                        if (d.isEmpty() == true)
                        {
                            break;
                        }
                        else
                        {
                            sum = 0;
                        }
                    }
                }
                if (isFibo(sum) == true)
                {
                    cout << "Winner in " << wins << " piles!" << endl;
                    loop = true;
                }
                else
                {
                    d.resetDeck();
                    d.shuffle();
                    sum = 0;
                }

                games++;
            }
            cout << endl;
            cout << "games played:" << games << endl;
            cout << endl;
        }
    }
    return 0;
}