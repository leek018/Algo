#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dist[300001];
int min_dist[300001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill_n(min_dist, 300001, 300001);
	int N, M, K, X; cin >> N >> M >> K >> X;
	min_dist[X] = 0;
	for (int i = 0; i < M; i++)
	{
		int from, to; cin >> from >> to;
		dist[from].push_back(to);
	}
	queue<pair<int, int>> q;
	q.push({ 0,X });
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		for (int i = 0; i < dist[ret.second].size(); i++)
		{
			int connected = dist[ret.second][i];
			if (ret.first + 1 < min_dist[connected])
			{
				min_dist[connected] = ret.first + 1;
				q.push({ ret.first + 1,connected });
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (min_dist[i] == K) {
			cout << i << "\n";
			count++;
		}			
	}
	if (count == 0)
		cout << -1;
	return 0;
}