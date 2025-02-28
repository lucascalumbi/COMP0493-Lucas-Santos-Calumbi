#include <bits/stdc++.h>

using namespace std;

void func(int N, int Q, int T)
{
	cout << "CASE# " << T << ":" << endl;

	vector<int> v(N);

	for(int& a : v)
		cin >> a;

	sort(v.begin(),v.end());

	for(int i = 0; i < Q; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j <= N; j++)
			if(j == N)
				cout << k << " not found" << endl;
			else if(v[j] == k)
			{
				cout << k << " found at " << j+1 << endl;
				break;
			}
	}

}




int main()
{
	int N, Q, T = 1;

	while(cin >> N >> Q)
	{
		if(!(N+Q))
			break;

		func(N,Q,T);
		T++;
	}

	return EXIT_SUCCESS;
}
