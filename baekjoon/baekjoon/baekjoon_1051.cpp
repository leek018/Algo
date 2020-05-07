#include <iostream>
#include <string>
using namespace std;
int N, M;
string map[50];
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };
int findRectangle(int r, int c, char value)
{
	int functionMax = 1;
	int Length = 2;
	while (true)
	{
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			int next_x = c + (Length-1)*dx[i];
			int next_y = r + (Length-1)*dy[i];
			if (next_x >= M || next_y >= N)
				return functionMax;
			if (map[next_y][next_x] == value)
				count++;
			else
				break;
		}
		if (count == 3)
		{
			if (functionMax < Length * Length)
				functionMax = Length * Length;
		}
		Length++;
	}	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)		
			cin >> map[i];
	int answer = 1;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int ret = findRectangle(i, j, map[i][j]);
			if (answer < ret)
				answer = ret;
		}
	}
	cout << answer;
	return 0;
}