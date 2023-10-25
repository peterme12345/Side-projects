// Peter Nguyen
// CECS 325-02
// Prog 5 – Sorting Contest using Threads
// 04/06/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <functional>

using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void *sorty(int *array, int size)
{
    quick_sort(array, 0, size - 1);
    return NULL;
}

int *merge(int *a1, int n1, int *a2, int n2)
{
    int *merged = new int[n1 + n2];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            merged[k] = a1[i];
            i++;
        }
        else
        {
            merged[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        merged[k] = a1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        merged[k] = a2[j];
        j++;
        k++;
    }

    return merged;
}

int main(int argc, char *argv[])
{
    ofstream output(argv[2]);
    ifstream file(argv[1]);

    int data;
    int count = 0;
    int n = 0;

    while (file >> data)
    {
        count++;
    }

    int nums[count];

    file.clear();
    file.seekg(0, ios::beg);

    while (file >> data)
    {
        nums[n] = data;
        n++;
    }

    int size = count / 8;

    int *ptrs[8];
    thread threads[8];

    for (int i = 0; i < 8; i++)
    {
        ptrs[i] = &nums[i * size];
        threads[i] = thread(sorty, ptrs[i], size);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    int *temp = merge(merge(merge(ptrs[0], size, ptrs[1], size), size * 2, merge(ptrs[2], size, ptrs[3], size), size * 2), size * 4, merge(merge(ptrs[4], size, ptrs[5], size), size * 2, merge(ptrs[6], size, ptrs[7], size), size * 2), size * 4);

    for (int i = 0; i < count; i++)
    {
        output << temp[i] << endl;
    }
    delete[] temp;
    file.close();
    output.close();
    return 0;
}
