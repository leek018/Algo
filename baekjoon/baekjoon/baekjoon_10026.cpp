#include <iostream>
#include <string>
#include <queue>
using namespace std;

string map[100];
bool visit[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N;
void bfs(int start_x, int start_y, char target_a,char target_b)
{
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });
	visit[start_y][start_x] = true;
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx] && (map[ny][nx] == target_a || map[ny][nx] == target_b))
			{
				visit[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	int non = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				non++;
				bfs(j, i, map[i][j],map[i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
		fill_n(visit[i], N, false);
	int on = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				on++;
				if (map[i][j] == 'R' || map[i][j] == 'G')
					bfs(j, i, 'R', 'G');
				else
					bfs(j, i, 'B', 'B');
			}
		}
	}
	cout << non << " " << on << "\n";
	return 0;
}