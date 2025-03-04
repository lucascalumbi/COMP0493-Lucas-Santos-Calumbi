//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int f, int s, int g, int u, int d)
{
	vector<int> dist(f+1,-1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty())
	{
		int aux = q.front();
		q.pop();
		
		int auxu = aux+u;
		if(auxu <= f && dist[auxu] == -1)
		{
			dist[auxu] = dist[aux]+1;
			q.push(auxu);
		}
		int auxd = aux-d;
		if(auxd >= 1 && dist[auxd] == -1)
		{
			dist[auxd] = dist[aux]+1;
			q.push(auxd);
		}
	}
	return dist[g];
}

int main()
{
	int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;

	int result = bfs(f,s,g,u,d);
	if(result == -1)
		cout << "use the stairs" << endl;
	else
		cout << result << endl;






	return EXIT_SUCCESS;
}
