#include <iostream>
#include <string>
using namespace std;
string map[10];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N, M;
bool check(int start_x, int start_y)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == 'X')
			count++;
	}
	return count == 3;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '.')
			{
				if (check(j, i))
				{
					answer = 1;
					break;
				}
			}
		}
		if (answer == 1)
			break;
	}
	cout << answer;
	return 0;
}