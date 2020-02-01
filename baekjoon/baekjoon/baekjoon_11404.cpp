#include <iostream>
#define INF 100000000
using namespace std;

int edge[101][101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		fill_n(edge[i], N + 1, INF);
		edge[i][i] = 0;
	}
	for (int i = 0; i < M; i++)
	{		
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from][to] = edge[from][to] > cost ? cost : edge[from][to];		
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if ( edge[i][k] != INF && edge[k][j] != INF)
					edge[i][j] = edge[i][j] > edge[i][k] + edge[k][j] ? edge[i][k] + edge[k][j] : edge[i][j];
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int val = edge[i][j];
			if (val == INF)
				val = 0;			
			cout << val << " ";						
		}
		cout << "\n";
	}
	return 0;
}