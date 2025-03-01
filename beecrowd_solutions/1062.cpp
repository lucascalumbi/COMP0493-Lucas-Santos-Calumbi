#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void func(int N)
{	
	while(1)
	{
	vector<int> v(N);
	cin >> v[0];
	if(!v[0])
		break;
	for(int i = 1; i < N; i++)
		cin >> v[i];

	stack<int> s;
	bool win = true;
	int k = 1;
	for(int i : v)
	{	
		if(i == k)
		{
			k++;
			continue;
		}
		else if(s.size() && i == s.top())
			s.pop();
		else if(i > k)
			while(i > k)
			{
				s.push(k);
				k++;
			}
		else
		{	
			win = false;
			cout << "NO" << endl;
			break;
		}
	}
	if(win)
		cout << "YES" << endl;
	}
}




int main()
{
	int N;
	do
	{
		cin >> N;
		if(!N)
			break;
		func(N);

	}while(1);

	return EXIT_SUCCESS;
}
