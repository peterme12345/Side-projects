// Peter Nguyen
// CECS 325-02
// Prog 6 – 3N+1
// 04/18/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <cstdlib>

using namespace std;

struct Stats
{
    int start = 0;
    int evens = 0;
    int odds = 0;
    int steps = 0;
    int max = 0;
    int of = 0;

} stats;

void recursion(int input)
{
    if (input > stats.max)
    {
        stats.max = input;
    }

    cout << "->(" << input << ')';

    if (input % 2 == 0)
    {
        stats.evens++;
        input = input / 2;
        stats.steps++;
        try
        {
            recursion(input);
        }

        catch (int input)
        {
            cout << "overflow detected for n:" << input << endl;
            cout << "3n +1:" << input << endl;
            cout << "something broke dude" << endl;
            cout << "overflow";
        }
    }
    else if (input == 1)
    {
        cout << endl;
        cout << "start: " << stats.start << endl;
        cout << "steps: " << stats.steps << endl;
        cout << "max: " << stats.max << endl;
        cout << "odds: " << stats.odds << endl;
        cout << "evens: " << stats.evens << endl;
        stats.steps = 0;
        stats.odds = 0;
        stats.evens = 0;
        stats.max = 0;
    }
    else if (input < 0)
    {
        stats.of = input;
        cout << endl;
        cout << "overflow detected for n:" << input << endl;
        cout << "3n +1:" << input << endl;
        cout << "something broke dude" << endl;
        cout << "overflow";
        cout << endl;
    }
    else
    {
        stats.odds++;
        input = (input * 3) + 1;
        stats.steps++;
        try
        {
            recursion(input);
        }

        catch (int input)
        {
            cout << "overflow detected for n:" << input << endl;
            cout << "3n +1:" << input << endl;
            cout << "something broke dude" << endl;
            cout << "overflow";
        }
    }
}

int main(int argc, char *argv[])
{
    int input = 0;

    if (argc == 1)
    {
        cout << "Enter a candidate number: ";
        cin >> input;
        stats.start = input;

        recursion(input);

        cout << endl;
    }
    else
    {
        for (int x = 1; x < argc; ++x)
        {
            cout << "Solving 3n+1 - starting value:" << argv[x] << endl;
            input = atoi(argv[x]);
            stats.start = input;
            recursion(input);
            cout << endl;
        }
    }
    return 0;
}
