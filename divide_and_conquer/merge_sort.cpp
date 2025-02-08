#include <iostream>

using namespace std;

        // vector<int>& array
void merge(int* array, int left, int mid, int right) // begin_l = comeco do vetor da esquerda
{    
    int i = left;
    int j = mid+1;

    while(i <= mid && j <= right)
    {
        if(array[i] <= array[j])
            i++;
        else
        {
            int temp = array[j];

            for(int k = j; k > i; k--)
                array[k] = array[k-1]; // faz um shift pra direita

            array[i] = temp;
            i++;
            j++;
            mid++;
        }
    }
}
            // vector<int>& array
void merge_sort(int* array, int left, int right)
{   
    if(!(left < right))
        return;
    
    int mid = left + (right - left) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    merge(array, left, mid, right);
}

void print_array(int* A, int size)
{
    for (int i = 0; i < size; i++)
        cout <<" "<< A[i];
    cout << endl;
}

int main(void)
{

    int array[] = {40, 90, 30, 45, 58, 1, 0, 34};
    int array_size = 8;
 
    merge_sort(array, 0, array_size - 1);
 
    print_array(array, array_size);

    return EXIT_SUCCESS;
}