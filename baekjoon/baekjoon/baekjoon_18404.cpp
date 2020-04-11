#include <iostream>
#include <queue>
using namespace std;
int map[501][501];
bool visit[501][501];
int N, M;
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { -1,-2,-2,-1,1,2,2,1 };
int record[1001];
void bfs(int start_x,int start_y)
{
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });
	visit[start_y][start_x] = true;
	int target = M;
	int count = 0;
	while (target != 0)
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = q.front();
			q.pop();
			int mapVal = map[ret.second][ret.first];
			if (mapVal != 0)
			{
				record[mapVal] = count;
				target--;
			}
			for (int j = 0; j < 8; j++)
			{
				int nx = ret.first + dx[j]; int ny = ret.second + dy[j];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
		count++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int start_x, start_y;
	cin >> N >> M >> start_y >> start_x;
	for (int i = 1; i <= M; i++)
	{
		int y, x; cin >> y >> x;
		map[y][x] = i;
	}
	bfs(start_x, start_y);
	for (int i = 1; i <= M; i++)
		cout << record[i] << " ";
	return 0;
}