#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class BigInt
{
private:
    vector<char> v;

public:
    BigInt();
    BigInt(int);
    BigInt(string);
    BigInt operator+(BigInt);
    BigInt operator++();
    BigInt operator++(int);

    BigInt half();
    bool isOdd();
    bool isEven();
    bool BigInt::operator==(const BigInt &);
    friend ostream &operator<<(ostream &, const BigInt &n);
};

BigInt &BigInt::operator++()
{
    v.push_back(v.back() + 1);
    return *this;
}

bool BigInt::isEven()
{
    return v.back() % 2 == 0;
}

bool BigInt::operator==(const BigInt &other)
{
    if (v.size() != other.v.size())
    {
        return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != other.v[i])
        {
            return false;
        }
    }
    return true;
}

struct Stats
{
    BigInt start = 0;
    BigInt evens = 0;
    BigInt odds = 0;
    BigInt steps = 0;
    BigInt max = 0;

} stats;

void print(Stats temp)
{
    cout << "start:" << temp.start << endl;
    cout << "steps:" << temp.steps << endl;
    cout << "max:" << temp.max << endl;
    cout << "odds:" << temp.odds << endl;
    cout << "evens:" << temp.evens << endl;
}

void findThreeNp1(BigInt n, Stats &stats, bool printSteps = false)
{
    if (printSteps)
    {
        cout << "->" << '(' << n << ')';
    }
    if (stats.max < n)
        stats.max = n;

    if (n == BigInt(1))
    {
        return;
    }
    else if (n.isEven())
    {
        stats.evens++;
        stats.steps++;

        findThreeNp1(n / 2, stats, printSteps);
    }
    else if (n.isOdd()) // BigInt::isOdd( )
    {
        stats.odds++;
        stats.steps++;
        BigInt tempN = n;
        findThreeNp1(tempN * 3 + 1, stats, printSteps);
        // BigInt::operator+( )
    }
    else
    {
        cout << "How the hell did I get here?\n";
        return;
    }
}

int main(int argc, char *argv[])
{
    BigInt MAX(INT_MAX);
    cout << "The largest integer is " << MAX << endl;
    cout << "Twice the largest integer is " << MAX + MAX << endl;
    // BigInt start(INT_MAX);
    BigInt start(12);
    bool printSteps = true;
    Stats N = {start, 0, 0, 0, 0};
    findThreeNp1(start, N, printSteps);
    cout << endl;
    print(N);
    return 0;
}