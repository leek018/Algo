#include <iostream>
#include <queue>
#define abs(X) ((X) < 0 ? (-(X)) : (X))
#define LIMIT 1000
using namespace std;
pair<int, int> Store[100];
bool visit[100];
int N;
int start_x, start_y, goal_x, goal_y;
bool bfs()
{
	if (abs(start_x - goal_x) + abs(start_y - goal_y) <= LIMIT)
		return true;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		pair<int, int> ret = Store[i];
		int x_diff = ret.first - start_x;
		int y_diff = ret.second - start_y;
		if (abs(x_diff) + abs(y_diff) <= LIMIT) {
			q.push(ret);
			visit[i] = true;
		}
			
	}
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		if (abs(ret.first - goal_x) + abs(ret.second - goal_y) <= LIMIT)
			return true;
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				if (abs(ret.first - Store[i].first) + abs(ret.second - Store[i].second) <= LIMIT)
				{
					q.push(Store[i]);
					visit[i] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{		
		fill_n(visit, 100, false);
		cin >> N;
		cin >> start_x >> start_y;
		for (int i = 0; i < N; i++)
		{
			cin >> Store[i].first >> Store[i].second;
		}
		cin >> goal_x >> goal_y;
		bool ret = bfs();
		if (ret)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}