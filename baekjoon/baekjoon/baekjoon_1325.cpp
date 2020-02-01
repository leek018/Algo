#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[10001];
bool visit[10001];
vector<int> edge[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int to, from;
		cin >> to >> from;
		edge[from].push_back(to);
	}
	queue<int> q;
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		fill_n(visit, N + 1, false);
		q.push(i);
		visit[i] = true;
		int count = 0;
		while (!q.empty())
		{
			int ret = q.front();
			q.pop();
			count++;
			for (int j = 0; j < edge[ret].size(); j++)
			{
				int ele = edge[ret][j];
				if (!visit[ele])
				{
					visit[ele] = true;
					q.push(ele);
				}
			}
		}
		arr[i] = count;
		max = max < count ? count : max;
	}
	for (int i = 1; i <= N; i++)
	{
		if (max == arr[i])
			cout << i << " ";
	}
	return 0;
}