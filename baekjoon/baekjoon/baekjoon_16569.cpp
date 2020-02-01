#include <iostream>
#include <queue>
using namespace std;

int height[101][101];
int visit[101][101];
bool escape[101][101];
struct Vol {
	int x,y, t;
	Vol(int x_a, int y_a, int time)
	{
		x = x_a;
		y = y_a;
		t = time;
	}
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C,V,start_y,start_x;
	cin >> R >> C >> V >> start_y >> start_x;
	
	for (int i = 1; i <= R; i++)
	{
		fill_n(visit[i], 101, -1);
		for (int j = 1; j <= C; j++)
		{
			cin >> height[i][j];
		}
	}
	queue<Vol> q;
	for (int i = 0; i < V; i++)
	{
		int r, c, t;
		cin >> r >> c >> t;
		visit[r][c] = t;		
		escape[r][c] = true;
		q.push(Vol(c, r, t));
	}
	while (!q.empty())
	{
		Vol ret = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.x + dx[i];
			int ny = ret.y + dy[i];
			if (nx > 0 && nx <= C && ny > 0 && ny <= R)
			{
				int visitVal = visit[ny][nx];
				if (visitVal < 0)
				{
					visit[ny][nx] = ret.t + 1;
					q.push(Vol(nx, ny, ret.t + 1));
				}
				else {
					if (visitVal > ret.t + 1)
					{
						visit[ny][nx] = ret.t + 1;
						q.push(Vol(nx, ny, ret.t + 1));
					}
				}
			}
		}
	}

	int maxHeight = 0;
	int time = 0;
	q.push(Vol(start_x, start_y, 0));
	escape[start_y][start_x] = true;
	while (!q.empty())
	{
		Vol ret = q.front();		
		q.pop();
		int heightVal = height[ret.y][ret.x];
		if (heightVal > maxHeight)
		{
			maxHeight = heightVal;
			time = ret.t;
		}
		else if (heightVal == maxHeight)
		{
			if (time > ret.t)
				time = ret.t;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.x + dx[i];
			int ny = ret.y + dy[i];
			if (nx > 0 && nx <= C && ny >0 && ny <= R && !escape[ny][nx])
			{
				int limitTime = visit[ny][nx];
				if (limitTime > ret.t + 1)
				{
					escape[ny][nx] = true;
					q.push(Vol(nx, ny, ret.t + 1));
				}
			}
		}
	}
	cout << maxHeight << " " << time;
}