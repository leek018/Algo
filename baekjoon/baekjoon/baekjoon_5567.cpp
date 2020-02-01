#include <iostream>
#include <vector>
using namespace std;

bool visit[501];
vector<int> adj[501];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int answer = 0;
	for (int i = 0; i < adj[1].size(); i++)
	{
		int fri = adj[1][i];
		visit[fri] = true;
		for (int j = 0; j < adj[fri].size(); j++)
		{
			int fri_fri = adj[fri][j];
			if(fri_fri!=1)
				visit[fri_fri] = true;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
			answer++;
	}
	cout << answer << "\n";
	return 0;
}