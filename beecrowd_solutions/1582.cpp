#include <bits/stdc++.h> 

using namespace std;

int mdc(int a, int b)
{
	while(b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	
	return a;
}

int main()
{
	vector<int> v(3,0);

	while(cin >> v[0] >> v[1] >> v[2])
	{	
		if(!(v[0] + v[1] + v[2]))
			break;
		sort(v.begin(), v.end());
		bool pitagorica = (v[2]*v[2] == (v[1]*v[1] + v[0]*v[0]));
		int max_dc = mdc(v[0],mdc(v[1],v[2]));
		if(pitagorica && max_dc == 1)
			cout << "tripla pitagorica primitiva" << endl;
		else if(pitagorica && max_dc != 1)
			cout << "tripla pitagorica" << endl;
		else
			cout << "tripla" << endl;
	}

	return EXIT_SUCCESS;
}
