#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

bool func(vector<bool>& ps,int p)
{
	while(p)
	{
		if(!(ps[p%10]))
			return false;
		p = p/10;
	} 
	return true;
}

int main()
{
	vector<bool> ps(MAX,true);

	ps[0] = false;
	ps[1] = false;

	for(int i = 2; i*i < MAX; i++)
		if(ps[i])
			for(long int j = i*i; j < MAX; j+=i)
				ps[j] = false;	
		

	int N;
	while(cin >> N)
	{
		if(func(ps, N) && ps[N])
			cout << "Super" << endl;
		else if(ps[N])
			cout << "Primo" << endl;
		else
			cout << "Nada" <<  endl;
	}


	return EXIT_SUCCESS;
} 

