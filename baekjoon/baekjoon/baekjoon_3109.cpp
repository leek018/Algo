#include <iostream>
#include <string>
using namespace std;

string map[10000];
bool visit[10000][500];
int dy[] = { -1,0,1 };
int R, C;
int answer = 0;
bool solve(int r, int c)
{
	visit[r][c] = true;
	if (c == C-1) {
		answer++;
		return true;
	}		
	for (int i = 0; i < 3; i++)
	{
		int nx = c + 1;
		int ny = r + dy[i];
		if (ny >= 0 && ny < R && !visit[ny][nx] && map[ny][nx] == '.')
		{
			if (solve(ny, c + 1))
				return true;
		}			
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> R >> C;
	for (int i = 0; i < R; i++)	
		cin >> map[i];
	
	for (int i = 0; i < R; i++)	
		solve(i, 0);
	cout << answer;	
}