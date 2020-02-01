#include <iostream>
#include <queue>
using namespace std;


int N;
int people[11];
bool edge[11][11];

int answer = 999999;

bool visit[11];
bool visit_que[11];
int bfs(int target)
{
	queue<int> q;
	q.push(target);
	visit_que[target] = true;
	int count = 1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (edge[here][i] && visit[i] == visit[here] && !visit_que[i])
			{
				q.push(i);
				count++;
				visit_que[i] = true;
			}
		}
	}
	return count;
}
void solve(int r,const int& limit)
{
	if (r == limit)
	{
		fill_n(visit_que, 11, false);
		int A_start = 0;
		int B_start = 0;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i])
			{
				A_start = i;
				break;
			}
		}
		int ret_a = bfs(A_start);
		if (ret_a != r)
			return;
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				B_start = i;
				break;
			}
		}
		int ret_b = bfs(B_start);
		if (ret_b != N - r)
			return;
		int sum_a = 0;
		int sum_b = 0;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i])
				sum_a += people[i];
			else
				sum_b += people[i];
		}
		int temp_answer = sum_a - sum_b;
		if (temp_answer < 0)
			temp_answer *= -1;

		answer = answer > temp_answer ? temp_answer : answer;
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			solve(r + 1, limit);
			visit[i] = false;
		}
	}
}
int main()
{
	freopen("sample_17471.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> people[i];
	for (int i = 1; i <= N; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int temp;
			cin >> temp;
			edge[i][temp] = true;
			edge[temp][i] = true;
		}
	}	
	for (int limit = 1; limit <= N / 2; limit++)
	{
		fill_n(visit, 11, false);
		solve(0, limit);
	}
	if (answer == 999999)
		answer = -1;
	cout << answer << "\n";
	return 0;
}