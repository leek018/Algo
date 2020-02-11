#include <iostream>
#include <cstring>
#define ROW 0
#define COL 1
using namespace std;
int sum[2][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		int N, M; cin >> N >> M;
		memset(sum, 0, sizeof(int) * 2 * 1001);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int input;  cin >> input;
				sum[ROW][i] += input;
				sum[COL][j] += input;
			}
		}
		for (int i = 0; i < M; i++)
		{
			int r1, c1, r2, c2, v; cin >> r1 >> c1 >> r2 >> c2 >> v;
			for (int c = c1; c <= c2; c++)
				sum[COL][c] += (r2 - r1 + 1) * v;
			for (int r = r1; r <= r2; r++)
				sum[ROW][r] += (c2 - c1 + 1) * v;
		}
		for (int i = 1; i <= N; i++)
			cout << sum[ROW][i] << " ";
		cout << "\n";
		for (int i = 1; i <= N; i++)
			cout << sum[COL][i] << " ";
		cout << "\n";
	}
	return 0;
}