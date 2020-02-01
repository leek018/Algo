#include <iostream>	
#include <string>
#include <queue>
using namespace std;

string map[50];
bool visit[50][50][1 << 6];
struct Trip{
	int x, y, key;
	Trip(int x_a, int y_a, int key_a)
	{
		x = x_a;
		y = y_a;
		key = key_a;
	}
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int start_x = 0, start_y = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '0')
			{
				start_x = j;
				start_y = i;
			}
		}
	}
	visit[start_y][start_x][0] = true;
	queue<Trip> q;
	q.push(Trip(start_x, start_y, 0));
	int count = 0;
	int answer = -1;
	while (!q.empty())
	{
		bool possible = false;
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			Trip ret = q.front();
			q.pop();
			if (map[ret.y][ret.x] == '1')
			{
				answer = count;
				possible = true;
				break;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.x + dx[j];
				int ny = ret.y + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] != '#')
				{
					char mapVal = map[ny][nx];
					if (mapVal >= 'a' && mapVal <= 'f')
					{
						int keyNum = mapVal - 'a';
						int myKeyval = ret.key;
						if (!visit[ny][nx][ret.key])
						{
							visit[ny][nx][ret.key] = true;
							if ((myKeyval & (1 << keyNum)) == 0) {
								myKeyval |= (1 << keyNum);
								visit[ny][nx][myKeyval] = true;								
							}
							q.push(Trip(nx, ny, myKeyval));
						}													
					}
					else if (mapVal >= 'A' && mapVal <= 'F')
					{
						int doorNum = mapVal - 'A';
						if (!visit[ny][nx][ret.key])
						{
							if ((ret.key & (1 << doorNum)) != 0)
							{
								visit[ny][nx][ret.key] = true;
								q.push(Trip(nx, ny, ret.key));
							}
						}						
					}
					else {
						if (!visit[ny][nx][ret.key])
						{
							visit[ny][nx][ret.key] = true;
							q.push(Trip(nx, ny, ret.key));
						}
					}
				}
			}
		}
		if (possible)
			break;
		count++;
	}
	cout << answer;
}