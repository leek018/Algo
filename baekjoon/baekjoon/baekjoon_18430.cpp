#include <iostream>
using namespace std;

int map[5][5];
bool isVisit[5][5];
int N, M;
// i,j
int direction[4][4] = {
	{0,1,1,0},
	{0,-1,-1,0},
	{0,-1,1,0},
	{-1,0,0,1}
};
bool isbuPossible(int start_x, int start_y,int dir)
{
	for (int i = 0; i < 4; i+=2)
	{
		int ny = start_y + direction[dir][i];
		int nx = start_x + direction[dir][i + 1];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N || isVisit[ny][nx])
			return false;			
	}
	return true;
}
int makeChange(int start_x, int start_y, int dir,bool value)
{
	int sum = map[start_y][start_x] * 2;
	isVisit[start_y][start_x] = value;
	for (int i = 0; i < 4; i += 2)
	{
		int ny = start_y + direction[dir][i];
		int nx = start_x + direction[dir][i + 1];
		isVisit[ny][nx] = value;
		sum += map[ny][nx];
	}
	return sum;
}
int bestAnswer = 0;
void simulation(int index, int sum)
{
	if (index == N * M)
	{
		if (sum > bestAnswer)
			bestAnswer = sum;
		return;
	}
	int currentY = index / M;
	int currentX = index % M;
	if (!isVisit[currentY][currentX])
	{
		for (int i = 0; i < 4; i++)
		{			
			if (isbuPossible(currentX, currentY, i))
			{
				int tempSum = makeChange(currentX, currentY, i, true);
				simulation(index + 1, sum + tempSum);
				makeChange(currentX, currentY, i, false);
			}			
		}
		simulation(index + 1, sum);
	}
	else
		simulation(index + 1, sum);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	simulation(0, 0);
	cout << bestAnswer;
	return 0;
}