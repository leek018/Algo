#include <iostream>
#include <string>
using namespace std;

int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
string answer_string[4] = { "UP","RIGHT","DOWN","LEFT" };
int flow[] = { 2,3,0,1 };
string map[100];
int isRight(int start_x, int start_y, int dir)
{
	int count = 1;
	while (true)
	{
		start_x += dx[dir];
		start_y += dy[dir];		
		if (start_x == M|| start_y == N || start_x == -1 || start_y == -1)
			return count -1 ;
		if (map[start_y][start_x] == '.')
		{
			int nx = start_x + dx[dir];
			int ny = start_y + dy[dir];
			if (nx == M || ny == N || nx == -1 || ny == -1)
				return count-1;
			else {
				if (map[ny][nx] == '#')
					return -1;
				else
					return count - 1;
			}				
		}		
		count++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)	
		cin >> map[i];	
	int start_x = 0;
	int start_y = 0;
	bool find = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '#')
			{
				start_y = i;
				start_x = j;
				find = true;
				break;
			}
		}
		if (find)
			break;
	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		int direction = flow[i];
		int ret = isRight(start_x, start_y, direction);
		if (ret == -1) {
			answer = i;
			break;
		}
		start_x += ret * dx[direction];
		start_y += ret * dy[direction];
	}
	cout << answer_string[answer];
	return 0;
}