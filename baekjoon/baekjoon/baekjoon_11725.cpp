#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visit[100001];
vector<int> arr[100001];
int answer[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;	
	for (int i = 0; i < N-1; i++)
	{
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	queue<int> q; q.push(1); visit[1] = true;
	while (!q.empty())
	{
		int parent = q.front();
		q.pop();
		for (int i = 0; i < arr[parent].size(); i++)
		{
			int child = arr[parent][i];
			if (!visit[child])
			{
				visit[child] = true;
				answer[child] = parent;
				q.push(child);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << answer[i] << "\n";
	return 0;
}