#include <iostream>
#include <queue>
using namespace std;
int A, B;
int N, M;
bool map[500][500];
bool visit[500][500];
queue<pair<int, int>> q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int start_x, start_y, goal_x, goal_y;
bool isMovePossible(int dir,const pair<int,int> &start)
{
	int nx = start.first;
	int ny = start.second;	
	if (dir == 0 || dir == 2)
	{
		if (dir == 0)
			nx -= 1;
		else if (dir == 2)
			nx += B;
		if (nx < 0 || nx >= M)
			return false;
		for (int r = start.second; r <= start.second + A - 1; r++)
		{
			if (map[r][nx])
				return false;
		}
	}		
	else {
		if (dir == 1)
			ny -= 1;
		else if (dir == 3)
			ny += A;
		if (ny < 0 || ny >= N)
			return false;
		for (int c = start.first; c <= start.first+B-1; c++)
		{
			if (map[ny][c])
				return false;
		}
	}
	return true;
}
int bfs(int start_x,int start_y)
{
	q.push({ start_x,start_y });
	visit[start_y][start_x] = true;
	int count = 0;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = q.front();
			q.pop();
			if (ret.first == goal_x && ret.second == goal_y)
				return count;
			for (int j = 0; j < 4; j++)
			{
				if (isMovePossible(j, ret))
				{
					pair<int, int> nPos = { ret.first + dx[j],ret.second + dy[j] };
					if (!visit[nPos.second][nPos.first])
					{
						q.push(nPos);
						visit[nPos.second][nPos.first] = true;
					}
				}
			}
		}
		count++;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c; cin >> r >> c;
		map[r-1][c-1] = true;		
	}	
	cin >> start_y >> start_x >> goal_y >> goal_x;
	start_x -= 1; start_y -= 1; goal_x -= 1; goal_y -= 1;
	int ret = bfs(start_x, start_y);
	cout << ret;	
	return 0;
}