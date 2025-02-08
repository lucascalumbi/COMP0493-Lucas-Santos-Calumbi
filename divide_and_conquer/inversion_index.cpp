#include <iostream>

using namespace std;

            // vector<int>& array
int count_merge(int* array, int left, int mid, int right) // begin_l = comeco do vetor da esquerda
{    
    int i = left;
    int j = mid+1;

    int invs = 0;
    while(i <= mid && j <= right)
    {
        if(array[i] <= array[j])
            i++;
        else
        {   
            invs += (mid - i + 1); // Todos os elementos restantes no vetor da esquerda são maiores que array[j]
            int temp = array[j];

            for(int k = j; k > i; k--)
                array[k] = array[k-1]; // faz um shift pra direita

            array[i] = temp;
            i++;
            j++;
            mid++;
        }
    }
    return invs;
}
                // vector<int>& array
int count_merge_sort(int* array, int left, int right)
{   
    if(!(left < right))
        return 0;
    
    int mid = left + (right - left) / 2;
    int invs = 0;

    invs += count_merge_sort(array, left, mid);
    invs += count_merge_sort(array, mid + 1, right);

    invs += count_merge(array, left, mid, right);

    return invs;
}

int main(void)
{

    int array[] = {3,2,1,0};
    int array_size = sizeof(array)/sizeof(int);
 
    cout << count_merge_sort(array, 0, array_size - 1) << endl;

    return EXIT_SUCCESS;
}