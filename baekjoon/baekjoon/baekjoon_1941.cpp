#include <iostream>
#include <string>
#include <queue>
using namespace std;
string map[5];
int answer = 0;
bool visit[5][5];
bool mark[5][5];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int sel[7];
bool bfs(int target)
{	
	for (int i = 0; i < 5; i++) {
		fill_n(visit[i], 5, false);
		fill_n(mark[i], 5, false);
	}
	for (int i = 0; i < 7; i++)
	{
		int ele = sel[i];
		mark[ele / 5][ele % 5] = true;
	}

	queue<pair<int, int>> q;
	q.push({ target % 5,target / 5 });
	visit[target / 5][target % 5] = true;
	int count = 1;

	while(!q.empty())
	{
		pair<int, int> ret = q.front();		
		q.pop();				
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visit[ny][nx] && mark[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ nx,ny });
				count++;
			}
		}
	}
	if (count == 7)
		return true;
	return false;
}
void solve(int idx, int r, int Scnt)
{
	if (r == 4)
	{
		if (Scnt < 1)
			return;
	}
	if (r == 7)
	{		
		if (Scnt >= 4) {
			bool ret = bfs(sel[0]);
			if (ret) 				
				answer++;							
		}		
		return;
	}
	for (int i = idx; i < 25; i++)
	{
		sel[r] = i;
		int findCnt = 0;
		if (map[i / 5][i % 5] == 'S')
			findCnt++;
		solve(i + 1, r + 1, Scnt + findCnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> map[i];		
	}
		
	solve(0, 0, 0);
	
	cout << answer;
}