#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucket_sort(float* array, int size)
{
    vector<float> bucket[size];

    for(int i = 0; i < size; i++)
    {
        int bucket_index = size*array[i];
        bucket[bucket_index].push_back(array[i]);
    }

    for(int i = 0; i < size; i++)
        sort(bucket[i].begin(), bucket[i].end());

    
    for(int index = 0, i = 0; i < size; i++)
        for(int j = 0; j < bucket[i].size(); j++)
            array[index++] = bucket[i][j];

}

void print_array(float* array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

