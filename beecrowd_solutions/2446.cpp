#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int V, M;
    cin >> V >> M;

    vector<int> Coins(M);

    for(int& c : Coins)
        cin >> c;

    vector<int> dp(V+1,0);
    dp[0] = 1;
    
    
    for(int c : Coins)
        for(int i = V; i >= c; i--)
            if(dp[i-c])
                dp[i] = 1;
    
    cout << (dp[V] ? 'S' : 'N') << endl;
    

    return EXIT_SUCCESS;
}
