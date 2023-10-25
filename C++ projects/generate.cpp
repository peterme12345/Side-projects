#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream file("numbers.dat");
    int max = atoi(argv[3]);
    int min = atoi(argv[2]);
    int nums = atoi(argv[1]);

    for (int x = 0; x < nums; x++)
    {
        int num = (rand() % (max - min)) + min;
        file << num << endl;
    }

    file.close();
    return 0;
}
