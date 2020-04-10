#include <iostream>
#include <algorithm>
using namespace std;
int R, C;
pair<int,int> map[100][10000];
bool visit[100];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

bool compare(int a, int b)
{
	for (int i = 0; i < C; i++)
	{
		if (map[a][i].first != map[b][i].first)
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j].first = j;
			cin >> map[i][j].second;
		}
			
	}
	int answer = 0;
	for (int i = 0; i < R; i++)
		sort(map[i], map[i] + C, cmp);
	for (int i = 0; i < R; i++)
	{
		if (visit[i])
			continue;
		int temp_answer = 1;
		for (int j = i+1; j < R; j++)
		{
			bool ret = compare(i, j);
			if (ret)
			{
				visit[j] = true;
				temp_answer++;
			}
		}
		answer += temp_answer * (temp_answer - 1) / 2;
	}
	cout << answer;
	return 0;
}