#include <iostream>

using namespace std;

void counting_sort_unstable(int* array, int size) // to considerando size > 0
{
    int max_value = array[0];
    for(int i = 1; i < size; i++) // pega o maior
        if(max_value < array[i])
            max_value = array[i];

    int count_array[max_value+1] = {0};

    for(int i = 0; i < size; i++) // faz a contagem
        count_array[array[i]]++;

    int sorted_array[size];
    int index = 0;
    for(int i = 0; i <= max_value; i++) // preenche o array com base na contagem
        while(count_array[i] > 0)
        {
            array[index] = i;
            index++;
            count_array[i]--;
        }
}

void counting_sort_stable(int* array, int size) // to considerando size > 0
{
    int max_value = array[0];
    for(int i = 1; i < size; i++)
        if(max_value < array[i])
            max_value = array[i];

    int count_array[max_value+1] = {0}; 

    for(int i = 0; i <size; i++)
        count_array[array[i]]++;

    for (int i = 1; i <= max_value; i++) // faz um shift no vetor
        count_array[i] += count_array[i - 1];

    int sorted_array[size];

    for (int i = size - 1; i >= 0; i--) 
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for(int i = 0; i < size; i++) // copia de volta pro array original
        array[i] = sorted_array[i];

}

 