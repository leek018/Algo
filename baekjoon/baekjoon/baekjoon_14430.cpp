#include <iostream>

using namespace std;
int N, M;
int map[300][300];
int memo[300][300];

//오른쪽 , 아래쪽
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int solve(int start_x, int start_y)
{
	if (start_x >= M || start_y >= N)
		return 0;
	if (start_x == M - 1 && start_y == N - 1)
	{
		if (map[N - 1][M - 1] == 1)
			return 1;
		return 0;
	}
	int ret = memo[start_y][start_x];
	if (ret >= 0)
		return ret;
	int sum = 0;
	if (map[start_y][start_x] == 1)
		sum++;
	int maxVal = 0;
	for (int i = 0; i < 2; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		int res = solve(nx, ny) + sum;
		if (res > maxVal)
			maxVal = res;
	}
	return memo[start_y][start_x] = maxVal;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N >> M;
	for (int i = 0; i < 300; i++)
		fill_n(memo[i], 300, -1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int answer = solve(0, 0);
	cout << answer;
}