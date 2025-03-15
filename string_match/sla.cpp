#include <bits/stdc++.h>

using namespace std;

vector<int> lps(string s, int m)
{
	vector<int> v;
	int i = 1;
	int j = 0;
	while(i<m)
	{
		if(s[i] = s[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else if(j!=0)
			j = lps[j-1];
		else
		{


int main(void)
{








	return EXIT_SUCCESS;
}

