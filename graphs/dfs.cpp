#include<bits/stdc++.h>

using namespace std;

void dfs_rec(vector<vector<int>>& G, vector<bool>& visited, int v)
{
	visited[v] = true;
	for(int i : G[v])
        if(!visited[i])
            dfs_rec(G,visited,i);
} 

void dfs(vector<vector<int>>& G, int v){
    vector<bool> visited(G.size(), false);
    dfs_rec(G, visited, v);
}

int main()
{
    //something like

    int V,E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for(int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a); // se for bi-direcionado
    }
    
    int v = 10;
    dfs(G,v);

    return EXIT_SUCCESS;
}