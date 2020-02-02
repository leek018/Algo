#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool visit[2][10][4][500][500];
int map[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
queue<pair<int, int>> q;
int N, M;
pair<int, int> findPos(int start_x, int start_y, int dir)
{
	while (true)
	{
		start_x += dx[dir];
		start_y += dy[dir];
		if (start_x < 0 || start_x >= N || start_y < 0 || start_y >= N)
			return { -1,-1 };
		if (map[start_y][start_x] == 1)
			continue;
		return { start_x,start_y };
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	q.push({ 0,0 });	
	int movecnt = 0;
	bool possible = false;
	int day = 0;
	int sky = 0;
	while (!q.empty())
	{
		int qlen = q.size();		
		for (int i = 0; i < qlen; i++)
		{
			pair<int, int> ret = q.front();
			q.pop();			
			if (ret.first == N - 1 && ret.second == N - 1)
			{
				possible = true;
				day = movecnt / (2 * M)+1;				
				sky = (movecnt / M) % 2;
				break;
			}					
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{					
					int current_sky = (movecnt / M) % 2;
					int next_sky = ((movecnt+1) / M) % 2;
					int nextmoverem = (movecnt+1) % M;
					if (map[ny][nx] == 0)
					{						
						if (!visit[next_sky][nextmoverem][j][ny][nx])
						{
							visit[next_sky][nextmoverem][j][ny][nx] = true;
							q.push({ nx,ny });
						}
					}
					else {
						if (current_sky == 1)
						{
							pair<int, int> findPosRes = findPos(ret.first, ret.second, j);
							if (findPosRes.first != -1)
							{
								if (!visit[next_sky][nextmoverem][j][findPosRes.second][findPosRes.first])
								{
									visit[next_sky][nextmoverem][j][findPosRes.second][findPosRes.first] = true;
									q.push(findPosRes);
								}
							}
						}
					}					
				}
			}
		}
		if (possible)
			break;
		movecnt++;
	}
	string answer_sky = "sun";
	if (possible)
	{
		if (sky == 1)
			answer_sky = "moon";
		cout << day << " " << answer_sky;
	}
	else
		cout << -1;
	return 0;
}