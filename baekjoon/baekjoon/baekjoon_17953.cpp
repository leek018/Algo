#include <iostream>
#define MAX_M 100
#define MAX_N 100000
using namespace std;

int dp[MAX_M][MAX_N];
int info[MAX_M][MAX_N];
void MakeDpTable(const int& r, const int& c,const int &N, const int &M)
{
	//dp[r][c] = Max( i = 0~M, j = c-1, dp[i][j]+ info[r][c], if i == r : info[r][c] <= info[r][c] / 2)
	int infoVal = info[r][c];
	for (int i = 0; i < M; i++)
	{
		int localMaxVal = dp[i][c - 1];		
		if (i == r)
			localMaxVal += infoVal / 2;		
		else {
			localMaxVal += infoVal;
		}
		if (dp[r][c] < localMaxVal)
			dp[r][c] = localMaxVal;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> info[i][j];
	}
	for (int i = 0; i < M; i++)
		dp[i][0] = info[i][0];
	for (int j = 1; j < N; j++)
	{
		for (int i = 0; i < M; i++)
			MakeDpTable(i, j, N, M);
	}
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		if (answer < dp[i][N - 1])
			answer = dp[i][N - 1];
	}
	cout << answer;
}