#include <iostream>	
#include <string>
using namespace std;
int N, M;
char flow[] = { 'B','W' };
string map[50];

int cal(int start,int start_x,int start_y)
{
	int sum = 0;
	for (int i = start_y; i < start_y + 8; i++)
	{
		for (int j = start_x; j < start_x + 8; j++)
		{
			if (map[i][j] != flow[start])
				sum++;
			start++;
			start %= 2;
		}
		start++;
		start %= 2;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	int answer = 9999999;
	for (int i = 0; i <= N-8; i++)
	{
		for (int j = 0; j <= M-8; j++)
		{
			int retA = cal(0, j, i);
			int retB = cal(1, j, i);
			answer = answer > retA ? retA : answer;
			answer = answer > retB ? retB : answer;						
		}
	}
	cout << answer;
}