#include <iostream>
#include <vector>
using namespace std;
char map[6][6];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N;
vector< pair<int, int> > teachers;
vector< pair<int, int> > vacant;
bool gamsi(int teaccherIdx)
{
	pair<int, int>& teacherPos = teachers[teaccherIdx];
	for (int i = 0; i < 4; i++)
	{
		int x = teacherPos.first; int y = teacherPos.second;
		while (true)
		{
			x += dx[i];
			y += dy[i];
			if (x < 0 || x >= N || y < 0 || y >= N || map[y][x] == 'O' || map[y][x] == 'T')
				break;
			if (map[y][x] == 'S')
				return false;
		}
	}
	return true;
}
bool simulation()
{
	for (int i = 0; i < teachers.size(); i++)
	{
		if (!gamsi(i))
			return false;
	}
	return true;
}
bool solve(int idx, int cnt)
{
	if (cnt == 3)
	{
		if (simulation())
			return true;
		return false;
	}
	for (int i = idx; i < vacant.size(); i++)
	{
		pair<int, int> vacantPos = vacant[i];
		map[vacantPos.second][vacantPos.first] = 'O';
		if (solve(i + 1, cnt + 1))
			return true;
		map[vacantPos.second][vacantPos.first] = 'X';
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')
				teachers.push_back({ j,i });
			else if (map[i][j] == 'X')
				vacant.push_back({ j,i });
		}			
	}
	if (solve(0, 0))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}