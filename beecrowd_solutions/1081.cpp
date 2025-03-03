#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& g, vector<int>& visited, int v, int b)
{
	visited[v] = 1;
	for(int i : g[v])
	{
		if(visited[i])
		{
			cout << string(b,' ') << v << "-" << i << endl;
			continue;
		}
		cout << string(b,' ') << v << "-" << i << " pathR(G," << i << ")" << endl;
		dfs(g,visited,i,b+2);
	}
}

int main(void)
{
	int N, count = 1;
	cin >> N;
	
	while(N--)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> G(V);
		
		for(int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
		}
		
		cout << "Caso " << count++ << ":" << endl;
		vector<int> visited(V,0);
		
		for(int i = 0; i < V; i++)
			sort(G[i].begin(),G[i].end());

		for(int i = 0; i < V; i++)
			if(!G[i].empty() && !visited[i])
			{
				dfs(G,visited,i,2);
				cout << endl;
			}
	}

	return EXIT_SUCCESS;
}

