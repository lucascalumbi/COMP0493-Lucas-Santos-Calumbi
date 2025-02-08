#include <iostream>

using namespace std;

int get_max(int* array, int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void counting_sort_stable(int* array, int size, int exp) 
{
    int max_value = get_max(array,size);

    int count_array[max_value+1] = {0};

    for(int i = 0; i < size; i++) 
        count_array[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count_array[i] += count_array[i - 1];

    int sorted_array[size];

    for (int i = size - 1; i >= 0; i--) {
        sorted_array[count_array[(array[i] / exp) % 10] - 1] = array[i];
        count_array[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = sorted_array[i];
}

void radixsort(int* array, int size)
{
    int max = get_max(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_stable(array, size, exp);
}


