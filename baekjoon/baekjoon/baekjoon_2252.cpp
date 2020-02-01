#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int inDegree[32001];
vector<int> edge[32001];
bool visit[32001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		inDegree[to]++;
	}
	queue<int> q;
	vector<int> answer;
	
	for (int i = 1; i <= N; i++)
	{
		if (!inDegree[i])
		{			
			q.push(i);
			visit[i] = true;
		}
	}
	
	while (!q.empty())
	{
		int ele = q.front();
		answer.push_back(ele);
		q.pop();
		for (int i = 0; i < edge[ele].size(); i++)		
			inDegree[edge[ele][i]]--;
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i] && !inDegree[i])
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << "\n";
	return 0;
}