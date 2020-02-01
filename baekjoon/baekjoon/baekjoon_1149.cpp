#include <iostream>

using namespace std;
int N;
int map[1000][3];
int memo[1000][3];
int solve(int idx, int before_color)
{
	if (idx == N)
		return 0;
	int ret = memo[idx][before_color];
	if (ret > 0)
		return ret;
	int min = 1000001;
	for (int i = 0; i < 3; i++)
	{
		if (before_color != i)
		{
			int temp = solve(idx + 1, i) + map[idx][i];
			min = min > temp ? temp : min;
		}
	}
	return memo[idx][before_color] = min;
}
int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];
	}
	int ret = solve(0, -1);
	cout << ret << "\n";
	return 0;
}