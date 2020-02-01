#include <iostream>

using namespace std;
int N, M, H;
bool map[11][31];

bool play(int w)
{
	int start_x = w;
	int start_y = 1;
	int right = w;
	while (start_y <= H)
	{
		int left = start_x - 1;
		
		if (left >= 1 )
		{
			if (map[start_y][left])
				start_x = left;											
		}
		if (map[start_y][start_x])
			start_x++;					
		start_y++;
	}
	if (start_x == w)
		return true;
	else
		return false;
}

int answer = 4;
void solve(int w, int count)
{
	if (count == 4)
		return ;
	if (w == N + 1)
	{
		answer = answer > count ? count : answer;
		return ;
	}
	if (play(w))	
		solve(w + 1, count);	
	else {
		int left = w - 1;
		int right = w + 1;
		if (left == 0)
			left = 1;
		if (right == N + 1)
			right = N;
		for (int i = 1; i <= H; i++)
		{
			bool possible = true;
			for (int j = left; j <= right; j++)
			{
				if (map[i][j]) {
					possible = false;
					break;
				}
			}
			if (possible)
			{
				map[i][w] = true;
				if (play(w))
					solve(w + 1, count + 1);
				map[i][w] = false;													
			}
		}
		solve(w + 1, count);
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = true;	
	}
	solve(1, 0);
	if (answer == 4)
		answer = -1;
	cout << answer << "\n";
	return 0;
}