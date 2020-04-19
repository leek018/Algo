#include <iostream>
using namespace std;

int N;
int memo[46][46];
int combi(int n, int r)
{
	
	if (n == r || r == 0)
		return memo[n][r] = 1;	
	int val = memo[n][r];
	if (val >= 0)
		return val;
	return memo[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
}
int solve(int one, int N)
{
	int n = N - 2 * one+1;
	int r = one-1;
	if (n == 0)
		return 1;	
	return combi(n+r , r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 45; i++)
		fill_n(memo[i], 45, -1);
	int sum = 0;
	int limit = N / 2;
	if (N % 2 == 1)
		limit++;
	for (int i = 1; i <= limit; i++)
		sum += solve(i, N);
	cout << sum;
	return 0;

}