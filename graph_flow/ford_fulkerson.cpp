#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>>& G, int s, int t, vector<int> parent)
{
	vector<bool> visited(G.size(),false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) 
	{
		int i = q.front();
		q.pop();

		for(int v : G[i])
			if(v > 0 && !visited[v])
			{
				if (v == t) 
				{
					parent[v] = i;
					return true;
				}
				q.push(v);
				parent[v] = i;
				visited[v] = true;
			}
		
	}
	return false;
}

int max_flow(vector<vector<int>>& G, int s, int t)
{
	int u, v;

	int rGraph[V]
			[V]; // Residual graph where rGraph[i][j]
				// indicates residual capacity of edge
				// from i to j (if there is an edge. If
				// rGraph[i][j] is 0, then there is not)
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; // This array is filled by BFS and to
				// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (bfs(rGraph, s, t, parent)) {
		// Find minimum residual capacity of the edges along
		// the path filled by BFS. Or we can say find the
		// maximum flow through the path found.
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

