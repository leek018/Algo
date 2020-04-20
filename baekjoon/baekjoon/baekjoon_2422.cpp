#include <iostream>
using namespace std;

bool map[201][201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v; cin >> u >> v;
		map[u][v] = true;
		map[v][u] = true;
	}
	int answer = 0;
	for (int i = 1; i <= N-2; i++)
	{
		for (int j = i + 1; j <= N - 1; j++)
		{
			if (map[i][j])
				continue;
			for (int k = j + 1; k <= N; k++)
			{
				if (map[i][k] || map[j][k])
					continue;
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}