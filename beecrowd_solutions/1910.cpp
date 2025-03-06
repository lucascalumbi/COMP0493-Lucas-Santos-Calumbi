#include <bits/stdc++.h>

using namespace std;

const int limit = 100001;

int plus1(int a){return a+1;}
int minus1(int a){return a-1;}
int times2(int a){return a*2;}
int times3(int a){return a*3;}
int divide2(int a){return a/2;}


int bfs(vector<int>& dist,int O,int D)
{	
	vector<function<int(int)>> ops = {plus1,minus1,times2,times3,divide2};
	dist[O] = 0;
	queue<int> line;
	line.push(O);

	while(!line.empty())
	{
		int c = line.front();
		line.pop();
		
		if(c == D)
			return dist[c];

		for(int i = 0; i < 4; i++)
		{	
			int r = ops[i](c);
			if(r > 0 && r <= limit-1 && dist[r] == -1)
			{
				dist[r] = dist[c]+1;
				line.push(r);
			}
		}
		if(c % 2 == 0)
		{
			int r = ops[4](c);
			if(r > 0 && r <= limit-1 && dist[r] == -1)
			{
				dist[r] = dist[c]+1;
				line.push(r);
			}
		}
	}
	
	return -1;
}


int main(void)
{
	int O, D, K;
	while(cin >> O >> D >> K)
	{
		if(!(O+D+K))
			break;
		
		vector<int> C(limit,-1);
		for(int i = 0; i < K; i++)
		{
			int k;
			cin >> k;
			C[k]--;
		}

		int Q = bfs(C,O,D);

		cout << Q << endl;
	}

	return EXIT_SUCCESS;
}

