#include <bits/stdc++.h>

using namespace std;

int sum(int i, vector<int>& bit)
{
	int parcial_sum = 0;
	
	while(i > 0)
	{
		parcial_sum += bit[i];
		i -= (i & (-i));
	}
	
	return parcial_sum;
}

int range_sum(int l, int r, vector<int>& bit)
{
	return sum(r,bit) - sum(l-1,bit);
}

void add(int i, int p, vector<int>& bit)
{
	while(i < bit.size())
	{
		bit[i] += p;
		i += (i & (-i));
	}
}	

int prefix_sum(int i, vector<int>& bit)
{
	return sum(i,bit);
}

void update(int i, int new_value, vector<int>& bit, vector<int>& ps) {
    int diff = new_value - ps[i];
    ps[i] = new_value;
    add(i, diff, bit);
}

void abduct(int i, vector<int>& bit, vector<int>& ps) {
    if (ps[i] > 0) 
	{  
        add(i, -ps[i], bit);
        ps[i] = 0;  
    }
}

int main(void)
{

	int N;
	cin >> N;
	
	vector<int> ps(N+1,0);
	vector<int> bit(N+1,0);

	for(int i = 1; i < N+1; i++)
	{
		cin >> ps[i];	
		add(i,ps[i],bit);
	}

	char f;
	int s;
	while(cin >> f >> s)
	{
		if(f == 'a')
			abduct(s,bit,ps);
		else if(f == '?')
			cout << range_sum(0,N,bit) << endl;
	}

	return EXIT_SUCCESS;
}

