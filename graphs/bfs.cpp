#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>&G ,int v)
{	
    vector<int> dist(G.size(),-1);
	dist[v] = 0;
	queue<int> q;
	q.push(v);

	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		
        for(int d : G[i])
            if(dist[d] == -1)
            {
                dist[d] = dist[i]+1;
                q.push(d);
            }
	}
}

int sum1(int a){return a+1;}
int times3(int a){return a*3;}
int minus2(int a){return a-2;}
int divide2(int a){return a/2;}

// quando o movimento no grafo é dado por funcoes
void bfs_func(unsigned int limit, int v)
{	
    vector<function<int(int)>> fs = {sum1,times3,minus2,divide2};
    vector<int> dist(limit,-1);
	dist[v] = 0;
	queue<int> q;
	q.push(v);

	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		
        for(auto f : fs)
        {
            int r = f(i);
            if(r >= 0 && r < limit && dist[r] == -1)
            {
                dist[r] = dist[i]+1;
                q.push(r);
            }
        }
	}
}