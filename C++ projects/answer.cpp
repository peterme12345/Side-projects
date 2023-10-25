#include <fstream>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

const int ARRAY_SIZE = 1000000;
const int THREADS_NUM = 8;
const int PART_SIZE = ARRAY_SIZE / THREADS_NUM;

void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void *sort_thread(void *arg)
{
    int *array = (int *)arg;
    bubble_sort(array, PART_SIZE);
    return NULL;
}

int main(int argc, char *argv[])
{
    ofstream output(argv[2]);
    ifstream file(argv[1]);

    int data;
    int count = 0;

    while (file >> data)
    {
        count++;
    }

    int nums[ARRAY_SIZE];

    file.clear();
    file.seekg(0, ios::beg);

    int n = 0;

    while (file >> data)
    {
        nums[n] = data;
        n++;
    }

    file.close();

    pthread_t threads[THREADS_NUM];

    int *array_ptrs[THREADS_NUM];

    for (int i = 0; i < THREADS_NUM; i++)
    {
        array_ptrs[i] = &nums[i * PART_SIZE];
        pthread_create(&threads[i], NULL, sort_thread, array_ptrs[i]);
    }

    for (int i = 0; i < THREADS_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted subarrays
    int merged[ARRAY_SIZE];

    for (int i = 0; i < THREADS_NUM; i++)
    {
        for (int j = 0; j < PART_SIZE; j++)
        {
            merged[i * PART_SIZE + j] = array_ptrs[i][j];
        }
    }

    bubble_sort(merged, ARRAY_SIZE);

    // Write the sorted array to output file
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        output << merged[i] << endl;
    }

    output.close();

    return 0;
}
