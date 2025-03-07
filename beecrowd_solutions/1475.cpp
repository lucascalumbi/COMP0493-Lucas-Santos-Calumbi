#include <bits/stdc++.h>

using namespace std;

int func(vector<int>& fs, int N, int C, int T1, int T2);
{
	


}

int main(void)
{
	int N, C, T1, T2;
	while(cin >> N >> C >> T1 >> T2)
	{
		vector<int> fs(N);
		for(int& f : fs)
			cin >> f;
		
		cout << func(fs,N,C,T1,T2);
	}	

	return EXIT_SUCCESS;
}

