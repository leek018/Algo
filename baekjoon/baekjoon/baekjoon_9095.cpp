#include <iostream>
using namespace std;
int memo[12];

int solve(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	int val = memo[N];
	if (val >= 0)
		return val;
	int sum = 0;
	sum += solve(N - 1);
	sum += solve(N - 2);
	sum += solve(N - 3);
	return memo[N] = sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	fill_n(memo, 12, -1);
	for (int test_case = 0; test_case < T; test_case++)
	{
		int N; cin >> N;
		cout << solve(N) << "\n";
	}
	return 0;
}