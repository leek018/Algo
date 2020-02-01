#include <iostream>
#include <queue>
using namespace std;
char map[1000][1000];
int visit[1000][1000];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	freopen("sample_4179.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	queue<pair<int, int>> j_q;
	queue<pair<int, int>> f_q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				j_q.push({ j,i });
				visit[i][j] = -1;
			}
			else if (map[i][j] == 'F')
			{
				f_q.push({ j,i });
				visit[i][j] = 1;
			}
		}
	}
	int count = 0;
	bool possible = false;
	while (true)
	{
		if (j_q.empty())
			break;
		int fire_len = f_q.size();
		for (int i = 0; i < fire_len; i++)
		{
			pair<int, int> ret = f_q.front();
			f_q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] != '#' && visit[ny][nx] != 1)
				{
					visit[ny][nx] = 1;
					f_q.push({ nx,ny });
					map[ny][nx] = 'F';
				}
			}			
		}
		int j_len = j_q.size();
		for (int i = 0; i < j_len; i++)
		{
			pair<int, int> ret = j_q.front();
			if (ret.first == 0 || ret.first == M - 1 || ret.second == 0 || ret.second == N - 1)
			{
				possible = true;
				break;
			}
			j_q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == '.' && visit[ny][nx] == 0)
				{
					visit[ny][nx] = -1;
					j_q.push({ nx,ny });
					map[ny][nx] = 'J';
				}
			}
		}
		count++;
		if (possible)
			break;
	}	
	if (possible)
		cout << count << "\n";
	else
		cout << "IMPOSSIBLE" << "\n";
	return 0;
}