#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class BigInt
{
private:
    vector<char> v;

public:
    BigInt(){};
    BigInt(int n)
    {
        char digit;
        while (n > 9)
        {
            digit = n % 10;
            n /= 10;
            v.push_back(digit);
        }
        digit = n;
        v.push_back(digit);
    }

    BigInt(string s)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char d = s[i];
            if (isdigit(d))
            {
                v.push_back(d - '0');
            }
        }
    }
    BigInt operator+(BigInt other)
    {
        int carry = 0;
        int i = 0;
        vector<char> result;

        while (i < v.size() || i < other.v.size() || carry > 0)
        {
            int sum = carry;
            if (i < v.size())
            {
                sum += v[i];
            }
            if (i < other.v.size())
            {
                sum += other.v[i];
            }
            carry = sum / 10;
            result.push_back(sum % 10);
            i++;
        }

        BigInt sum;
        sum.v = result;
        return sum;
    }
    BigInt operator++()
    {
        BigInt temp = *this;
        *this = *this + BigInt(1);
        return temp;
    }
    BigInt operator++(int)
    {
        *this = *this + BigInt(1);
        return *this;
    }

    BigInt operator*(BigInt other)
    {

        int n1 = v.size();
        int n2 = other.v.size();

        vector<char> result(n1 + n2, 0);

        int i_n1 = 0;
        int i_n2 = 0;

        for (int i = n1 - 1; i >= 0; i--)
        {
            int carry = 0;
            int num1 = v[i];

            i_n2 = 0;

            for (int j = n2 - 1; j >= 0; j--)
            {
                int num2 = other.v[j];
                int sum = num1 * num2 + result[i_n1 + i_n2] + carry;

                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            if (carry > 0)
            {
                result[i_n1 + i_n2] += carry;
            }

            i_n1++;
        }

        while (result.size() > 1 && result.back() == 0)
        {
            result.pop_back();
        }

        BigInt resultBigInt;
        resultBigInt.v = result;
        return resultBigInt;
    }

    BigInt half() const
    {
        if (v.size() == 1)
        {
            return BigInt(v[0] / 2);
        }

        BigInt result;
        result.v.resize(v.size());
        int carry = 0;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            int current = v[i] + carry * 10;
            result.v[i] = current >> 1;
            carry = current & 1;
        }

        while (result.v.size() > 1 && result.v.back() == 0)
        {
            result.v.pop_back();
        }

        return result;
    }

    bool isOdd() const
    {

        return v.front() % 2 == 1;
    }

    bool isEven() const
    {

        return v.front() % 2 == 0;
    }
    bool operator==(const BigInt &other)
    {
        return v == other.v;
    }
    bool operator<(const BigInt &other) const
    {
        if (v.size() < other.v.size())
            return true;
        if (v.size() > other.v.size())
            return false;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] < other.v[i])
                return true;
            if (v[i] > other.v[i])
                return false;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, const BigInt &n)
    {
        for (int i = n.v.size() - 1; i >= 0; i--)

            cout << (int)n.v[i];
        return out;
    }
};

struct Stats
{
    BigInt start;
    BigInt evens;
    BigInt odds;
    BigInt steps;
    BigInt max;

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

        findThreeNp1(n.half(), stats, printSteps);
    }
    else if (n.isOdd())
    {
        stats.odds++;
        stats.steps++;
        BigInt tempN(n);
        findThreeNp1(tempN * BigInt(3) + BigInt(1), stats, printSteps);
    }
    else
    {
        cout << "How the hell did I get here?\n";
        return;
    }
}

int main()
{
    BigInt B1(1);
    cout << B1 << endl;
    cout << "The largest integer is " << B1 << endl;
    cout << "Twice the largest integer is " << B1 + B1 << endl;
    BigInt start(12);
    bool printSteps = true;
    Stats N = {start, 0, 0, 0, 0};
    findThreeNp1(start, N, printSteps);
    cout << endl;

    return 0;
}