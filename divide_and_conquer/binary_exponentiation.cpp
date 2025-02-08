#include <iostream>

using namespace std;

unsigned long long int binary_exponentiation(unsigned long long int x, unsigned long long int n)
{
    if(n == 0)
        return 1;

    unsigned long long int half = binary_exponentiation(x, n / 2);
    
    if(n % 2 == 0) 
        return half * half;
    else 
        return x * half * half;

}

int main(void)
{
    cout << binary_exponentiation (2,30) << endl;
    return EXIT_SUCCESS;
}