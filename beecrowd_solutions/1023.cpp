#include <bits/stdc++.h> 

using namespace std; 

int main() 
{
	int N;
	cin >> N;
	int C = 1;
	while(N)
	{
		vector<int> M(201,0);
		int a, b, p = 0, c = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> a >> b;
			M[floor(b / a)] += a;
			p += a;
			c += b;
		}		

		cout << "Cidade# " << C++ << ":" << endl;

		for(int i = 0; i < 201; i++)
			if(M[i])
				cout << M[i] << "-" << i << " ";
		cout << endl;
		cout << "Consumo medio: " << fixed << setprecision(2) << (floor(c / (float) p * 100) / (float) 100.0) << " m3." << endl;
		cin >> N;
			if(N)
				cout << endl;	
	}	
	return EXIT_SUCCESS;
}

