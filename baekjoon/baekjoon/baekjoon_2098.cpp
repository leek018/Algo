#include <iostream>

using namespace std;
int map[16][16];
int memo[16][1 << 16];
bool visit[16];
int N;
int solve(int target,int log,int sel)
{
	if (sel == N)
	{
		int mapVal = map[target][0];
		if (mapVal != 0)
			return mapVal;
		return -2;
	}
	int ret = memo[target][log];
	if (ret != -1)
		return ret;
	int minVal = 1000000000;
	for (int i = 0; i < N; i++)
	{
		if (!visit[i] && map[target][i] !=0)
		{
			visit[i] = true;
			int localMin = solve(i, log | (1 << i), sel + 1);
			if (localMin != -2)
				minVal = minVal > localMin+map[target][i] ? localMin + map[target][i] : minVal;
			visit[i] = false;
		}
	}
	if (minVal == 1000000000)
		return memo[target][log] = -2;
	return memo[target][log] = minVal;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{	
		fill_n(memo[i], 1 << 16, -1);
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	
	visit[0] = true;
	int answer = solve(0, 1, 1);
	cout << answer;
}