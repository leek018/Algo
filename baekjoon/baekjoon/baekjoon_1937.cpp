#include <iostream>

using namespace std;
int memo[4][500][500];
int map[500][500];
int N;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int solve(int start_x, int start_y, int current, int direc)
{	
	int ret = memo[direc][start_y][start_x];
	if (ret >= 0)
		return ret;
	int localMax = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] >current)
		{
			int ret = solve(nx, ny, map[ny][nx], i) + 1;
			if (ret > localMax)
				localMax = ret;
		}
	}
	return memo[direc][start_y][start_x] = localMax;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < 4; j++)
			fill_n(memo[j][i], 500, -1);
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ret = solve(j, i, map[i][j], k)+1;
				if (ret > answer)
					answer = ret;
			}
		}
	}
	cout << answer;
}