#include <iostream>

using namespace std;
//up 0 front 1 dwon 2 back 3
//left 4 right 5
int dice[6] = { 0, };
int copyFlow[5][4] =
{
	{0,},
	{0,5,2,4},
	{0,4,2,5},
	{0,3,2,1},
	{0,1,2,3}	
};

void rotate(int direc)
{
	int copy[4];
	for (int i = 0; i < 4; i++)
	{
		int targetIdx = copyFlow[direc][i];
		copy[i] = dice[targetIdx];
	}
	for (int i = 0; i < 4; i++)
	{
		int targetIdx = copyFlow[direc][(i+1)%4];
		dice[targetIdx] = copy[i];
	}
}

int map[20][20];
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, x, y, k;
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < k; i++)
	{
		int direc;
		cin >> direc;
		int nx = x + dx[direc];
		int ny = y + dy[direc];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
		{
			rotate(direc);
			x = nx;
			y = ny;
			int val = map[y][x];
			if (val == 0)			
				map[y][x] = dice[2];			
			else {
				dice[2] = val;
				map[y][x] = 0;
			}
			cout << dice[0] << "\n";
		}
		
	}
	
}