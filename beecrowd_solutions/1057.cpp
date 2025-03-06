#include <bits/stdc++.h>

using namespace std;

template <typename T>
pair<T,T> operator+(const pair<T,T>& p1, const pair<T,T>& p2)
{
	return {p1.first+p2.first, p1.second+p2.second};
}

string encode(vector<pair<int,int>> P)
{
	return to_string(P[0].first) + "," + to_string(P[0].second) + ";" + to_string(P[1].first) + "," + to_string(P[1].second) + ";" + to_string(P[2].first) + "," + to_string(P[2].second);
}

int bfs(vector<vector<char>>& G, vector<pair<int,int>>& P)
{
	vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

	unordered_map<string,int> dist;
	string p_str = encode(P);
	dist[p_str] = 0;

	queue<vector<pair<int,int>>> fila;
	fila.push(P);

	while(!fila.empty())
	{
		auto vp = fila.front();
		fila.pop();
		string code_vp = encode(vp);
		
		for(auto m : moves)
		{	
			int all_reached = 0;
			bool is_possible = true;
			vector<pair<int,int>> temp;
			for(auto p : vp)
			{
				auto k = p+m;
				auto x_a = p.first;
				auto y_a = p.second;
				auto x = k.first;
				auto y = k.second;

				if(x < 0 || y < 0 || x >= G.size() || y >= G.size())
				{
					is_possible = false;
					break;
				}
				char c = G[x][y];
				char a = G[x_a][y_a];
				if(a == 'X')
				{
					all_reached++;
					temp.push_back(p);
				}
				else if(c == '#')
					temp.push_back(p);
				else if(c == 'X')
				{
					all_reached++;
					temp.push_back(k);
				}
				else if(c == 'A' || c == 'B' || c == 'C')
				{
					is_possible = false;
					break;
				}
				else 
					temp.push_back(k);
			}
			if(is_possible && all_reached == 3)
				return dist[code_vp]+1;
			else if(is_possible)
			{
				string code = encode(temp);
				if(!(dist.find(code) == dist.end()))
					continue;
				dist[code] = dist[code_vp]+1;
				fila.push(temp);
			}
		}
	}
	
	return -1;
}

				
			
			




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
		
		cout << "Case " << count++ << ": ";
		if(t>0) 
			cout << t << endl;
		else 
			cout << "trapped" << endl;

	}


	return EXIT_SUCCESS;
}
