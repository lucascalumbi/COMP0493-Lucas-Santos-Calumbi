#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& G, vector<int>& visited, int v)
{
	int count = 0;
	visited[v] = 1;
	for(int i : G[v])
	{	
		if(visited[i])
			continue;
		count += dfs(G,visited,i);
	}
	return count+1;
} 

int main(void)
{
	int T;
	cin >> T;
	
	while(T--)
	{
		int N, V, A;
		cin >> N;
		cin >> V >> A;
		vector<vector<int>> G(V);
		for(int i = 0; i < A; i++)
		{
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		vector<int> visited(V,0);
		cout << 2*(dfs(G,visited,N)-1) << endl;
	}	


	return EXIT_SUCCESS;
}

