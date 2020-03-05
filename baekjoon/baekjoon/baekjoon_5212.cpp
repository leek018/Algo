#include <iostream>
using namespace std;
int map[10][10];
bool isDown[100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int Xcnt = 0;
pair<int, int> buffer[100];

int R, C;
bool isWillFallen(int start_x, int start_y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx < 0 || nx >= C || ny < 0 || ny >= R || map[ny][nx] == -1)
			cnt++;
	}
	return cnt >= 3;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		fill_n(map[i], 10, -1);
		for (int j = 0; j < C; j++)
		{
			char input; cin >> input;
			if (input == 'X') {
				map[i][j] = Xcnt;
				buffer[Xcnt++] = { j,i };
			}				
		}
	}
	int minCol = C-1; int maxCol = 0;
	int minRow = R-1; int maxRow = 0;
	for (int i = 0; i < Xcnt; i++)
	{
		pair<int, int>& target = buffer[i];
		if(isWillFallen(target.first, target.second))
			isDown[i] = true;
		else {
			if (minCol > target.first) minCol = target.first;
			if (maxCol < target.first) maxCol = target.first;
			if (minRow > target.second) minRow = target.second;
			if (maxRow < target.second) maxRow = target.second;
		}
	}	
	for (int r = minRow; r <= maxRow; r++)
	{
		for (int c = minCol; c <= maxCol; c++)
		{
			int mapVal = map[r][c];
			if (mapVal != -1)
			{
				if (!isDown[mapVal])
					cout << "X";
				else
					cout << ".";
			}
			else
				cout << ".";
		}
		cout << "\n";
	}
	return 0;
}