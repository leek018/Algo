#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Info {
	int J, O, I;	
	Info operator +(const Info& target)
	{
		return { J + target.J,O + target.O,I + target.I };
	}
	Info operator -(const Info& target)
	{
		return { J - target.J,O - target.O,I - target.I };
	}
};
char map[1001][1001];
Info dp[1001][1001];
int N, M, K;
void makeDpset()
{	
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			char mapVal = map[r][c];
			dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1];
			if (mapVal == 'J')
				dp[r][c].J++;
			else if (mapVal == 'O')
				dp[r][c].O++;
			else
				dp[r][c].I++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N >> M >> K;	
	for (int i = 1; i <= N; i++)
	{
		for(int j = 1; j <=M; j++)
			cin >> map[i][j];
	}		
	makeDpset();
	for (int i = 0; i < K; i++)
	{
		int startR, startC, endR, endC; cin >> startR >> startC >> endR >> endC;
		Info Answer = dp[endR][endC] - dp[endR][startC - 1] - dp[startR-1][endC] + dp[startR - 1][startC - 1];
		cout << Answer.J << " " << Answer.O << " " << Answer.I << "\n";
	}	
	return 0;
}