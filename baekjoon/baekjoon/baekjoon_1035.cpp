#include <iostream>
#include <queue>
#define abs(X) ( (X) < 0 ? (-(X)) : (X))
using namespace std;
int puzzle[5];
int puzzleLen = 0;
bool mark[25];
bool visit[25];
int sel[5];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool bfs(int target)
{
	fill_n(mark, 25, false);
	fill_n(visit, 25, false);
	for (int i = 0; i < puzzleLen; i++)
	{
		int ele = sel[i];
		mark[ele] = true;
	}
	queue<int> q;
	q.push(target);
	visit[target] = true;
	int count = 1;
	while (!q.empty())
	{
		int ret = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ret % 5 + dx[i];
			int ny = ret / 5 + dy[i];			
			int idx = ny * 5 + nx;
			if (nx >= 0 && nx < 5 && ny >=0 && ny < 5 &&!visit[idx] && mark[idx])
			{
				visit[idx] = true;
				count++;
				q.push(idx);
			}
		}
	}
	if (count == puzzleLen)
		return true;
	return false;
}
bool selVisit[5];
int flow[5];
int answer = 1000;
void perm(int r)
{
	if (r == puzzleLen)
	{
		int sum = 0;
		for (int i = 0; i < puzzleLen; i++)
		{
			int ele = flow[i];
			int eleidx = puzzle[ele];
			int xdiff = abs(eleidx % 5 - sel[i] % 5);
			int ydiff = abs(eleidx / 5 - sel[i] / 5);
			sum += (xdiff + ydiff);
		}		
		answer = answer > sum ? sum : answer;
		return;
	}
	for (int i = 0; i < puzzleLen; i++)
	{
		if (!selVisit[i])
		{
			selVisit[i] = true;
			flow[r] = i;
			perm(r+1);
			selVisit[i] = false;
		}
	}
}
void solve(int r,int idx)
{
	if (r == puzzleLen)
	{		
		if (!bfs(sel[0]))
			return;
		perm(0);
		return;
	}
	for (int i = idx; i < 25; i++)
	{
		sel[r] = i;
		solve(r + 1,i+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5 * 5; i++)
	{
		char input;
		cin >> input;
		if (input == '*')
			puzzle[puzzleLen++] = i;
	}
	solve(0,0);
	cout << answer;
}