#include <bits/stdc++.h>

using namespace std;

template <typename T>
pair<T,T> operator+(const pair<T,T>& p1, const pair<T,T>& p2)
{
	return {p1.first+p2.first, p1.second+p2.second};
}

int bfs(vector<vector<char>>& G, vector<pair<int,int>>& P)
{
	vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
	vector<pair<int,int>>
	queue<vector<pair<int,int>>> fila;
	fila.push(P);
	while(!fila.empty())
	{
		auto p = fila.front();
		fila.pop();
		
		vector<pair<int,int>> pm;

		for(auto m : moves)
		{	
			bool is_possible = true;
			for(auto s : p)
			{
				auto k = p+m;
				auto x = k.first;
				auto y = k.second;

				if(x < 0 || y < 0 || x > G.size()-1 || y > G.size()-1)




int main()
{
	int T;
	cin >> T;
	
	int count = 1;
	while(T--)
	{
		int N;
		cin >> N;
		vector<vector<char>> G(N, vector<char>(N));
		vector<pair<int,int>> P(3);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				char c;
				cin >> c;
				if(c == 'A')
					P[0] = {i,j};
				if(c == 'B')
					P[1] = {i,j};
				if(c == 'C')
					P[2] = {i,j};
				G[i][j] = c;
			}
		
		int t = bfs(G,P);
		
		cout << "Case " << count++ << ": " << (t>0 ? t : "trapped") << endl;

	}


	return EXIT_SUCCESS;
}
